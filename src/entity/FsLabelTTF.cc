#include <stdlib.h>
#include <string.h>
#include "data/FsIconv.h"
#include "entity/FsLabelTTF.h"
#include "material/FsPositionTextureMaterial.h"
#include "graphics/FsImage2D.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsFontTTF.h"
#include "graphics/FsRender.h"
#include "util/FsArray.h"


NS_FS_BEGIN


Image2D* LineTypography::typo(const char* text,FontTTF* font)
{
	uint16_t* unicode=FsIconv_UTF8_to_UNICODE(text);
	if(!unicode)
	{
		return NULL;
	}
	uint16_t* cur=unicode;
	uint16_t ch;
	
	FsArray* glyphs=FsArray::create();

	while((ch=(*cur++)))
	{
		if(ch=='\n') /* just ignore  new line */
		{
			continue;
		}

		Glyph* g=font->loadGlyph(ch);
		if(font)
		{
			glyphs->push(g);
		}
		else 
		{
			FS_TRACE_WARN("Can't Load Glyph %d,just ignore it",ch);
		}

		FS_SAFE_DEC_REF(g);
	}

	int maxx,minx,maxy, miny;
	int glyphs_nu=glyphs->size();

	int penx=0;
	for(int i=0;i<glyphs_nu;i++)
	{
		Glyph* g=(Glyph*)glyphs->get(i);
		if(i==0)
		{
			maxx=g->m_maxx;
			minx=g->m_minx;
			maxy=g->m_maxy;
			miny=g->m_miny;
			penx=minx+g->m_advance;
		}
		else 
		{
			if(maxy<g->m_maxy)
			{
				maxy=g->m_maxy;
			}
			if(miny>g->m_miny)
			{
				miny=g->m_miny;
			}
			if(minx>penx+g->m_minx)
			{
				minx=penx+g->m_minx;
			}
			if(maxx<penx+g->m_maxx)
			{
				maxx=penx+g->m_maxx;
			}
			penx+=g->m_advance;
		}
		g->decRef();
	}

	int width=maxx-minx+1;
	int height=maxy-miny;
	int font_height=font->getHeight();
	assert(height<=font_height);
	height=font_height;


	if(width==0)
	{
		glyphs->decRef();
		delete unicode;
		return NULL;
	}
	Image2D* dst_image=Image2D::create(width,height,
										Image2D::PIXEL_RGBA8888);
	uint8_t* dst_buffer=(uint8_t*)dst_image->getPixelData();
	memset(dst_buffer,0,width*height*4);

	int startx=0;

	for(int i=0;i<glyphs_nu;i++)
	{
		Glyph* g=(Glyph*)glyphs->get(i);
		if(g->m_bitmap==NULL)
		{
			startx+=g->m_advance;
			continue;
		}

		uint8_t* src_buffer=(uint8_t*)g->m_bitmap->getPixelData();
		int glyph_width=g->m_bitmap->getWidth();
		int glyph_height=g->m_bitmap->getHeight();

		assert(font->getAscend()>=g->m_maxy);
		int y_offset=font->getAscend()-g->m_maxy;


		for(int j=0;j<glyph_height;j++)
		{
			for(int z=0;z<glyph_width;z++)
			{
				assert(z+startx<width);
				uint8_t gray=src_buffer[j*glyph_width+z];
				uint8_t* cur_dst_buffer=dst_buffer+((j+y_offset)*width+z+startx)*4;
				*cur_dst_buffer=255;
				*(cur_dst_buffer+1)=255;
				*(cur_dst_buffer+2)=255;
				*(cur_dst_buffer+3)=gray;
			}
		}
		g->decRef();
		startx+=g->m_advance;
	}
	glyphs->decRef();
	delete[] unicode;
	return dst_image;
}

const char*  LabelTTF::className()
{
	return FS_LABEL_TTF_CLASS_NAME;
}

LabelTTF* LabelTTF::create(const char* text,FontTTF* font)
{
	LabelTTF* ret=new LabelTTF;
	ret->init(text,font);
	return ret;
}

void LabelTTF::setString(const char* text)
{
	if(m_string!=text)
	{
		m_string=text;
		m_dirty=true;
	}
}

