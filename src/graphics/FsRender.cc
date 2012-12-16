#include "graphics/FsRender.h"
#include "FsConfig.h"

#if FS_CONFIG(FS_GL_RENDER) 
	#include "platform/FsGLRender.cc"
#else 
	#error "unsupport render platform"
#endif /*FS_GL_RENDER*/

