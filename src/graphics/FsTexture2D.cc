#include "graphics/FsTexture2D.h"

NS_FS_BEGIN

#if FS_CONFIG(FS_GL_RENDER)||FS_CONFIG(FS_GLES_RENDER)
	#include "platform/FsGLTexture2D.cc"
#else 
	#error "Unsupport PlatformTexture"
#endif 

NS_FS_END 

