#include <string.h>

#include "material/FsShaderMaterial.h"
#include "graphics/FsRender.h"
#include "graphics/FsProgram.h"
#include "util/FsDict.h"

NS_FS_BEGIN

static const FsChar* s_ShaderMateral_UniformName="ShaderMaterial::UniformObject";
static const FsChar* s_ShaderMaterialName="ShaderMaterialObject";

const FsChar* ShaderMaterial::Uniform::getName()
{
	return s_ShaderMateral_UniformName;
}
const FsChar* ShaderMaterial::getName()
{
	return s_ShaderMaterialName;
}

ShaderMaterial::Uniform::Uniform(FsString* name,FsInt type,FsInt count)
{
	m_name=name;
	m_name->addRef();
	m_type=type;
	m_count=count;

	m_location=-1;
	m_value=new FsChar[Render::sizeofUniformType(type)*m_count];
	memset(m_value,0,Render::sizeofUniformType(type)*m_count);
}

ShaderMaterial::Uniform::~Uniform()
{
	m_name->decRef();
	delete[] (FsChar*)m_value;
}

void ShaderMaterial::Uniform::setValue(void* value,FsInt type,FsInt count)
{
	if(type!=m_type)
	{
		FS_TRACE_WARN("Error Type For Material Uniform %s",m_name->cstr());
		return;
	}
	if(count>m_count)
	{
		FS_TRACE_WARN("Count Enlarge Than We Need,so Trunk It");
		count=m_count;
	}

	memcpy(m_value,value,Render::sizeofUniformType(m_type)*count);
}


void ShaderMaterial::setProgram(Program* prog)
{
	if(prog)
	{
		prog->addRef();
	}
	if(m_program)
	{
		prog->decRef();
	}
	m_program=prog;
	refreshUniform();
}

void ShaderMaterial::refreshUniform()
{
	FsDict::Iterator iter(m_uniforms);
	while(!iter.done())
	{
		Uniform* u=(Uniform*)iter.getValue();
		if(m_program)
		{
			u->m_location=m_program->getUniformLocation(u->m_name);
		}
		else 
		{
			u->m_location=-1;
		}
		u->decRef();
	}
}

void ShaderMaterial::setUniform(const FsChar* name,FsInt type,FsVoid* value,FsInt count)
{
	Uniform* u=(Uniform*)m_uniforms->lookup(name);
	if(u)
	{
		u->setValue(value,type,count);
		u->decRef();
	}
	else 
	{
		FS_TRACE_WARN("Uniform %s Not Found Int Material",name);
	}
}

void ShaderMaterial::addUniform(ShaderMaterial::Uniform* u)
{
	m_uniforms->insert(u->m_name,u);
	if(m_program)
	{
		u->m_location=m_program->getUniformLocation(u->m_name);
	}
	else 
	{
		u->m_location=-1;
	}
}

ShaderMaterial::ShaderMaterial()
{
	m_wireFrame=false;
	m_wireFrameWidth=1;
	m_program=NULL;
	m_programSourceName=NULL;
	m_uniforms=new FsDict();
}

ShaderMaterial::~ShaderMaterial()
{
	FS_SAFE_DEC_REF(m_program);
	FS_SAFE_DEC_REF(m_programSourceName);
	m_uniforms->decRef();
}

void ShaderMaterial::configRender(Render* r)
{
	Material::configRender(r);
	/*TODO(Set WireFrame Here) */
}

void ShaderMaterial::load(Render* r)
{
	configRender(r);
	r->setProgram(m_program);
	if(m_program)
	{
		FsDict::Iterator iter(m_uniforms);
		while(!iter.done())
		{
			Uniform* u=(Uniform*)iter.getValue();
			if(u->m_location!=-1)
			{
				r->setUniform(u->m_location,u->m_type,u->m_count,u->m_value);
			}
			u->decRef();
		}
	}
}
void ShaderMaterial::unload(Render* r)
{
}


FsDict* ShaderMaterial::getUniforms()
{
	m_uniforms->addRef();
	return m_uniforms;
}
void ShaderMaterial::setProgramSourceName(FsString* name)
{
	FS_SAFE_ADD_REF(name);
	FS_SAFE_DEC_REF(m_programSourceName);
	m_programSourceName=name;
}

FsString* ShaderMaterial::getProgramSourceName()
{
	FS_SAFE_ADD_REF(m_programSourceName);
	return m_programSourceName;
}



NS_FS_END






















