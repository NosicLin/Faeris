#ifndef _FS_MATTERIAL_H_
#define _FS_MATTERIAL_H_
#include "FsMacros.h"
#include "util/FsResource.h"
FAERIS_NAMESPACE_BEGIN
class Render;
class Material:public FsObject
{
	public:
		/* alpha blend*/
		FsInt blendEnable;
		FsInt blendEquation;
		FsInt blendSrc;
		FsInt blendDst;

		/* depth */
		FsBool depthTest;
		FsBool depthMask;

	public:
		Material()
			:blendEnable(true),
			blendEquation(EQUATION_ADD),
			blendSrc(FACTOR_SRC_ALPHA),
			blendDst(FACTOR_ONE_MINUS_SRC_ALPHA),
			depthTest(true),
			depthMask(true)
			{}



	public:
		virtual void load(Render* r);
		virtual void unload(Render* r);
};
FAERIS_NAMESPACE_END 
#endif /*_FS_MATTERIAL_H_*/

