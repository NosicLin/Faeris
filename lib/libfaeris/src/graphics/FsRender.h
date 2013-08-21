#ifndef _FS_RENDER_H_
#define _FS_RENDER_H_

#include "FsMacros.h"
#include "FsConfig.h"

#if FS_CONFIG(FS_GLES_RENDER)
	#include "platform/FsESRender.h"
#elif FS_CONFIG(FS_GL_RENDER)
	#include "platform/FsGLRender.h"
#else 
	#error "UnSupport Render"
#endif 
 
#endif 

