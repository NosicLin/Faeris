#ifndef _FS_COLOR_QUAD2D_MATERIAL_H_
#define _FS_COLOR_QUAD2D_MATERIAL_H_

#include "FsMacros.h"
#include "material/FsMaterial.h"

NS_FS_BEGIN
class ColorQuad2DMaterial:public Material
{
	public:
		static ColorQuad2DMaterial* create();

	public:
		virtual void load(Render* r);
		virtual void unload(Render* r);

	public:
		void setOpacity(float opacity)
		{
			m_opacity=opacity;
		}

		float getOpacity()
		{
			return m_opacity;
		}

	protected:
		ColorQuad2DMaterial();
		~ColorQuad2DMaterial();

	private:
		float m_opacity;
		int m_opacityLocation;
		Program* m_progam;
};

NS_FS_END
#endif /*_FS_COLOR_QUAD_MATERIAL_H_*/



