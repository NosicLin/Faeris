#include <string.h>

#include "fsys/FsVFS.h"
#include "loader/FsMaterialLoader.h"
#include "loader/FsLoaderUtil.h"
#include "loader/FsProgramLoader.h"
#include "util/FsScriptUtil.h"
#include "material/FsShaderMaterial.h"


NS_FS_BEGIN

Material* MaterialLoader::loadFromMgr(const FsChar* name)
{
	/*TODO(add real mgr here)*/
	return create(name);
}

Material* MaterialLoader::create(const FsChar* name)
{
	FsFile* file=VFS::open(name);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Open File(%s) For Material",name);
		return NULL;
	}
	Material* mat=create(file);
	file->decRef();
	return mat;
}
Material* MaterialLoader::create(FsFile* file)
{
	if(LoaderUtil::fileType(file)==FS_FTYPE_SCRIPT)
	{
		return createFromScript(file);
	}
	else 
	{
		return createFromBinary(file);
	}
}
Material* MaterialLoader::createFromBinary(FsFile* file)
{
	/*TODO */
	FS_ASSERT(0);
	return NULL;
}
Material* MaterialLoader::createFromScript(FsFile* file)
{
	Material* mat=NULL;
	FsDict* dict=ScriptUtil::parseScript(file);
	if(dict==NULL)
	{
		FS_TRACE_WARN("Error Script For Material");
		return NULL;
	}
	FsString* type=ScriptUtil::getString(dict,"type");
	if(type->equal("material.shader"))
	{
		mat=new ShaderMaterial();
		setShaderMaterial((ShaderMaterial*)mat,dict);
	}
	else 
	{
		FS_TRACE_WARN("Error Type(%s) For Material",type->cstr());
	}
	dict->decRef();
	type->decRef();
	return mat;
}

FsInt s_GetFromSide(FsDict* dict,const FsChar* key)
{
	FsString* value=ScriptUtil::getString(dict,key);
	FsInt ret=-1;
	if(value!=NULL)
	{
		ret=LoaderUtil::parseFrontSide(value->cstr());
		value->decRef();
	}
	return ret;
}
FsInt s_GetBlendEquation(FsDict* dict,const FsChar* key)
{
	FsString* value=ScriptUtil::getString(dict,key);
	FsInt ret=-1;
	if(value!=NULL)
	{
		ret=LoaderUtil::parseBlendEquation(value->cstr());
		value->decRef();
	}
	return ret;
}

FsInt s_GetBlendFactor(FsDict* dict,const FsChar* key)
{
	FsString* value=ScriptUtil::getString(dict,key);
	FsInt ret=-1;
	if(value!=NULL)
	{
		ret=LoaderUtil::parseBlendFactor(value->cstr());
		value->decRef();
	}
	return ret;
}
FsInt s_GetShadeMode(FsDict* dict,const FsChar*  key)
{
	FsInt ret=-1;
	FsString* value=ScriptUtil::getString(dict,key);
	if(value!=NULL)
	{
		ret=LoaderUtil::parseShadeMode(value->cstr());
		value->decRef();
	}
	return ret;
}
FsInt s_GetFrontSide(FsDict* dict,const FsChar* key)
{
	FsInt ret=-1;
	FsString* value=ScriptUtil::getString(dict,key);
	if(value!=NULL)
	{
		ret=LoaderUtil::parseFrontSide(value->cstr());
		value->decRef();
	}
	return ret;
}



void MaterialLoader::setMaterial(Material* mat,FsDict* dict)
{

	FsInt blend_equation=s_GetBlendEquation(dict,"blendEquation");
	if(blend_equation==-1) { blend_equation=Render::EQUATION_ADD; }

	FsInt src_factor=s_GetBlendFactor(dict,"srcFactor");
	if(src_factor==-1) { src_factor=Render::FACTOR_SRC_ALPHA; }

	FsInt dst_factor=s_GetBlendFactor(dict,"dstFactor");
	if(dst_factor==-1) { dst_factor=Render::FACTOR_ONE_MINUS_SRC_ALPHA;}

	FsInt shade_mode=s_GetShadeMode(dict,"shadeMode");
	if(shade_mode==-1) { shade_mode=Render::SHADE_MODE_SMOOTH;}

	FsInt front_side=s_GetFrontSide(dict,"frontSide");
	if(front_side==-1) { front_side=Render::FRONT_CCW;}

	FsFloat opacity=1.0;
	FsBool depth_mask=true;
	FsBool depth_test=true;
	ScriptUtil::getFloat(dict,"opacity",&opacity);
	ScriptUtil::getBoolean(dict,"depthMask",&depth_mask);
	ScriptUtil::getBoolean(dict,"depthTest",&depth_test);

	mat->setBlend(blend_equation,src_factor,dst_factor);
	mat->setShadeMode(shade_mode);
	mat->setOpacity(opacity);
	mat->setDepthTest(depth_test);
	mat->setDepthMask(depth_mask);
	mat->setFrontSide(front_side);
}

