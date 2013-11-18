#ifndef _FS_MAT_V4F_H_
#define _FS_MAT_V4F_H_ 

#include "FsMacros.h"
#include "graphics/material/FsMaterial.h"

NS_FS_BEGIN

class Program;
class Mat_V4F:public Material 
{
	public:
		static Mat_V4F* create();
		static Mat_V4F* shareMaterial();
		static void purgeShareMaterial();

	public:

		void setColor(Color c){m_color=c;}
		Color getColor(){return m_color;}

		void setOpacity(float opacity){m_opacity=opacity;}
		float getOpacity(){return m_opacity;}

		void setPointSize(float size){m_pointSize=size;}
		float getPointSize(){return m_pointSize;}

		int getOpacityUniform(){return m_opacityUniform;}
		int getColorUniform(){return m_colorUniform;}
		int getMvpUniform(){return m_mvpUniform;}

		int getV4FLocation(){return m_positionAttribute;}

	public:
		virtual void onUse(Render* r);
		const char* className();

	protected:
		Mat_V4F();
		~Mat_V4F();

	private:
		Color m_color;
		float m_opacity;
		float m_pointSize;

		Program* m_program;

		/* uniform */
		int m_opacityUniform;
		int m_colorUniform;
		int m_mvpUniform;
		int m_pointSizeUniform;


		/* attribute */
		int  m_positionAttribute;

};


NS_FS_END

#endif /*_FS_MAT_V4F_H_*/







