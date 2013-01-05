#include "GL/glew.h"

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
static inline GLint s_filterToGlEnum(FsInt filter_min,FsInt filter_mipmap)
{
	if(filter_min==Texture2D::FILTER_LINEAR)
	{
		if(filter_mipmap==Texture2D::FILTER_LINEAR)
		{
			return GL_LINEAR_MIPMAP_LINEAR;
		}
		else if(filter_mipmap==Texture2D::FILTER_NEAREST)
		{
			return GL_LINEAR_MIPMAP_NEAREST;
		}
		else 
		{
			return GL_LINEAR_MIPMAP_NEAREST;
		}
	}
	else  if(filter_min==Texture2D::FILTER_NEAREST)
	{
		if(filter_mipmap==Texture2D::FILTER_LINEAR)
		{
			return GL_NEAREST_MIPMAP_LINEAR;
		}
		else if(filter_mipmap==Texture2D::FILTER_NEAREST)
		{
			return GL_NEAREST_MIPMAP_NEAREST;
		}
	}
	
	return GL_LINEAR_MIPMAP_LINEAR;
}

static inline GLint s_wrapToGlEnum(FsInt wrap)
{
	switch(wrap)
	{
		case Texture2D::WRAP_CLAMP:
			return GL_CLAMP;
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
			return GL_RGBA8;
		case Texture2D::FORMAT_ALPHA:
			return GL_ALPHA;
		case Texture2D::FORMAT_LUMINANCE:
			return GL_LUMINANCE;
		case Texture2D::FORMAT_LUMINANCE_ALPHA:
			return GL_LUMINANCE_ALPHA;
		case Texture2D::FORMAT_INTENSITY:
			return GL_INTENSITY;
		case Texture2D::FORMAT_RGB:
			return GL_RGB8;
		default:
			return GL_RGBA8;
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
		FsInt filter_mag,
		FsInt filter_min,
		FsInt wraps,
		FsInt wrapt,
		FsInt internal_format
		)
		
{

	GLint format_gl;
	GLint filter_mag_gl,filter_min_gl;
	GLint wraps_gl,wrapt_gl;
	GLint internal_format_gl;
	GLint width,height;
	GLvoid* pixels;

	/* pixel format */
	switch(image->getPixelFormat())
	{
		case Image2D::PIXEL_RGBA8888:
			format_gl=GL_RGBA;
			break;
		case Image2D::PIXEL_RGB888:
			format_gl=GL_RGB;
			break;
		default:
			FS_TRACE_WARN("Unsupport Pixel Format To Texture2D");
			return NULL;
	}

	/* env mode */

	/* gen texture */
	GLuint texture;
	glGenTextures(1,&texture);

	/* bind texture */
	s_bindTexture2D(texture);

	/* filter */
	filter_mag_gl=s_filterToGlEnum(filter_mag);
	filter_min_gl=s_filterToGlEnum(filter_min);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,filter_mag_gl);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,filter_min_gl);

	/* wrap */
	wraps_gl=s_wrapToGlEnum(wraps);
	wrapt_gl=s_wrapToGlEnum(wrapt);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,wraps_gl);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,wrapt_gl);

	/* env mode */

	glPixelStorei(GL_UNPACK_ALIGNMENT,1);

	/* internal_format */
	internal_format_gl=s_fomatToGLEnum(internal_format);


	/* set texture data */
	height=image->getHeight();
	width=image->getWidth();
	pixels=image->getPixelData();

	glTexImage2D(
			GL_TEXTURE_2D,
			0,
			internal_format_gl,
			width,
			height,
			0,
			format_gl,
			GL_UNSIGNED_BYTE,
			pixels
			);

	Texture2D* ret=new Texture2D();
	ret->m_width=width;
	ret->m_height=height;
	ret->m_format=internal_format;
	ret->m_filterMin=filter_min;
	ret->m_filterMag=filter_mag;
	ret->m_filterMipmap=FILTER_LINEAR;
	ret->m_useMipmap=false;
	ret->m_wrapS=wraps;
	ret->m_wrapT=wrapt;
	ret->m_platformTexture=texture;
	return ret;
}


