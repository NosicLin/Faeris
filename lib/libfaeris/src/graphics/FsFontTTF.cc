#include "ft2build.h"
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include "graphics/FsFontTTF.h"
#include "graphics/FsImage2D.h"
#include "graphics/FsTexture2D.h"
#include "graphics/material/FsMat_V4F_C4F.h"
#include "FsGlobal.h"
#include "sys/io/FsFile.h"


#define FT_FLOOR(X)	((X & -64) / 64)
#define FT_CEIL(X)	(((X + 63) & -64) / 64)



NS_FS_BEGIN
static FT_Library S_mLibrary;

static int S_mFreetypeRefNu=0;

static int S_RefFreetype()
{
	if(S_mFreetypeRefNu==0)
	{
		FT_Error error = FT_Init_FreeType( &S_mLibrary);
		if(error)
		{
			FS_TRACE_WARN("init FT_Library Failed");
			return -1;
		}
	}
	S_mFreetypeRefNu++;
	return 0;
}

static int S_unRefFreeType()
{
	assert(S_mFreetypeRefNu>0);
	S_mFreetypeRefNu--;
	if(S_mFreetypeRefNu==0)
	{
		FT_Done_FreeType(S_mLibrary);
	}
	return 0;
}


static unsigned long  S_fileRead(FT_Stream stream,
		unsigned long offset,
		unsigned char* buffer,
		unsigned long count)
{
	int readbyte;
	FsFile* file=(FsFile*)stream->descriptor.pointer;
	file->seek(offset,FsFile::FS_SEEK_SET);
	readbyte=file->read(buffer,count);
	return readbyte;
}




class PlatfromFontTTF
{
	public:
		PlatfromFontTTF();
		~PlatfromFontTTF();
	public:
		Glyph* createGlyph(uint16_t char_index,int size);
		bool getFontMetrices(int size,FontMetrices* metrics);

		bool init(FsFile* file);
		bool setFontSize(int size);
		void destruct();

	private:
		int m_curSize;
		bool m_refFreeType;
		FsFile* m_source;
		FT_Stream m_stream;
		FT_Face m_face;
		FT_Open_Args m_args;
};

Glyph* PlatfromFontTTF::createGlyph(uint16_t char_index,int size)
{
	if(!setFontSize(size))
	{
		return NULL;
	}
	int error=FT_Load_Char(m_face,char_index,FT_LOAD_RENDER);
	if(error)
	{
		FS_TRACE_WARN("Load Glyph(%d) Failed",char_index);
		return NULL;
	}
	Glyph* ret=Glyph::create();

	/* get glyph metrics */
	FT_Glyph_Metrics* metrics=&m_face->glyph->metrics;


	int minx=FT_FLOOR(metrics->horiBearingX);
	int maxx=ret->m_minx+FT_CEIL(metrics->width);
	int maxy=FT_FLOOR(metrics->horiBearingY);
	int miny=ret->m_maxy-FT_CEIL(metrics->height);
	int advance=FT_CEIL(metrics->horiAdvance);

	ret->setBound(minx,miny,maxx,maxy);
	ret->setAdvance(advance);



	FT_Bitmap* bitmap_src=&m_face->glyph->bitmap;
	int rows=bitmap_src->rows;
	int width=bitmap_src->width;

	if(rows==0||width==0)
	{
		return ret;
	}

	if(bitmap_src->pixel_mode!=FT_PIXEL_MODE_GRAY)
	{
		FS_TRACE_WARN("bitmap is not 8 bit gray");
		return ret;
	}
	Image2D* image=Image2D::create(width,rows,Image2D::PIXEL_GRAY8);

	void* data_dst=image->getPixelData();
	void* data_src=bitmap_src->buffer;

	memcpy(data_dst,data_src,rows*width);

	ret->setImage(image);

	return ret;
}

