#include "graphics/FsProgram.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN

void Program::addUniform(const char* name)
{
	if(m_uniforms==NULL)
	{
		m_uniforms=new FsDict();
	}

	FsString* fs_name=new FsString(name);
	Location* l=new Location(fs_name);

	m_uniforms->insert(fs_name,l);

	fs_name->decRef();
	l->decRef();
}

void Program::addAttribute(const char* name)
{

	if(m_attrs==NULL)
	{
		m_attrs=new FsDict();
	}

	FsString* fs_name=new FsString(name);
	Location* l=new Location(fs_name);
	m_attrs->insert(fs_name,l);

	fs_name->decRef();
	l->decRef();
}


Program::Location::~Location()
{
	name->decRef();
}

const char* s_LocationName="Program::Location";
const char* Program::Location::className()
{
	return s_LocationName;
}


NS_FS_END



#if FS_CONFIG(FS_GL_RENDER)
	#include "platform/FsGLProgram.cc"
#else 
	#error "Unsupport PlatformProgram"
#endif 
