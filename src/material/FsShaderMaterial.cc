#include "material/FsShaderMaterial.h"
#include "graphics/FsRender.h"
#include "graphics/FsProgram.h"


static const FsChar* s_ShaderMateral_Uniform="ShaderMaterial::UniformObject";
static const FsChar* s_ShaderMaterial="ShaderMaterialObject";

const FsChar* ShaderMaterial::Uniform::getName()
{
	return s_ShaderMater_Uniform;
}
const Fschar* ShaderMaterial::getName()
{
	return s_ShaderMaterial;
}

ShaderMaterial::Uniform::Uniform(FsString* name,FsInt type,FsInt count)
{
	m_name=name;
	m_name->addRef();
	m_type=type;
	m_count=count;

	m_location=-1;
	m_value=new FsChar[Render::uniformTypeSize(type)*m_count];
	memset(m_value,0,Render::UniformObject(type)*m_count);
}

ShaderMaterial::Uniform::~Uniform()
{
	m_name->decRef();
	delete[] (FsChar*)m_value;
}

void ShaderMaterial::Uniform::setValue(void* value)
{
	memcpy(m_value,value,Render::uniformTypeSize(type)*m_count);
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
	FsArray::Iterator iter(m_uniforms);
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

void ShaderMaterial::setUniform(const FsChar* name,FsVoid* value)
{
	FsArray::Iterator iter(m_uniforms);
	while(!iter.done())
	{
		Uniform* u=(Uniform*)iter.getValue();
		if(u->equal(name))
		{
			u->setValue(value);
			u->decRef();
			break;
		}
		u->decRef();
	}
	FS_TRACE_WARN("Uniform %s Not Found Int Material",name);
}

void ShaderMaterial::addUniform(ShaderMaterial::Uniform* u)
{
	m_uniforms->push(u);
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
	m_uniforms=new FsArray();
}

ShaderMaterial::~ShaderMaterial()
{
	if(m_program)
	{
		m_program->decRef();
	}
	m_uniforms->decRef();
}

ShaderMaterial::configRender(Render* r)
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
		FsArray::Iterator iter(m_uniforms);
		while(!iter.done())
		{
			Uniform* u=iter.getValue();
			if(u->location!=-1)
			{
				r->setUniform(u->location,u->type,u->count,u->value);
			}
			u->decRef();
		}
	}
}
void ShaderMaterial::unload(Render* r)
{
}


























