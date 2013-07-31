#ifndef _FS_POSITION_COLOR_MATERIAL_H_
#define _FS_POSITION_COLOR_MATERIAL_H_

#include "FsMacros.h"
#include "graphics/material/FsMaterial.h"

NS_FS_BEGIN
class Mat_V4F_C4F:public Material
{
	public:
		static Mat_V4F_C4F* create();
		static Mat_V4F_C4F* shareMaterial();

	public:
		virtual void onUse(Render* r);

	public:
		void setOpacity(float opacity)
		{
			m_opacity=opacity;
		}

		float getOpacity()
		{
			return m_opacity;
		}
	public:
		int getV4FLocation(){return m_positionLocation;}
		int getC4FLocation(){return m_colorLocation;}

	protected:
		Mat_V4F_C4F();
		~Mat_V4F_C4F();

	private:
		float m_opacity;

		/* uniform and attribute */
		int m_opacityUniform;
		int m_mvpUniform;
		int m_positionLocation;
		int m_colorLocation;
		Program* m_program;
};

NS_FS_END
#endif /*_FS_POSITION_COLOR_MATERIAL_H_*/



