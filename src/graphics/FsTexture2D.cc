#include "graphics/FsTexture2D.h"

FAERIS_NAMESPACE_BEGIN

#if FS_CONFIG(FS_GL_RENDER)
	#include "platform/FsGLTexture2D.cc"
#else 
	#error "Unsupport PlatformTexture"
#endif 

FAERIS_NAMESPACE_END 

