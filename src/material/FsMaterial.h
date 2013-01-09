#ifndef _FS_BASE_MATTERIAL_H_
#define _FS_BASE_MATTERIAL_H_
#include "FsMacros.h"
#include "util/FsResource.h"
#include "core/FsObject.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
class Material:public FsObject
{
	protected:
		/* alpha blend*/
		FsInt m_blendEquation;
		FsInt m_blendSrc;
		FsInt m_blendDst;

		FsFloat m_opacity;

		FsInt m_shadeMode;

		/* depth */
		FsBool m_depthTest;
		FsBool m_depthMask;


	public:
		Material()
			:m_blendEquation(Render::EQUATION_ADD),
			m_blendSrc(Render::FACTOR_SRC_ALPHA),
			m_blendDst(Render::FACTOR_ONE_MINUS_SRC_ALPHA),
			m_opacity(1.0f),
			m_shadeMode(Render::SHADER_MODE_SMOOTH),
			m_depthTest(true),
			m_depthMask(true) {}
		virtual ~Material();
		virtual const FsChar* getName();
	public:
		void setBlend(FsInt equation,FsInt src,FsInt dst)
		{
			m_blendEquation=equation;
			m_blendSrc=src;
			m_blendDst=dst;
		}
		void setShadeMode(FsInt mode)
		{
			m_shadeMode=mode;
		}
		void setOpacity(FsFloat opacity)
		{
			m_opacity=opacity;
		}
		void setDepthTest(FsBool enable)
		{
			m_depthTest=enable;
		}
		void setDepthMask(FsBool enable)
		{
			m_depthMask=enable;
		}
	protected:
		void configRender(Render* r);
	public:
		virtual void load(Render* r)=0;
		virtual void unload(Render* r)=0;
};
NS_FS_END 
#endif /*_FS_MATTERIAL_H_*/

