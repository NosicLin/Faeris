#ifndef _FS_POSITION_COLOR_MATERIAL_H_
#define _FS_POSITION_COLOR_MATERIAL_H_

#include "FsMacros.h"
#include "material/FsMaterial.h"

NS_FS_BEGIN
class PositionColorMaterial:public Material
{
	public:
		static PositionColorMaterial* create();
		static PositionColorMaterial* shareMaterial();

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
		int getPostionLocation(){return m_positionLocation;}
		int getColorLocation(){return m_colorLocation;}

	protected:
		PositionColorMaterial();
		~PositionColorMaterial();

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