const char* LabelTTF::getString()
{
	return m_string.c_str();
}


void LabelTTF::setFont(FontTTF* font)
{
	if(font!=m_font)
	{
		FS_SAFE_ADD_REF(font);
		FS_SAFE_DEC_REF(m_font);
		m_font=font;
		m_dirty=true;
	}
}

FontTTF* LabelTTF::getFont()
{
	FS_SAFE_ADD_REF(m_font);
	return m_font;
}


void LabelTTF::setAlign(int h,int v)
{
	m_alignv=v;
	m_alignh=h;
}

void LabelTTF::getAlign(int* h,int* v)
{
	*h=m_alignh;
	*v=m_alignv;
}


void LabelTTF::setColor(Color c)
{
	m_color=c;
}

Color LabelTTF::getColor()
{
	return m_color;
}

void LabelTTF::setOpacity(float opacity)
{
	m_opacity=opacity;
}


float LabelTTF::getOpacity()
{
	return m_opacity;
}


void LabelTTF::draw(Render* render,bool updateMatrix)
{
	if(m_dirty)
	{
		generateTexture();
		m_dirty=false;
	}

	if(!m_texture)
	{
		return ;
	}

	if(updateMatrix)
	{
		updateWorldMatrix();
	}
	render->pushMatrix();
	render->mulMatrix(m_worldMatrix);
	m_material->setOpacity(m_opacity);
	m_material->setColor(m_color);
	render->setMaterial(m_material,true);

	render->setActiveTexture(1);
	render->disableAllClientArray();
	render->disableAllAttrArray();
	render->bindTexture(m_texture,0);

	float x,y,width,height;

	width=(float)m_texture->getWidth();
	height=(float)m_texture->getHeight();

	switch(m_alignv)
	{
		case ALIGN_V_CENTER:
			y=-height/2;
			break;
		case ALIGN_V_TOP:
			y=-height;
			break;
		case ALIGN_V_BOTTOM:
			y=0;
			break;
	}
	switch(m_alignh)
	{
		case ALIGN_H_LEFT:
			x=0;
			break;
		case ALIGN_H_CENTER:
			x=width/2;
			break;
		case ALIGN_H_RIGHT:
			x=width;
			break;
	}

	Vector3 vv[4]=
	{
		Vector3(x,y,0.0f),
		Vector3(x+width,y,0.0f),
		Vector3(x+width,y+height,0.0f),
		Vector3(x,y+height,0.0f),
	};

	TexCoord2 vc[4]=
	{
		TexCoord2(0,1),
		TexCoord2(1,1),
		TexCoord2(1,0),
		TexCoord2(0,0),
	};

	Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};

	render->setAndEnableVertexAttrPointer("a_position",3,FS_FLOAT,4,0,vv);
	render->setAndEnableVertexAttrPointer("a_texCoord",2,FS_FLOAT,4,0,vc);

	render->drawFace3(faces,2);
	render->popMatrix();
}

void LabelTTF::init(const char* text,FontTTF* font)
{
	m_dirty=true;

	m_string=text;
	FS_SAFE_ADD_REF(font);
	m_font=font;
}

void LabelTTF::generateTexture()
{
	FS_SAFE_DEC_REF(m_texture);
	m_texture=NULL;
	if(!m_font) /* no font exist */
	{
		return;
	}

	LineTypography typo;
	Image2D* image=typo.typo(m_string.c_str(), m_font);
	if(image==NULL)
	{
		return;
	}

	m_texture=Texture2D::create(image);
	image->decRef();
}

LabelTTF::LabelTTF()
{
	m_dirty=true;
	m_string="";
	m_color=Color::WHITE;
	m_opacity=1.0f;
	m_texture=NULL;
	m_material=PositionTextureMaterial::shareMaterial();
	m_font=NULL;
	m_alignv=ALIGN_V_BOTTOM;
	m_alignh=ALIGN_H_LEFT;
}

LabelTTF::~LabelTTF()
{
	FS_SAFE_DEC_REF(m_texture);
	FS_SAFE_DEC_REF(m_font);
	m_material->decRef();
}


NS_FS_END

















