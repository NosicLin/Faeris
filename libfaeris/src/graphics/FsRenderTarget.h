#ifndef _FAERIS_RENDER_TARGET_H_
#define _FAERIS_RENDER_TARGET_H_
#include "FsMacros.h"
#include "core/FsObject.h"

NS_FS_BEGIN
class Render;
class RenderTarget:public FsObject
{
	public:
		virtual void swapBuffers()=0;
		virtual void makeCurrent(Render*)=0;
		virtual void loseCurrent(Render*)=0;
};
NS_FS_END
#endif /*_FAERIS_RENDER_TARGET_H_*/

