#ifndef _FS_BASE_MATERIAL_H_
#define _FS_BASE_MATERIAL_H_
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

		/* shade mode */
		FsInt m_shadeMode;

		/* front side */
		FsInt m_frontSide;

		/* depth */
		FsBool m_depthTest;
		FsBool m_depthMask;


	public:
		Material()
			:m_blendEquation(Render::EQUATION_ADD),
			m_blendSrc(Render::FACTOR_SRC_ALPHA),
			m_blendDst(Render::FACTOR_ONE_MINUS_SRC_ALPHA),
			m_opacity(1.0f),
			m_shadeMode(Render::SHADE_MODE_SMOOTH),
			m_frontSide(Render::FRONT_CCW),
			m_depthTest(true),
			m_depthMask(true) {}
		virtual ~Material();
		virtual const FsChar* getName();
	public:
		/* blend */
		void setBlend(FsInt equation,FsInt src,FsInt dst)
		{
			m_blendEquation=equation;
			m_blendSrc=src;
			m_blendDst=dst;
		}
		FsInt getBlendEquation()
		{
			return m_blendEquation;
		}
		FsInt getBlendSrc()
		{
			return m_blendSrc;
		}
		FsInt getBlendDst()
		{
			return m_blendDst;
		}

		/* shader mode */
		void setShadeMode(FsInt mode)
		{
			m_shadeMode=mode;
		}
		FsInt getShadeMode()
		{
			return m_shadeMode;
		}

		/* opacity */
		void setOpacity(FsFloat opacity)
		{
			m_opacity=opacity;
		}
		FsFloat getOpacity()
		{
			return m_opacity;
		}

		/* depth test */
		void setDepthTest(FsBool enable)
		{
			m_depthTest=enable;
		}
		FsBool getDepthTest()
		{
			return m_depthTest;
		}

		/* depth mask */
		void setDepthMask(FsBool enable)
		{
			m_depthMask=enable;
		}
		FsBool getDepthMask()
		{
			return m_depthMask;
		}

		void setFrontSide(FsInt type)
		{
			m_frontSide=type;
		}
		FsInt getFrontSide()
		{
			return m_frontSide;
		}
	protected:
		void configRender(Render* r);
	public:
		virtual void load(Render* r)=0;
		virtual void unload(Render* r)=0;
};
NS_FS_END 
#endif /*_FS_MATTERIAL_H_*/

