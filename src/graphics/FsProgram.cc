#include "graphics/FsProgram.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN

void Program::addUniform(const FsChar* name,FsInt type,FsInt count)
{
	if(type>=Render::U_MAX_NU||type<0)
	{
		FS_TRACE_WARN("Unkown Uniform Type");
		return;
	}
	if(m_uniforms==NULL)
	{
		m_uniforms=new FsDict();
	}

	FsString* fs_name=new FsString(name);
	Uniform* uniform=(Uniform*) m_uniforms->lookup(fs_name);
	if(uniform!=NULL)
	{
		fs_name->decRef();
		uniform->decRef();
		FS_TRACE_WARN("Uniform %s Is Already Add",name);
		return;
	}
	uniform=new Uniform(fs_name,type,count);
	m_uniforms->insert(fs_name,uniform);

	fs_name->decRef();
	uniform->decRef();
}

void Program::addAttribute(const FsChar* name,FsInt type)
{
	if(type<0||type>=FS_MAX_TYPE_NU)
	{
		FS_TRACE_WARN("Unkown Attribute Type");
		return;
	}

	if(m_attrs==NULL)
	{
		m_attrs=new FsDict();
	}

	FsString* fs_name=new FsString(name);
	Attribute* attr=(Attribute*) m_attrs->lookup(fs_name);
	if(attr!=NULL)
	{
		fs_name->decRef();
		attr->decRef();
		FS_TRACE_WARN("Attribute %s Is Already Add",name);
		return ;
	}
	attr=new Attribute(fs_name,type);

	m_attrs->insert(fs_name,attr);
	fs_name->decRef();
	attr->decRef();
}

Program::Uniform::~Uniform()
{
	name->decRef();
}
const FsChar* s_UniformName="Program::UniformObject";
const FsChar* Program::Uniform::getName()
{
	return s_UniformName;
}


Program::Attribute::~Attribute()
{
	name->decRef();
}
const FsChar* s_AttributeName="Program::AttributeObject";
const FsChar* Program::Attribute::getName()
{
	return s_AttributeName;
}


NS_FS_END



#if FS_CONFIG(FS_GL_RENDER)
	#include "platform/FsGLProgram.cc"
#else 
	#error "Unsupport PlatformProgram"
#endif 