static ShaderMaterial::Uniform* s_ToUniform(FsDict* dict)
{
	FsString* name=ScriptUtil::getString(dict,"name");
	if(!name)
	{
		FS_TRACE_WARN("Can't GetName For Material Uniforms");
		return NULL;
	}
	FsString* type=ScriptUtil::getString(dict,"type");
	if(!type)
	{
		FS_TRACE_WARN("Can't Get Type For Material Uniforms");
		name->decRef();
		return NULL;
	}

	FsInt count=0;
	if(!ScriptUtil::getInteger(dict,"count",&count))
	{
		FS_TRACE_WARN("Can't Get Count For Material Uniforms");
		type->decRef();
		name->decRef();
		return NULL;
	}
	FsInt real_type=LoaderUtil::parseUniformType(type->cstr());
	if(real_type==-1)
	{
		FS_TRACE_WARN("Unkown Uniform Type(%s)",type->cstr());
		name->decRef();
		type->decRef();
		return NULL;
	}

	ShaderMaterial::Uniform* u=new ShaderMaterial::Uniform(name,real_type,count);
	name->decRef();
	type->decRef();

	FsInt compoents=Render::uniformTypeComponent(real_type);
	switch(real_type)
	{
		case Render::U_F_1:
		case Render::U_F_2:
		case Render::U_F_3:
		case Render::U_F_4:
		case Render::U_M_2:
		case Render::U_M_3:
		case Render::U_M_4:
		{
			FsArray* sct_value=ScriptUtil::getArray(dict,"value");
			if(sct_value==NULL)
			{
				break;
			}
			FsInt total_value=compoents*count;
			FsFloat* v=new FsFloat[total_value];
			memset(v,0,total_value*sizeof(FsFloat));
			FsInt value_nu=sct_value->size();
			if(value_nu>compoents*count)
			{
				value_nu=compoents*count;
			}
			for(FsInt i=0;i<value_nu;i++)
			{
				FsFloat cur_value=0;
				ScriptUtil::getFloat(sct_value,i,&cur_value);
				v[i]=cur_value;
			}
			u->setValue(v,real_type,count);
			delete[] v;
			sct_value->decRef();
			break;
		}
		case Render::U_I_1:
		case Render::U_I_2:
		case Render::U_I_3:
		case Render::U_I_4:
		{
			FsArray* sct_value=ScriptUtil::getArray(dict,"value");
			if(sct_value==NULL)
			{
				break;
			}
			FsInt total_value=compoents*count;
			FsInt* v=new FsInt[total_value];
			memset(v,0,total_value*sizeof(FsInt));
			FsInt value_nu=sct_value->size();
			if(value_nu>compoents*count)
			{
				value_nu=compoents*count;
			}
			for(FsInt i=0;i<value_nu;i++)
			{
				FsInt cur_value=0;
				ScriptUtil::getInteger(sct_value,i,&cur_value);
				v[i]=cur_value;
			}
			u->setValue(v,real_type,count);
			sct_value->decRef();
			delete[] v;
			break;
		}

		case Render::U_UI_1:
		case Render::U_UI_2:
		case Render::U_UI_3:
		case Render::U_UI_4:
		{
			FsArray* sct_value=ScriptUtil::getArray(dict,"value");
			if(sct_value==NULL)
			{
				break;
			}
			FsInt total_value=compoents*count;
			FsUint* v=new FsUint[total_value];
			memset(v,0,total_value*sizeof(FsUint));
			FsInt value_nu=sct_value->size();
			if(value_nu>compoents*count)
			{
				value_nu=compoents*count;
			}
			for(FsInt i=0;i<value_nu;i++)
			{
				FsInt cur_value=0;
				ScriptUtil::getInteger(sct_value,i,&cur_value);
				v[i]=cur_value;
			}
			u->setValue(v,real_type,count);
			sct_value->decRef();
			delete[] v;
			break;

		}
		case Render::U_S_1D:
		case Render::U_S_2D:
		case Render::U_S_3D:
		case Render::U_S_CUBE:
		case Render::U_S_1D_SHADOW:
		case Render::U_S_2D_SHADOW:
			FS_TRACE_WARN("Texture Shouldn't Declare Here");
			break;

	}
	return u;
}
void MaterialLoader::setShaderMaterial(ShaderMaterial* mat,FsDict* dict)
{
	setMaterial(mat,dict);
	FsBool wire_frame=false;
	FsFloat wire_frame_width=1.0f;
	ScriptUtil::getBoolean(dict,"wireFrame",&wire_frame);
	ScriptUtil::getFloat(dict,"wireFrameWidth",&wire_frame_width);
	mat->enableWireFrame(wire_frame);
	mat->setWireFrameWidth(wire_frame_width);

	FsString* prog_name=ScriptUtil::getString(dict,"shader");
	if(prog_name!=NULL)
	{
		mat->setProgramSourceName(prog_name);
		/*TODO(Add reletive current file path support)*/ 
		/* cur_path=resource->getPath();*/
		/* prog=ProgramLoader::loadFromMgr("cur_path+prog_name") */

		Program* prog=ProgramLoader::loadFromMgr(prog_name->cstr());
		if(prog!=NULL)
		{
			mat->setProgram(prog);
			prog->decRef();
		}
		prog_name->decRef();
	}


	FsArray* uniforms=ScriptUtil::getArray(dict,"uniforms");
	if(uniforms==NULL)
	{
		return;
	}

	FsInt uniform_nu=uniforms->size();
	for(FsInt i=0;i<uniform_nu;i++)
	{
		FsDict* cur_udict=ScriptUtil::getDict(uniforms,i);
		if(cur_udict==NULL)
		{
			continue;
		}
		ShaderMaterial::Uniform* u=s_ToUniform(cur_udict);
		if(u!=NULL)
		{
			mat->addUniform(u);
			u->decRef();
		}
		cur_udict->decRef();
	}
	uniforms->decRef();
}





