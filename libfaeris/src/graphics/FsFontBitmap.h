#ifndef _FS_FONT_BITMAP_H_
#define _FS_FONT_BITMAP_H_

#include "FsMacros.h"
#include "mgr/FsResource.h"

NS_FS_BEGIN
class FsDict;
class FsArray;
class FsFile;

class GlyphBitmap:public FsObject 
{
	public:
		static GlyphBitmap* create();
	public:
		GlyphBitmap();

	public:
		/* override FsObject */
		virtual const char* className();

	public:
		uint16_t m_char;
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		int m_xoffset;
		int m_yoffset;
		int m_xadvance;
		int m_page;
};

class FontBitmap:public Resource
{
	public:
		static FontBitmap* create(const char* fnt);
		static FontBitmap* create(FsFile* file);
	public:
		GlyphBitmap* loadGlyph(uint16_t char_index);


		int getLineGap(){return m_linegap;}
		void  setLineGap(int line_gap){m_linegap=line_gap;}

		int getHeight(){return m_height;}
		int getAscent(){return m_ascent;}
		int getDescent(){return m_descent;}
		int getBaseline(){return m_baseline;}

		int getTextureWidth(){return m_textureWidth;}
		int getTextureHeight(){return m_textureHeight;}

	public:
		/* override FsObject */
		virtual const char* className();

	protected:
		FontBitmap();
		virtual ~FontBitmap();

		bool init(FsFile* file);
		void destroy();

	private:
		FsDict* m_glyphs;

		int m_textureWidth;
		int m_textureHeight;

		int m_descent;
		int m_ascent;
		int m_baseline;
		int m_height;
		int m_linegap;

		FsArray* m_textures;
};





NS_FS_END 
#endif 



