#ifndef _FS_MATTERIAL_H_
#define _FS_MATTERIAL_H_
#include "FsMacros.h"
#include "core/FsObject.h"
FAERIS_NAMESPACE_BEGIN
class Render;
class Material:public FsObject
{
	public:
		virtual void load(Render* r);
		virtual void unload(Render* r);
};
FAERIS_NAMESPACE_END 
#endif /*_FS_MATTERIAL_H_*/

