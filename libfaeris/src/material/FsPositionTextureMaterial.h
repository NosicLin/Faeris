#ifndef _FS_POSITION_TEXTURE_MATERIAL_H_
#define _FS_POSITION_TEXTURE_MATERIAL_H_
#include "FsMacros.h"
#include "material/FsMaterial.h"

NS_FS_BEGIN
class Program;
class PositionTextureMaterial: public Material
{
	public:
		static PositionTextureMaterial* create();
		static PositionTextureMaterial* shareMaterial();
		static void purgeShareMaterial();

	public:
		void setColor(Color c);
		Color getColor();
		void setOpacity(float opacity);
		float getOpacity();

		int getPostionLocaition();
		int getTexCoordLocation();

	public:
		virtual void onUse(Render* r);
		virtual const char* className();
	protected:
		PositionTextureMaterial();
		~PositionTextureMaterial();



	private:
		Color m_color;
		float m_opacity;

		Program* m_program;
		/* uniform */
		int m_opacityUniform;
		int m_colorUniform;
		int m_textureUniform;
		int m_mvpUniform;

		/* attribute */
		int m_positionAttribute;
		int m_textcoordAttribute;
};

NS_FS_END

#endif /*_FS_POSITION_TEXTURE_MATERIAL_H_*/

