#ifndef _FS_FONT_TTF_H_
#define _FS_FONT_TTF_H_
#include "FsMacros.h"
#include "mgr/FsResource.h"
#include "graphics/FsImage2D.h"
#include "sys/io/FsFile.h"

#define FS_FONT_GLYPH_CACHE_NU 256

NS_FS_BEGIN

class FontTTFData;
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
		static Glyph* create(uint16_t c,uint16_t size);

	public:
		virtual const char* className();

	public:
		void getBound(int* minx,int* miny,int* maxx,int* maxy);
		void setBound(int minx,int miny,int maxx,int maxy);

		void setAdvance(int advance);
		int getAdvance();

		uint16_t getChar();
		uint16_t getSize();

		Image2D* getImage();
		void setImage2D(Image2D* image);

		Texture2D* getTexture();

		void setFont(FontTTFData* data);
		FontTTF* getFont();




	protected:
		Glyph(uint16_t c,uint16_t size);
		~Glyph();

	private:
		/* size and char used for compare */
		uint16_t m_char;
		uint16_t m_size;

		/* glyph metrics */
		int m_minx;
		int m_miny;
		int m_maxx;
		int m_maxy;
		int m_advance;

		/* gray bit */
		Image2D* m_bitmap;
		Texture2D* m_texture;
		FS_FEATURE_WEAK_REF(FontTTF*) m_mgr;
};


class PlatfromFontTTFData;
class FontTTF:public Resource
{
	public:
		class GlyphCompare
		{
		};
		typedef std::set<Glyph*,GlyphCompare> GlyphSet;

	public:
		static FontTTF* create(FsFile* file);

	public:
		Glyph* getGlyph(uint16_t char_index,int size);
		bool getFontMetrices(int size,FontMetrices* metrics);
		void clearCache();



		/* WARN: Please Don't Call It, This Interface Used To Remove Glyph,
		 * 		 When Glyph Destory.
		 */
		void removeGlyph(Glyph* g);

	public:
		virtual const char* className();
	
	protected:
		FontTTF();
		~FontTTF();

		bool init(FsFile* file);
		bool destruct();

		void addToMgr(Glyph* g);
		void addToCache(Glyph* g);

		Glyph* findFromCache(uint16_t char_index,uint16_t size);
		Glyph* findFromMgr(uint16_t char_index,uint16_t size);
		Glyph* createGlyph(uint16_t char_index,uint16_t size);

		uint32_t getGlyphHashCode(Glyph* g);

	private:
		PlatfromFontTTFData* m_data;
		GlyphSet m_glyphSet;
		Glyph* m_caches[FS_FONT_GLYPH_CACHE_NU];
};






NS_FS_END

#endif /*_FS_FONT_TTF_H_*/