bool PlatfromFontTTF::getFontMetrices(int size,FontMetrices* metrics)
{
	if(!setFontSize(size))
	{
		return false;
	}

	FT_Fixed scale;
	scale=m_face->size->metrics.y_scale;

	metrics->m_ascend=FT_CEIL(FT_MulFix(m_face->ascender,scale));
	metrics->m_descend=FT_CEIL(FT_MulFix(m_face->descender,scale));
	metrics->m_height=metrics->m_ascend-metrics->m_descend+1;
	return true;
}

PlatfromFontTTF::PlatfromFontTTF()
{
	m_curSize=-1;
	m_source=NULL;
	m_stream=NULL;
	m_face=NULL;
	m_refFreeType=false;
}
PlatfromFontTTF::~PlatfromFontTTF()
{
	if(m_face)
	{
		FT_Done_Face(m_face);
	}

	FS_SAFE_DEC_REF(m_source);

	if(m_stream)
	{
		free(m_stream);
	}
	if(m_refFreeType)
	{
		S_unRefFreeType();
	}
}


bool PlatfromFontTTF::init(FsFile* file)
{
	if(S_RefFreetype()<0)
	{
		return false;
	}

	m_refFreeType=true;

	FT_CharMap found=NULL;
	FT_Error error;
	m_stream=(FT_Stream)malloc(sizeof(*m_stream));
	memset(m_stream,0,sizeof(*m_stream));
	m_stream->read=S_fileRead;
	m_stream->descriptor.pointer=file;
	m_stream->pos=0;
	m_stream->size=file->getLength();

	m_args.flags=FT_OPEN_STREAM;
	m_args.stream=m_stream;

	error=FT_Open_Face(S_mLibrary,&m_args,0,&m_face);
	if(error)
	{
		FS_TRACE_WARN("Open FT_Face Failed");
		free(m_stream);
		m_stream=NULL;
		return false;
	}

	for(int i=0;i<m_face->num_charmaps;i++)
	{
		FT_CharMap charmap=m_face->charmaps[i];

		if ((charmap->platform_id == 3 && charmap->encoding_id == 1) /* Windows Unicode */
				||(charmap->platform_id == 3 && charmap->encoding_id == 0) /* Windows Symbol */
				||(charmap->platform_id == 2 && charmap->encoding_id == 1) /* ISO Unicode */
				||(charmap->platform_id == 0)) /* Apple Unicode */
		{ 
			found = charmap;
			break;
		}
	}
	if(found) 
	{
		FT_Set_Charmap(m_face,found);
	}

	FS_SAFE_ASSIGN(m_source,file);
	m_curSize=-1;
	return true;
}



bool PlatfromFontTTF::setFontSize(int size)
{
	if(m_curSize==size)
	{
		return true;
	}
	FT_Error error=FT_Set_Char_Size(m_face,0,size*64,0,0);
	if(error)
	{
		FS_TRACE_WARN("Can't Set Font Size(%d)",size);
		return false;
	}
	m_curSize=size;
	return true;
}


Glyph* Glyph::create(uint16_t c_id,uint16_t size)
{
	Glyph* ret=new Glyph(c_id,size);
	return ret;
}

const char* Glyph::className()
{
	return FS_GLYPH_CLASS_NAME;
}

Glyph::Glyph(uint16_t c_id,uint16_t size)
{
	m_char=c_id;
	m_size=size;
	m_minx=0;
	m_miny=0;
	m_maxx=0;
	m_maxy=0;
	m_advance=0;
	m_bitmap=NULL;
	m_texture=NULL;
}
uint16_t Glyph::getChar()
{
	return m_char;
}
uint16_t Glyph::getSize()
{
	return m_size;
}

void Glyph::setBound(int minx,int miny,int maxx,int maxy)
{
	m_minx=minx;
	m_miny=miny;
	m_maxx=maxx;
	m_maxy=maxy;
}

void Glyph::getBound(int* minx,int* miny,int* maxx,int* maxy)
{
	*minx=m_minx;
	*miny=m_miny;
	*maxx=m_maxx;
	*maxy=m_maxy;
}


Image2D* Glyph::getImage()
{
	return m_bitmap;
}

void Glyph::setImage(Image2D* image)
{
	FS_SAFE_ASSIGN(m_bitmap,image);
}


