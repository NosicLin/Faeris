#ifndef _FS_TEXTURE_2D_H_
#define _FS_TEXTURE_2D_H_ 

#include "FsMacros.h"
#include "FsConfig.h"
#include "util/FsResourceMgr.h"
#include "util/FsResource.h"
#include "fsys/FsFile.h"
#include "graphics/FsImage2D.h"

#if FS_CONFIG(FS_GL_RENDER)
	typedef FsUint PlatformTexture;
#else 
	#error "Unsupport PlatformTexture"
#endif 


FAERIS_NAMESPACE_BEGIN 
class Texture2D 
{
	public:
		enum 
		{
			/* filter */
			FILTER_LINEAR=0,
			FILTER_NEAREST,

			/* wrap */
			WRAP_CLAMP,
			WRAP_REPEAT,
			WRAP_CLAMP_TO_EDGE,
			WRAP_CLAMP_TO_BORDER,

			/* format */
			FORMAT_RGBA,
			FORMAT_ALPHA,
			FORMAT_LUMINANCE,
			FORMAT_LUMINANCE_ALPHA,
			FORMAT_INTENSITY,
			FORMAT_RGB,


			/* env mode */
			ENV_DECAL,
			ENV_REPLACE,
			ENV_MODULATE,
			ENV_BLEND,
			ENV_ADD,
			ENV_COMBINE,

		};

	public:
		static Texture2D* create(
				Image2D* image,
				FsInt filter_mag,
				FsInt filter_min,
				FsInt wraps,
				FsInt wrapt,
				FsInt internal_format,
				FsInt env_mode,
				FsBool auto_mipmap=false
				);

		static Texture2D* create(
				Image2D* image,
				FsInt filter_mag,
				FsInt filter_min,
				FsInt filter_mipmap,
				FsInt wraps,
				FsInt wrapt,
				FsInt internal_format,
				FsInt env_mode
				);
		static Texture2D* create(
				Image2D** images,
				FsUint imageCnt,
				FsInt filter_mag,
				FsInt fileter_min,
				FsInt filter_mipmap,
				FsInt wraps,
				FsInt wrapt,
				FsInt internal_format,
				FsInt env_mode);

		/* for quick create texture from image */
		static Texture2D* create(Image2D* image);
	public:


		/* fileter */
		void setFilter(FsInt mag,FsInt min,FsInt mip=FILTER_LINEAR);
		FsInt getFilterMin(){return m_filterMin;}
		FsInt getFilterMag(){return m_filterMag;}
		FsInt getFilterMipmap(){return m_filterMipmap;}

		/* wrap */
		void setWrap(FsInt wraps,FsInt wrapt);
		FsInt getWrapS(){return m_wrapS;}
		FsInt getWrapT(){return m_wrapT;}

		/* format */
		FsInt getFormat(){return m_format;}

		/* height,and width */
		FsUint getWidth(){return m_width;}
		FsUint getHeight(){return m_height;}

		/* mipmap */
		FsBool enableMipmap(FsBool enable);

		/* evn mode */
		void setEvnMode(FsInt mode);
		FsInt getEvnMode(){return m_evnMode;}

	public:
		void bind();
	private:
		Texture2D(){}
	private:
		FsBool m_useMipmap;

		FsInt m_width;
		FsInt m_height;
		/* format */
		FsInt m_format;
		/* filter */
		FsInt m_filterMin;
		FsInt m_filterMag;
		FsInt m_filterMipmap;
		/* wrap */
		FsInt m_wrapS;
		FsInt m_wrapT;
		/* env */
		FsInt m_evnMode;
		PlatformTexture m_platformTexture;
};

FAERIS_NAMESPACE_END 

#endif /*_FS_TEXTURE_2D_H_*/

