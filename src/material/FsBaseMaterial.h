#ifndef _FS_BASE_MATTERIAL_H_
#define _FS_BASE_MATTERIAL_H_
#include "FsMacros.h"
#include "util/FsResource.h"
#include "graphics/FsRender.h"
NS_FS_BEGIN
class Render;
class BaseMaterial:public FsObject
{
	public:
		/* alpha blend*/
		FsInt blendEquation;
		FsInt blendSrc;
		FsInt blendDst;

		FsFloat opacity;

		/* depth */
		FsBool depthTest;
		FsBool depthMask;

	public:
		BaseMaterial()
			:blendEquation(Render::EQUATION_ADD),
			blendSrc(Render::FACTOR_SRC_ALPHA),
			blendDst(Render::FACTOR_ONE_MINUS_SRC_ALPHA),
			opacity(1.0f),
			depthTest(true),
			depthMask(true) {}

	public:
		virtual void load(Render* r);
		virtual void unload(Render* r);
};
NS_FS_END 
#endif /*_FS_MATTERIAL_H_*/

