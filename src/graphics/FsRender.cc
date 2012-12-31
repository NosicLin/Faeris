#include "graphics/FsRender.h"
#include "FsConfig.h"


NS_FS_BEGIN
static Render* s_share_render=NULL;
Render* Render::shareRender()
{
	if(s_share_render==NULL)
	{
		s_share_render=new Render;
	}
	return s_share_render;
}

void Render::purgeShareRender()
{
	if(s_share_render)
	{
		delete s_share_render;
		s_share_render=NULL;
	}
}
NS_FS_END

#if FS_CONFIG(FS_GL_RENDER) 
	#include "platform/FsGLRender.cc"
#else 
	#error "unsupport render platform"
#endif /*FS_GL_RENDER*/

