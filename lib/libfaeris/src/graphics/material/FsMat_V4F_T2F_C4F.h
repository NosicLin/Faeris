#ifndef _FS_MAT_V4F_T2F_C4F_H_
#define _FS_MAT_V4F_T2F_C4F_H_

#include "FsMacros.h"
#include "graphics/material/FsMaterial.h"

NS_FS_BEGIN
class Mat_V4F_T2F_C4F:public Material  
{
	public:
		static Mat_V4F_T2F_C4F* create();
		static Mat_V4F_T2F_C4F* shareMaterial();
		static void purgeShareMaterial();

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

		void setColor(Color c);
		Color getColor();

	public:
		int getV4FLocation();
		int getC4FLocation();
		int getT2FLocation();

		int getOpacityUniform(){return m_opacityUniform;}
		int getColorUniform(){return m_colorUniform;}
		int getMvpUniform(){return m_mvpUniform;}
		int getTextureUniform(){return m_textureUniform;}


	protected:
		Mat_V4F_T2F_C4F();
		~Mat_V4F_T2F_C4F();

	private:
		float m_opacity;
		Color m_color;

		/* uniform and attribute */
		int  m_opacityUniform;
		int  m_colorUniform;
		int  m_mvpUniform;
		int  m_textureUniform;

		int  m_v4fLocation;
		int  m_c4fLocation;
		int  m_t2fLocation;

		Program* m_program;
};

NS_FS_END
#endif /* _FS_MAT_V4F_T2F_C4F_H_ */





