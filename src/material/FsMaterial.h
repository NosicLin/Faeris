#ifndef _FS_BASE_MATERIAL_H_
#define _FS_BASE_MATERIAL_H_
#include "FsMacros.h"
#include "io/FsResource.h"
#include "core/FsObject.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
class Material:public FsObject
{
	protected:
		/* alpha blend*/
		int m_blendEquation;
		int m_blendSrc;
		int m_blendDst;

		float m_opacity;

		/* shade mode */
		int m_shadeMode;

		/* front side */
		int m_frontSide;

		/* depth */
		bool m_depthTest;
		bool m_depthMask;


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
		virtual const char* className();
	public:
		/* blend */
		void setBlend(int equation,int src,int dst)
		{
			m_blendEquation=equation;
			m_blendSrc=src;
			m_blendDst=dst;
		}
		int getBlendEquation()
		{
			return m_blendEquation;
		}
		int getBlendSrc()
		{
			return m_blendSrc;
		}
		int getBlendDst()
		{
			return m_blendDst;
		}

		/* shader mode */
		void setShadeMode(int mode)
		{
			m_shadeMode=mode;
		}
		int getShadeMode()
		{
			return m_shadeMode;
		}

		/* opacity */
		void setOpacity(float opacity)
		{
			m_opacity=opacity;
		}
		float getOpacity()
		{
			return m_opacity;
		}

		/* depth test */
		void setDepthTest(bool enable)
		{
			m_depthTest=enable;
		}
		bool getDepthTest()
		{
			return m_depthTest;
		}

		/* depth mask */
		void setDepthMask(bool enable)
		{
			m_depthMask=enable;
		}
		bool getDepthMask()
		{
			return m_depthMask;
		}

		void setFrontSide(int type)
		{
			m_frontSide=type;
		}
		int getFrontSide()
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

