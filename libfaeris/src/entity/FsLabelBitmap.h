#ifndef _FS_LABEL_BITMAP_H_
#define _FS_LABEL_BITMAP_H_


#include <string>

#include "FsMacros.h"
#include "entity/FsEntity.h"
#include "graphics/FsColor.h"
#include "math/FsVertices.h"


NS_FS_BEGIN
class FontBitmap;
class PositionTextureMaterial;

class LabelBitmap:public Entity 
{
	public:
		enum{ 
			ALIGN_V_TOP,
			ALIGN_V_CENTER,
			ALIGN_V_BOTTOM,
			ALIGN_V_USER_DEFINE,

			ALIGN_H_LEFT,
			ALIGN_H_RIGHT,
			ALIGN_H_CENTER,
			ALIGN_H_USER_DEFINE,
		};
		enum{
			TEXT_ALIGN_LEFT,
			TEXT_ALIGN_CENTER,
			TEXT_ALIGN_RIGHT,
		};

	public:
		static LabelBitmap* create(const char* text,FontBitmap* font);
		static LabelBitmap* create(FontBitmap* font);

	public:
		int setString(const char* utf8_str);
		int setString(const char* utf8_str,int start);
		int setString(const char* utf8_str,int start,int num);

		const char* getString();

		void setColor(Color c);
		Color getColor();

		void setOpacity(float opacity);
		float getOpacity();

		void setAlign(int alignh,int alignv);
		void setAlignOffset(float x,float y);

		void getAlign(int* alignh,int* alignv);
		void getAlignOffset(float* x,float* y);


		float getWidth();
		float getHeight();

		/* NOTE: setTextAlign and setBounds will not take effect 
		 * immediately,it will change at next setString called 
		 */
		void setTextAlign(int mode);
		void setBounds(float x,float y);

		int getTextAlign();
		void getBounds(float* x,float* y);

	public:
		/* override Entity */
		virtual void draw(Render* r,bool updateMatrix);
		virtual bool hit2D(float x,float y);

		/* override FsObject */
		virtual const char* className();



	protected:
		FontBitmap();
		virtual ~FontBitmap();
		bool init(FontBitmap* font);
		void destroy();

		void setString(uint16_t* utf16_str,int start,int num);

		void calRelOffset();


	private:
		int m_alignh,m_alignv;
		float m_offsetx,m_offsety;
		int m_textAlign;

		float m_boundx,m_boundy;

		float m_opacity;
		Color m_color;

		uint8_t* m_utf8str;


		FontBitmap* m_font;
		Texture2D* m_texture;

		Mat_V4F_T2F* m_material;


		/* auto generate */
		float m_width,m_height;
		float m_relOffsetx,m_relOffsety;

		Fs_V2F_T2F* m_vertices;
		int m_vertexNu;

};


NS_FS_END 


#endif /*_FS_LABEL_BITMAP_H_*/




