Texture2D* Texture2D::create(
		Image2D** images,
		FsUint imageCnt,
		FsInt filter_mag,
		FsInt filter_min,
		FsInt filter_mipmap,
		FsInt wraps,
		FsInt wrapt,
		FsInt internal_format)
{
	GLint* formats_gl;
	GLint filter_mag_gl,filter_min_gl;
	GLint wraps_gl,wrapt_gl;
	GLint internal_format_gl;
	GLint width,height;
	GLvoid* pixels;

	formats_gl=new GLint[imageCnt];

	/* pixel format */
	for(FsUint i=0;i<imageCnt;++i)
	{
		switch(images[i]->getPixelFormat())
		{
			case Image2D::PIXEL_RGBA8888:
				formats_gl[i]=GL_RGBA;
				break;
			case Image2D::PIXEL_RGB888:
				formats_gl[i]=GL_RGB;
				break;
			default:
				delete[]  formats_gl;
				FS_TRACE_WARN("Unsupport Pixel Format To Texture2D");
				return NULL;
		}
	}

	/* env mode */

	/* gen texture */
	GLuint texture;
	glGenTextures(1,&texture);

	/* bind texture */
	s_bindTexture2D(texture);

	/* filter */
	filter_mag_gl=s_filterToGlEnum(filter_mag);
	filter_min_gl=s_filterToGlEnum(filter_min,filter_mipmap);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,filter_mag_gl);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,filter_min_gl);

	/* wrap */
	wraps_gl=s_wrapToGlEnum(wraps);
	wrapt_gl=s_wrapToGlEnum(wrapt);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,wraps_gl);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,wrapt_gl);

	glPixelStorei(GL_UNPACK_ALIGNMENT,1);

	/* internal_format */
	internal_format_gl=s_fomatToGLEnum(internal_format);

	/* FIXME:
	 * if used glGenerateMipmap, we can't set level 2 or higher 
	 * bitmap, so here use glTexParameteri instead 
	 */
	//glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D,GL_GENERATE_MIPMAP,GL_TRUE);

	for(FsUint i=0;i<imageCnt;++i)
	{
		width=images[i]->getWidth();
		height=images[i]->getHeight();
		pixels=images[i]->getPixelData();
		
		glTexImage2D(
				GL_TEXTURE_2D, 
				i,
				internal_format_gl,
				width,height,
				0,
				formats_gl[i],
				GL_UNSIGNED_BYTE,
				pixels);
	}


	width=images[0]->getWidth();
	height=images[0]->getHeight();

	Texture2D* ret=new Texture2D();
	ret->m_width=width;
	ret->m_height=height;
	ret->m_format=internal_format;
	ret->m_filterMin=filter_min;
	ret->m_filterMag=filter_mag;
	ret->m_filterMipmap=filter_mipmap;
	ret->m_useMipmap=true;
	ret->m_wrapS=wraps;
	ret->m_wrapT=wrapt;
	ret->m_platformTexture=texture;
	delete[] formats_gl;
	return ret;
}

Texture2D* Texture2D::create(Image2D* image)
{
	return create(
			image,
			FILTER_LINEAR,
			FILTER_LINEAR,
			WRAP_CLAMP_TO_EDGE,
			WRAP_CLAMP_TO_EDGE,
			FORMAT_RGBA);
}

void Texture2D::setFilter(FsInt mag,FsInt min,FsInt mipmap)
{
	s_bindTexture2D(m_platformTexture);
	GLint filter_min_gl,filter_mag_gl;
	filter_mag_gl=s_filterToGlEnum(mag);
	if(m_useMipmap)
	{
		filter_min_gl=s_filterToGlEnum(min,mipmap);
	}
	else 
	{
		filter_min_gl=s_filterToGlEnum(min);
	}

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,filter_mag_gl);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,filter_min_gl);
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









