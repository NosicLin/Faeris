#ifndef _FS_QUAD_2D_MATERIAL_H_
#define _FS_QUAD_2D_MATERIAL_H_
#include "FsMacros.h"
#include "material/FsMaterial.h"

NS_FS_BEGIN
class Quad2DMaterial: public Material
{
	public:
		static Quad2DMaterial* create();

	public:
		void setColor(Color c);
		Color getColor();
		void setOpacity(float opacity);
		float getOpacity();

		int getPostionLocaition();
		int getTexCoordLocation();

	public:
		virtual void load(Render* r);
		virtual void unload(Render* );
		virtual const char* className();
	protected:
		Quad2DMaterial();
		~Quad2DMaterial();



	private:
		Color m_color;
		float m_opacity;

		Program* m_program;
		/* uniform */
		int m_opacityUniform;
		int m_colorUniform;
		int m_textureUniform;

		/* attribute */
		int m_positionAttribute;
		int m_textcoordAttribute;
};

NS_FS_END

#endif /*_FS_QUAD_2D_MATERIAL_H_*/

