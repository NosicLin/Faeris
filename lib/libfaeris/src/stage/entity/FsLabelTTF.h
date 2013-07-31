#ifndef _FS_LABLE_TTF_H_
#define _FS_LABLE_TTF_H_

#include <string>

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN
class Image2D;
class Texture2D;
class Mat_V4F_T2F;
class FontTTF;
class LineTypography
{
	public:
		Image2D* typo(const char* text,FontTTF* font);
};

class LabelTTF:public Entity
{
	public:
		enum 
		{
			ALIGN_V_CENTER,
			ALIGN_V_TOP,
			ALIGN_V_BOTTOM,

			ALIGN_H_LEFT,
			ALIGN_H_RIGHT,
			ALIGN_H_CENTER,

		};
	public:
		static LabelTTF* create(const char* text,FontTTF* font);

	public:
		void setString(const char* string);
		const char* getString();

		void setFont(FontTTF* font);
		FontTTF* getFont();

		void setAlign(int h,int v);
		void getAlign(int* h,int* v);

		void setColor(Color c);
		Color getColor();

		void setOpacity(float opacity);
		float getOpacity();

		Rect2D getRect2D();

	public:
		/* inherit Entity */
		virtual void draw(Render* render,bool updateMatrix);
		virtual bool hit2D(float x,float y);

		/* inherit FsObject */
		virtual const char* className();
	protected:
		void init(const char* text,FontTTF* font);
		void generateTexture();

		LabelTTF();
		~LabelTTF();


	private:
		int m_dirty;

		std::string m_string;
		int m_alignv;
		int m_alignh;

		Color m_color;
		float m_opacity;
		FontTTF* m_font;
		Texture2D* m_texture;

		Mat_V4F_T2F* m_material;
};
NS_FS_END

#endif /*_FS_LABLE_TTF_H_*/















