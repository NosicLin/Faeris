#ifndef _FS_FONT_TTF_H_
#define _FS_FONT_TTF_H_
#include "FsMacros.h"
#include "mgr/FsResource.h"
#include "graphics/FsImage2D.h"
#include "sys/io/FsFile.h"

#define FS_FONT_GLYPH_CACHE_NU 256

NS_FS_BEGIN

class FontMetrices 
{
	public:
		int m_ascend;
		int m_descend;
		int m_height;
};


class Glyph:public FsObject
{
	public:
		static Glyph* create();

	public:
		uint16_t m_char;
		/* glyph metrics */
		int m_minx;
		int m_miny;
		int m_maxx;
		int m_maxy;
		int m_advance;

		/* gray bit */
		Image2D* m_bitmap;
	public:
		virtual const char* className();

	protected:
		Glyph();
		~Glyph();
};


class PlatfromFontTTFData;
class FontTTFData:public Resource
{
	public:
		static FontTTFData* create(FsFile* file);
	public:
		Glyph* loadGlyph(uint16_t char_index,int size);
		bool getFontMetrices(int size,FontMetrices* metrics);

	public:
		virtual const char* className();
	
	protected:
		bool init(FsFile* file);
		FontTTFData();
		~FontTTFData();

	private:
		PlatfromFontTTFData* m_data;

};


class FontTTF:public FsObject
{
	public:
		static FontTTF* create(const char* name,int size);

	public:
		Glyph* loadGlyph(uint16_t char_index);
		int getHeight();
		int getAscend();
		int getDescend();
	public:
		virtual const char* className();

	protected:
		FontTTF();
		virtual ~FontTTF();

		void purgeCache();
		void addCache(Glyph* glyph);
	private:
		FontTTFData* m_data;
		int m_size;
		FontMetrices m_metrices;

		Glyph* m_caches[FS_FONT_GLYPH_CACHE_NU-1];
};


NS_FS_END

#endif /*_FS_FONT_TTF_H_*/











