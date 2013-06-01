#ifndef _FS_POSITION_ALPHA_TEXTURE_MATERIAL_H_
#define _FS_POSITION_ALPHA_TEXTURE_MATERIAL_H_

#include "FsMacros.h"
#include "material/FsMaterial.h"
#include "graphics/FsColor.h"


NS_FS_BEGIN
class PositionAlphaTextureMaterial:public Material
{
	public:
		static PositionAlphaTextureMaterial* create();
		static PositionAlphaTextureMaterial* shareMaterial();
		static void purgeShareMaterial();
	public:
		void setColor(Color c);
		Color getColor();

		void setOpacity(float opacity);
		float getOpacity();

		int getPositionLocaition();
		int getTexCoordLocation();
		int getAlphaLocation();

	public:
		virtual void onUse(Render* r);
		virtual const char* className();

	protected:
		PositionAlphaTextureMaterial();
		~PositionAlphaTextureMaterial();

	private:
		Color m_color;
		float m_opacity;

		Program* m_program;

		/* uniform */
		int m_opacityUniform;
		int m_colorUniform;
		int m_textureUniform;
		int m_mvpUniform;

		int m_positionAttribute;
		int m_textcoordAttribute;
		int m_alphaAttribute;

		/* attribute */
};

NS_FS_END

#endif /*_FS_POSITION_ALPHA_TEXTURE_MATERIAL_H_*/
