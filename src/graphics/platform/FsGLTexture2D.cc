#include "GL/gl.h"

#include "graphics/FsTexture2D.h"

static GLuint s_curBindTexture=0;
static void s_bindTexture2D(GLuint texture)
{
	if(s_curBindTexture==texture)
	{
		return;
	}
	glBindTexture(GL_TEXTURE_2D,texture);
	s_curBindTexture=texture;
}



static inline GLint s_filterToGlEnum(FsInt filter)
{
	switch(filter)
	{
		case Texture2D::FILTER_LINEAR:
			return GL_LINEAR;
		case Texture2D::FILTER_NEAREST:
			return GL_NEAREST;
		default:
			return GL_LINEAR;
	}
}
static inline GLint s_wrapToGlEnum(FsInt wrap)
{
	switch(wrap)
	{
		case Texture2D::WRAP_CLAMP:
			return GL_CLAMP
		case Texture2D::WRAP_REPEAT:
			return GL_REPEAT;
		case Texture2D::WRAP_CLAMP_TO_EDGE:
			return GL_CLAMP_TO_EDGE;
		case Texture2D::WRAP_CLAMP_TO_BORDER:
			return GL_CLAMP_TO_BORDER;
		default:
			return GL_CLAMP_TO_EDGE;
	}
}

static inline GLint s_fomatToGLEnum(FsInt format)
{
	switch(format)
	{
		case Texture2D::FORMAT_RGBA:
			return GL_RGBA;
		case Texture2D::FORMAT_ALPHA:
			return GL_ALPHA;
		case Texture2D::FORMAT_LUMINANCE:
			return GL_LUMINANCE;
		case Texture2D::FORMAT_LUMINANCE_ALPHA:
			return GL_LUMINANCE_ALPHA;
		case Texture2D::FORMAT_INTENSITY:
			return GL_INTENSITY;
		case Texture2D::FORMAT_RGB:
			return GL_RGB;
		default:
			return GL_RGBA;
	}
}

static inline GLint s_envModeToGLEnum(FsInt mode)
{
	switch(mode)
	{
		case Texture2D::ENV_DECAL:
			return GL_DECAL;
		case Texture2D::ENV_REPLACE:
			return GL_REPLACE;
		case Texture2D::ENV_MODULATE:
			return GL_MODULATE;
		case Texture2D::ENV_BLEND:
			return GL_BLEND;
		case Texture2D::ENV_ADD:
			return GL_ADD;
		case Texture2D::ENV_COMBINE:
			return GL_COMBINE;
		default:
			return GL_REPLACE;
	}
}



Texture2D* Texture2D::create(
		Image2D* image,
		FsInt internal_format,
		FsInt filter_min,FsInt filter_mag,
		FsInt wraps,FsInt wrapt)
{

	GLint format;
	switch(image->getPixelFormat())
	{
		case Image2D::PIXEL_RGBA8888:
			format=GL_RGBA;
			break;
		case Image2D::PIXEL_RGB888:
			format=GL_RGB;
			break;
		default:
			FS_TRACE_WARN("Unsupport Pixel Format To Texture2D");
			return NULL;
	}

	GLint gl_interal_format=internal_format==Image2D::PIXEL_RGBA8888?GL_RGBA8:GL_RGB8;

	GLint gl_filter_min=s_filterToGlEnum(filter_min);
	GLint gl_filter_mag=s_filterToGlEnum(filter_mag);

	GLint gl_wraps=s_wrapToGlEnum(wraps);
	GLint gl_wrapt=s_wrapToGlEnum(wrapt);

	GLsizei width=image->getWidth();
	GLsizei height=image->getHeight();
	GLvoid* pixels=(GLvoid*)image->getPixelData();

	GLuint texture;
	glGenTextures(1,&texture);

	s_bindTexture2D(texture);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,gl_filter_min);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,gl_filter_mag);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,gl_wraps);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,gl_wrapt);

	glPixelStorei(GL_UNPACK_ALIGNMENT,1);

	glTexImage2D(
			GL_TEXTURE_2D,
			0,
			gl_interal_format,
			width,
			height,
			0,
			format,
			GL_UNSIGNED_BYTE,
			pixels
			);

	Texture2D* ret=new Texture2D();
	ret->m_width=width;
	ret->m_height=height;
	ret->m_format=internal_format;
	ret->m_filterMin=filter_min;
	ret->m_filterMag=filter_mag;
	ret->m_wrapS=wraps;
	ret->m_wrapT=wrapt;
	ret->m_platformTexture=texture;
	return ret;
}

Texture2D* Texture2D::create(Image2D* image)
{
	return create(image,FILTER_LINEAR,FILTER_LINEAR,WRAP_CLAMP,WRAP_CLAMP,Image2D::PIXEL_RGBA8888);
}

void Texture2D::setFilter(FsInt min,FsInt mag)
{
	s_bindTexture2D(m_platformTexture);
	GLint gl_filter_min=s_filterToGlEnum(min);
	GLint gl_filter_mag=s_filterToGlEnum(mag);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,gl_filter_min);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,gl_filter_mag);
}

void Texture2D::setWrap(FsInt wraps,FsInt wrapt)
{
	s_bindTexture2D(m_platformTexture);
	GLint gl_wraps=s_wrapToGlEnum(wraps);
	GLint gl_wrapt=s_wrapToGlEnum(wrapt);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,gl_wraps);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,gl_wrapt);
}
void Texture2D::bind()
{
	s_bindTexture2D(m_platformTexture);
}









