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
static FT_Library s_library;
static bool s_freetypeInitFlags=false;
static int s_initFreetype()
{
	if(!s_freetypeInitFlags)
	{
		FT_Error error = FT_Init_FreeType( &s_library );
		if(error)
		{
			FS_TRACE_WARN("init FT_Library Failed");
			return -1;
		}
		s_freetypeInitFlags=true;
	}

	return 0;
}



static unsigned long  s_fileRead(FT_Stream stream,
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




class PlatfromFontTTFData
{
	public:
		PlatfromFontTTFData();
		~PlatfromFontTTFData();
	public:
		Glyph* createGlyph(uint16_t char_index,int size);
		bool getFontMetrices(int size,FontMetrices* metrics);

		bool init(FsFile* file);
		bool setFontSize(int size);
		void destruct();

	private:
		int m_curSize;
		FsFile* m_source;
		FT_Stream m_stream;
		FT_Face m_face;
		FT_Open_Args m_args;
};

Glyph* PlatfromFontTTFData::createGlyph(uint16_t char_index,int size)
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

	ret->m_minx=FT_FLOOR(metrics->horiBearingX);
	ret->m_maxx=ret->m_minx+FT_CEIL(metrics->width);
	ret->m_maxy=FT_FLOOR(metrics->horiBearingY);
	ret->m_miny=ret->m_maxy-FT_CEIL(metrics->height);
	ret->m_advance=FT_CEIL(metrics->horiAdvance);

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
	FS_NO_REF_DESTROY(image);

	void* data_dst=image->getPixelData();
	void* data_src=bitmap_src->buffer;
	memcpy(data_dst,data_src,rows*width);

	ret->m_bitmap=image;
	return ret;
}

bool PlatfromFontTTFData::getFontMetrices(int size,FontMetrices* metrics)
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

PlatfromFontTTFData::PlatfromFontTTFData()
{
	m_curSize=-1;
	m_source=NULL;
	m_stream=NULL;
	m_face=NULL;
}
PlatfromFontTTFData::~PlatfromFontTTFData()
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
}


bool PlatfromFontTTFData::init(FsFile* file)
{
	if(s_initFreetype()<0)
	{
		return false;
	}


	FT_CharMap found=NULL;
	FT_Error error;
	m_stream=(FT_Stream)malloc(sizeof(*m_stream));
	memset(m_stream,0,sizeof(*m_stream));
	m_stream->read=s_fileRead;
	m_stream->descriptor.pointer=file;
	m_stream->pos=0;
	m_stream->size=file->getLength();

	m_args.flags=FT_OPEN_STREAM;
	m_args.stream=m_stream;

	error=FT_Open_Face(s_library,&m_args,0,&m_face);
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



bool PlatfromFontTTFData::setFontSize(int size)
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


Glyph* Glyph::create()
{
	Glyph* ret=new Glyph;
	return ret;
}

const char* Glyph::className()
{
	return FS_GLYPH_CLASS_NAME;
}

Glyph::Glyph()
{
	m_char=-1;
	m_minx=0;
	m_miny=0;
	m_maxx=0;
	m_maxy=0;
	m_advance=0;
	m_bitmap=NULL;
}

Glyph::~Glyph()
{
	FS_SAFE_DESTROY(m_bitmap);
}

FontTTFData* FontTTFData::create(FsFile* file)
{
	FontTTFData* ret=new FontTTFData();
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Glyph* FontTTFData::createGlyph(uint16_t char_index,int size)
{
	return m_data->createGlyph(char_index,size);
}

bool FontTTFData::getFontMetrices(int size,FontMetrices* metrics)
{
	return m_data->getFontMetrices(size,metrics);
}

const char* FontTTFData::className()
{
	return FS_FONT_TTF_DATA_CLASS_NAME;
}

bool FontTTFData::init(FsFile* file)
{
	m_data=new PlatfromFontTTFData();
	return m_data->init(file);
}

FontTTFData::FontTTFData()
{
	m_data=NULL;
}

FontTTFData::~FontTTFData()
{
	FS_SAFE_DELETE(m_data);
}


FontTTF* FontTTF::create(const char* name,int size)
{
	FontTTFData* data=(FontTTFData*)Global::fontTTFDataMgr()->load(name);
	if(!data)
	{
		return NULL;
	}
	FontTTF* ret=new FontTTF;
	if(!data->getFontMetrices(size,&ret->m_metrices))
	{
		FS_DESTROY(ret);
		return NULL;
	}
	FS_SAFE_ASSIGN(ret->m_data,data);
	ret->m_size=size;
	return ret;
}

Glyph* FontTTF::getGlyph(uint16_t char_index)
{
	Glyph* ret=m_caches[char_index%(FS_FONT_GLYPH_CACHE_NU-1)];

	if(ret&&ret->m_char==char_index)
	{
		return ret;
	}

	ret=m_data->createGlyph(char_index,m_size);
	if(ret)
	{
		addCache(ret);
	}
	return ret;
}

int FontTTF::getHeight()
{
	return m_metrices.m_height;
}

int FontTTF::getAscend()
{
	return m_metrices.m_ascend;
}

int FontTTF::getDescend()
{
	return m_metrices.m_descend;
}
const char* FontTTF::className()
{
	return FS_FONT_TTF_CLASS_NAME;
}


FontTTF::FontTTF()
{
	m_data=NULL;
	m_size=-1;
	for(int i=0;i<FS_FONT_GLYPH_CACHE_NU-1;i++)
	{
		m_caches[i]=NULL;
	}
}

FontTTF::~FontTTF()
{
	purgeCache();
	FS_SAFE_DEC_REF(m_data);
}


void FontTTF::purgeCache()
{
	for(int i=0;i<FS_FONT_GLYPH_CACHE_NU-1;i++)
	{
		if(m_caches[i])
		{
			m_caches[i]->decRef();
			m_caches[i]=NULL;
		}
	}
}

void FontTTF::addCache(Glyph* glyph)
{
	int char_index=glyph->m_char%(FS_FONT_GLYPH_CACHE_NU-1);

	Glyph* old=m_caches[char_index];

	if(old!=NULL)
	{
		old->decRef();
	}

	glyph->addRef();
	m_caches[char_index]=glyph;
}
NS_FS_END