void MaterialLoader::saveShaderMaterialWithScript(ShaderMaterial* mat,FsFile* file)
{
	file->writeStr("type:\"material.shader\"\n");
	file->writeStr("version:\"v.10\"\n");

	/* blendEquation */
	file->writeStr("blendEquation:%s\n",LoaderUtil::blendEquationToStr(mat->getBlendEquation()));
	file->writeStr("srcFactor:%s\n",LoaderUtil::blendFactorToStr(mat->getBlendSrc()));
	file->writeStr("dstFactor:%s\n",LoaderUtil::blendFactorToStr(mat->getBlendDst()));
	file->writeStr("frontSide:%s\n",LoaderUtil::frontSideToStr(mat->getFrontSide()));
	file->writeStr("shadeMode:%s\n",LoaderUtil::shadeModeToStr(mat->getShadeMode()));
	if(mat->getDepthMask())
	{
		file->writeStr("depthMask:true\n");
	}
	else 
	{
		file->writeStr("depthMask:false\n");
	}

	if(mat->getDepthTest())
	{
		file->writeStr("depthTest:true\n");
	}
	else 
	{
		file->writeStr("depthTest:false\n");
	}
	file->writeStr("opacity:%.10g\n",mat->getOpacity());

	FsString* shader_name=mat->getProgramSourceName();
	if(shader_name) 
	{
		file->writeStr("shader:%s\n",shader_name->cstr());
		shader_name->decRef();
	}

	FsDict* uniforms=mat->getUniforms();
	if(uniforms)
	{
		file->writeStr("uniforms:[\n");
		FsDict::Iterator iter(uniforms);
		while(!iter.done())
		{
			file->writeStr("\t{\n");
			ShaderMaterial::Uniform* u=(ShaderMaterial::Uniform*)iter.getValue();
			file->writeStr("\t\tname:%s\n",u->m_name->cstr());
			file->writeStr("\t\ttype:%s\n",LoaderUtil::uniformTypeToStr(u->m_type));
			file->writeStr("\t\tcount:%d\n",u->m_count);
			file->writeStr("\t\tvalue:[");

			FsInt compoents=Render::uniformTypeComponent(u->m_type);
			switch(u->m_type)
			{
				case Render::U_F_1:
				case Render::U_F_2:
				case Render::U_F_3:
				case Render::U_F_4:
				case Render::U_M_2:
				case Render::U_M_3:
				case Render::U_M_4:
				{
					FsFloat* value=(FsFloat*) u->m_value;
					for(FsInt i=0;i<compoents*u->m_count;i++)
					{
						file->writeStr("%.10g,",value[i]);
					}
					break;
				}
				case Render::U_UI_1:
				case Render::U_UI_2:
				case Render::U_UI_3:
				case Render::U_UI_4:
				{
					FsUint* value=(FsUint*) u->m_value;
					for(FsInt i=0;i<compoents*u->m_count;i++)
					{
						file->writeStr("%u,",value[i]);
					}
					break;
				}
				case Render::U_I_1:
				case Render::U_I_2:
				case Render::U_I_3:
				case Render::U_I_4:
				{
					FsInt* value=(FsInt*) u->m_value;
					for(FsInt i=0;i<compoents*u->m_count;i++)
					{
						file->writeStr("%d,",value[i]);
					}
					break;
				}
			}

			file->writeStr("]\n");
			file->writeStr("\t},\n");

			u->decRef();
			iter.next();
		}
		file->writeStr("]\n");
	}
	uniforms->decRef();
}







NS_FS_END




















