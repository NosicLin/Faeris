#include <string.h>

#include "graphics/FsFontBitmap.h"
#include "graphics/FsTexture2D.h"
#include "util/FsDict.h"
#include "util/FsInteger.h"
#include "util/FsArray.h"
#include "io/FsFile.h"
#include "io/FsVFS.h"
#include "common/FsGlobal.h"

NS_FS_BEGIN
#define FS_CHAR_TOKEN_NUM 9
static const char* s_char_token[FS_CHAR_TOKEN_NUM]=
{
	"id=", "x=", "y=", "width=", "height=", "xoffset=", "yoffset=", "xadvance=","page="
};
static int s_char_token_len[FS_CHAR_TOKEN_NUM]=
{
	 3,2,2,6,7,7,8,9,5,
};

GlyphBitmap* GlyphBitmap::create()
{
	return new GlyphBitmap;
}

GlyphBitmap::GlyphBitmap()
	:m_char(0),m_x(0),m_y(0),m_width(0),m_height(0),m_xoffset(0),m_yoffset(0),m_xadvance(0),m_page(0)
{
}
const char* GlyphBitmap::className()
{
	return FS_GLYPH_BITMAP_CLASS_NAME;
}



const char* FontBitmap::className()
{
	return FS_FONT_BITMAP_CLASS_NAME;
}


FontBitmap* FontBitmap::create(const char* fnt)
{
	FsFile* file=VFS::open(fnt);
	if(file==NULL)
	{
		FS_TRACE_WARN("Can't open File(%s) For FontBitmap",fnt);
		return NULL;
	}
	FontBitmap* ret=create(file);
	file->decRef();
	return ret;
}

FontBitmap* FontBitmap::create(FsFile* file)
{
	FontBitmap* ret=new FontBitmap();
	if(!ret->init(file))
	{
		ret->decRef();
		ret=NULL;
	}
	return ret;
}



FontBitmap::FontBitmap()
{
	m_glyphs=NULL;
	m_textureWidth=0;
	m_textureHeight=0;
	m_descent=0;
	m_ascent=0;
	m_baseline=0;
	m_height=0;
	m_textures=NULL;
}

FontBitmap::~FontBitmap()
{
	destroy();
}

void FontBitmap::destroy()
{
	FS_SAFE_DEC_REF(m_glyphs);
	m_glyphs=NULL;

	FS_SAFE_DEC_REF(m_textures);
	m_textures=NULL;
}


bool FontBitmap::init(FsFile* file)
{
	int file_len=file->getLength();

	char* buf=new char[file_len+1];
	buf[file_len]='\0';

	file->read(buf,file_len);

	std::string file_data(buf);

	delete[] buf;

	int cur_pos=0;
	int prev_pos=0;

	int line_height=0;
	int base_line=0;
	int scale_w;
	int scale_h;

	std::string texture_file;
	FsDict* glyphs=FsDict::create();

	int line_num=1;


	bool next=true;
	while(next)
	{
		cur_pos=file_data.find('\n',prev_pos);

		std::string line;
		if(cur_pos==std::string::npos)
		{
			line=file_data.substr(prev_pos,std::string::npos);
			next=false;
		}
		else 
		{
			int length=cur_pos-prev_pos;
			line=file_data.substr(prev_pos,length);
		}

		if(strncmp(line.c_str(),"info",4)==0)
		{
			/* do nothing */
		}
		else if(strncmp(line.c_str(),"common",6)==0)
		{
			/* lineHeight */
			int height_pos=line.find("lineHeight=");
			if(height_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find \"lineHeight\" In Font Bitmap");
				goto error;
			}
			line_height=atoi(line.c_str()+height_pos+11);  /* strlen("lineHeight=") is 11 */


			/* baseLine */
			int baseline_pos=line.find("base=");
			if(baseline_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find \"base\" In Font Bitmap");
				goto error;
			}
			base_line=atoi(line.c_str()+baseline_pos+5); /* strlen("base=") is 5 */


			/* scaleW */
			int scale_w_pos=line.find("scaleW=");
			if(scale_w_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find \"scaleW\" in FontBitmap");
				goto error;
			}
			scale_w=atoi(line.c_str()+scale_w_pos+7); /* strlen("scaleW") is 7 */

			/* scaleH */
			int scale_h_pos=line.find("scaleH=");
			if(scale_w_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find \"scaleH\" in FontBitmap");
				goto error;
			}

			scale_h=atoi(line.c_str()+scale_h_pos+7);  /* strlen("scaleH") is 7 */
		}
		else if (strncmp(line.c_str(),"page",4)==0)
		{
			int file_name_begin_pos=line.find("file=\"");
			if(file_name_begin_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find file name in FontBitmap");
				goto error;
			}

			int file_name_end_pos=  line.find("\"",file_name_begin_pos+6);
			if(file_name_end_pos==std::string::npos)
			{
				FS_TRACE_WARN("Can't Find file name in FontBitmap");
				goto error;
			}

			texture_file=line.substr(file_name_begin_pos+6,file_name_end_pos-file_name_begin_pos-6);
		}

		else if (strncmp(line.c_str(),"char ",5)==0)
		{
			int v_id,v_x,v_y,v_width,v_height,v_xoffset,v_yoffset,v_xadvance,v_page;
			int* values[FS_CHAR_TOKEN_NUM]={&v_id,&v_x,&v_y,&v_width,&v_height,
										&v_xoffset,&v_yoffset,&v_xadvance,&v_page};

			for(int i=0;i<FS_CHAR_TOKEN_NUM;i++)
			{
				int token_pos=line.find(s_char_token[i]);
				if(token_pos==std::string::npos)
				{
					FS_TRACE_WARN("Ignore:Can't Find Token(%s) In Bitmap At Line(%d)",s_char_token[i],line_num);
					goto next_line;
				}
				*values[i]=atoi(line.c_str()+s_char_token_len[i]+token_pos);
			}

			GlyphBitmap* glyph=GlyphBitmap::create();
			glyph->m_char=v_id;
			glyph->m_x=v_x;
			glyph->m_y=v_y;
			glyph->m_width=v_width;
			glyph->m_height=v_height;
			glyph->m_xoffset=v_xoffset;
			glyph->m_yoffset=v_yoffset;
			glyph->m_xadvance=v_xadvance;
			glyph->m_page=v_page;

			FsInteger* key=FsInteger::create(v_id);

			glyphs->insert(key,glyph);
			key->decRef();
			glyph->decRef();
		}
		else
		{
			FS_TRACE_INFO("Ignore Unused Of UnSupport Line(%d)",line_num);
		}

next_line:
		line_num++;
		cur_pos++;
		prev_pos=cur_pos;
	}

	Texture2D* texture=Global::textureMgr()->loadTexture(texture_file.c_str());
	if(texture==NULL)
	{
		FS_TRACE_WARN("Can't Load Texture(%s) For Bitmap".texture_file.c_str());
		goto error;
	}

	m_glyphs=glyphs;
	m_textureWidth=scale_w;
	m_textureHeight=scale_h;

	m_baseline=base_line;
	m_height=line_height;

	m_ascent=m_height-m_baseline;
	m_descent=m_ascent-m_height;

	m_linegap=0;

	m_textures=FsArray::create();
	m_textures->push(texture);
	texture->decRef();
	return true;

error:
	FS_SAFE_DEC_REF(glyphs);
	return false;

};







NS_FS_END;
