Texture2D* Glyph::getTexture()
{
	if(!m_texture)
	{
		if(m_bitmap)
		{
			m_texture=Texture2D::create(m_bitmap);
			FS_NO_REF_DESTROY(m_texture);
		}
	}

	return m_texture;
}

Glyph::~Glyph()
{
	if(m_mgr)
	{
		m_mgr->removeGlyph(this);
		m_mgr=NULL;
	}

	FS_SAFE_DEC_REF(m_bitmap);
	FS_SAFE_DESTROY(m_texture);
}



/* ----- FontTTF ------ */

FontTTF* FontTTF::create(FsFile* file)
{
	FontTTF* ret=new FontTTF();
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}


Glyph* FontTTF::getGlyph(uint16_t char_index,int size)
{
	Glyph* g=NULL;

	g=findFromCache(char_index,size);
	if(g)
	{
		return g;
	}

	g=findFromMgr(char_index,size);
	if(!g)
	{
		Glyph* g=m_data->createGlyph(char_index,size);
		addToMgr(g);
	}
	if(g)
	{
		addToCache(g);
	}
	return g;
}


void FontTTF::removeGlyph(Glyph* g)
{
	assert(findFromCache(g->getChar(),g->getSize())==NULL);
	m_glyphSet.erase(g);
}




bool FontTTF::getFontMetrices(int size,FontMetrices* metrics)
{
	return m_data->getFontMetrices(size,metrics);
}


const char* FontTTF::className()
{
	return FS_FONT_TTF_DATA_CLASS_NAME;
}

bool FontTTF::init(FsFile* file)
{
	m_data=new PlatfromFontTTF();
	return m_data->init(file);
}

FontTTF::FontTTF()
{
	m_data=NULL;
	for(int i=0;i<FS_FONT_GLYPH_CACHE_NU;i++)
	{
		m_caches[i]=NULL;
	}
}

void FontTTF::clearCache()
{
	for(int i=0;i<FS_FONT_GLYPH_CACHE_NU;i++)
	{
		Glyph* g=m_caches[i];
		FS_SAFE_DEC_REF(g);
		m_caches[i]=NULL;
	}
}


void FontTTF::destruct()
{
	GlyphSet::iterator iter;
	for(iter=m_glyphSet.begin();iter!=m_glyphSet.end();++iter)
	{
		iter->setFont(NULL);
	}
	m_glyphSet.clear();

	clearCache();
	FS_SAFE_DELETE(m_data);
}


FontTTF::~FontTTF()
{
	destruct();
}


void FontTTF::addToMgr(Glyph* g)
{
	g->setFont(this);

	m_glyphSet.insert(g);
}


void FontTTF::addToCache(Glyph* g)
{
	uint32_t hash_code=glyphHashCode(g);

	int index=hash_code%(FS_FONT_GLYPH_CACHE_NU-1);

	Glyph* old=m_caches[index];

	FS_SAFE_DEC_REF(old);

	FS_SAFE_ADD_REF(g);

	m_caches[index]=g;

}

Glyph* FontTTF::findFromCache(uint16_t char_index,uint16_t size)
{

	uint32_t hash_code=glyphHashCode(g);
	int index=hash_code%(FS_FONT_GLYPH_CACHE_NU-1);

	Glyph* g=m_caches[index];
	if(g)
	{
		if(g->getChar()==char_index&& g->getSize()==size)
		{
			return g;
		}
	}
	return NULL;

}


Glyph* FontTTF::findFromMgr(uint16_t char_index, uint16_t size)
{
	Glyph g(char_index,size);

	GlyphSet::iterator iter=m_glyphSet->find(g);

	if(iter!=m_glyphSet.end())
	{
		return  *iter;
	}

	return NULL;
}



Glyph* FontTTF::createGlyph(uint16_t char_index,uint16_t size)
{
	Glyph* g=m_data->createGlyph();
	return g;
}


uint32_t FontTTF::getGlyphHashCode(Glyph* g)
{
	uint32_t c_id=g->getChar();
	uint32_t size=g->getSize();
	return size<<16|c_id;
}











NS_FS_END



















