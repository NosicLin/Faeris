#include "fsys/FsVFS.h"
#include "loader/FsMaterialLoader.h"
NS_FS_BEGIN

Material* MaterialLoader::create(FsChar* name)
{
	FsFile* file=VFS::open(name);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't Open File(%s) For Material");
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
		return createFromScript(FsFile* file);
	}
	else 
	{
		return createFromBinary(FsFile* file);
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
	FsInt ret=Render::FRONT_CCW;
	if(value!=NULL)
	{
		if(value->equal("ccw"))
		{
			ret=Render::FRONT_CCW;
		}
		else if(value->equal("cw"))
		{
			ret=Render::FRONT_CW;
		}
		value->decRef();
	}
	return ret;
}
FsInt s_GetBlendEquation(FsDict* dict,const FsChar* key)
{
	FsString* value=ScriptUtil::getString(dict,key);
	FsInt ret=Render::EQUATION_ADD;
	if(value!=NULL)
	{
		if(value->equal("none"))
		{
			ret=Render::EQUATION_NONE;
		}
		else if(value->equal("add"))
		{
			ret=Render::EQUATION_ADD;
		}
		else if(value->equal("subtract"))
		{
			ret=Render::EQUATION_SUBTRACT;
		}
		else if(value->equal("reverse_subtract"))
		{
			ret=Render::EQUATION_REVERSE_SUBTRACT;
		}
		else if(value->equal("min"))
		{
			ret=Render::EQUATION_MIN;
		}
		else if(value->equal("max"))
		{
			ret=Render::EQUATION_MAX;
		}
		else if(value->equal("logic_op"))
		{
			ret=Render::EQUATION_LOGIC_OP;
		}
		value->decRef();
	}
	return ret;
}

FsInt s_GetBlendFactor(FsDict* dict,const FsChar* key)
{
	FsString* value=ScriptUtil::getString(dict,key);
	FsInt ret=Render::FACTOR_SRC_ALPHA;
	if(value!=NULL)
	{
		if(value->equal("src_alpha"))
		{
			ret=Render::FACTOR_SRC_ALPHA;
		}
		else if(value->equal("one_minus_src_alpha"))
		{
			ret=Render::FACTOR_ONE_MINUS_SRC_ALPHA;
		}
		else if(value->equal("zero"))
		{
			ret=Render::FACTOR_ZERO;
		}
		else if(value->equal("one"))
		{
			ret=Render::FACTOR_ONE;
		}
		else if(value->equal("src_color"))
		{
			ret=Render::FACTOR_SRC_COLOR;
		}
		else if(value->equal("one_minus_src_color"))
		{
			ret=Render::FACTOR_ONE_MINUS_SRC_COLOR;
		}
		else if(value->equal("dst_color"))
		{
			ret=Render::FACTOR_DST_COLOR;
		}
		else if(value->equal("one_minus_dst_color"))
		{
			ret=Render::FACTOR_ONE_MINUS_DST_COLOR;
		}
		else if(value->equal("dst_alpha"))
		{
			ret=Render::FACTOR_DST_ALPHA;
		}
		else if(value->equal("one_minus_dst_alpha"))
		{
			ret=Render::FACTOR_ONE_MINUS_DST_ALPHA;
		}
		else if(value->equal("src_alpha_saturate"))
		{
			ret=Render::FACTOR_SRC_ALPHA_SATURATE;
		}
		value->decRef();
	}
	return ret;
}
FsInt s_GetShadeMode(FsDict* dict,const FsChar*  key)
{
	FsInt ret=Render::SHADER_MODE_SMOOTH;
	FsString* value=ScriptUtil::getString(dict,key);
	if(value!=NULL)
	{
		if(value->equal("smooth"))
		{
			ret=Render::SHADER_MODE_SMOOTH;
		}
		else if(value->equal("flat"))
		{
			ret=Render::SHADER_MODE_FLAT;
		}
		value->decRef();
	}
	return ret;
}



void MaterialLoader::setMaterial(Material* mat,FsDict* dict)
{

//	FsInt front_side=s_GetFromSide(dict,"frontSide");
	FsInt blend_equation=s_GetBlendEquation(dict,"blendEquation");
	FsInt src_factor=s_GetBlendFactor(dict,"srcFactor");
	FsInt dst_factor=s_GetBlendFactor(dict,"dstFactor");
	FsInt shade_mode=s_GetShadeMode(dict,"shadeMode");
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
		/*TODO(Add reletive current file path support)*/ 
		/* cur_path=resource->getPath();*/
		/* prog=ProgramLoader::loadFromMgr("cur_path+prog_name") */

		Program* prog=ProgramLoader::loadFromMgr(prog_name);
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
	for(FsInt i=0;uniform_nu;i++)
	{
		FsDict* cur_udict=ScriptUtil(uniforms,i);
		if(cur_udict==NULL)
		{
			continue;
		}
		ShaderMaterial::Uniform* u=s_ToUniform(cur_udict);
		mat->addUniform(u);
		u->decRef();
		cur_udict->decRef();
	}
	uniforms->decRef();
}

NS_FS_END




















