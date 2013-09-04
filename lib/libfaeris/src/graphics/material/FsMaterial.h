#ifndef _FS_BASE_MATERIAL_H_
#define _FS_BASE_MATERIAL_H_
#include "FsMacros.h"
#include "mgr/FsResource.h"
#include "FsObject.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
class Program;
class Material:public FsObject
{
	protected:
		/* alpha blend*/
		int m_blendEquation;
		int m_blendSrc;
		int m_blendDst;
		bool m_depthTest;
	public:
		Material()
			:m_blendEquation(Render::EQUATION_ADD),
			m_blendSrc(Render::FACTOR_SRC_ALPHA),
			m_blendDst(Render::FACTOR_ONE_MINUS_SRC_ALPHA),
			m_depthTest(false) {}

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


		/* depth test */
		void setDepthTest(bool enable)
		{
			m_depthTest=enable;
		}
		bool getDepthTest()
		{
			return m_depthTest;
		}
	public:
		virtual void onUse(Render* r);
};
NS_FS_END 
#endif /*_FS_MATTERIAL_H_*/

