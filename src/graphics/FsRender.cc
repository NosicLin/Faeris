#include "graphics/FsRender.h"
#include "FsConfig.h"


FAERIS_NAMESPACE_BEGIN
static Render* s_singletonRender=NULL;
Render* Render::instance()
{
	if(s_singletonRender==NULL)
	{
		s_singletonRender=new Render;
	}
	return s_singletonRender;
}
FAERIS_NAMESPACE_END

#if FS_CONFIG(FS_GL_RENDER) 
	#include "platform/FsGLRender.cc"
#else 
	#error "unsupport render platform"
#endif /*FS_GL_RENDER*/

