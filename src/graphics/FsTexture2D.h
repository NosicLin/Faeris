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
			FILTER_LINEAR=0,
			FILTER_NEAREST,
			FILTER_MIPMAP,
			WRAP_CLAMP,
			WRAP_REPEAT
		};

	public:
		static Texture2D* create(
				Image2D* image,
				FsInt filter_min,FsInt filter_mag,
				FsInt wraps,FsInt wrapt,
				FsInt internal_format);

		static Texture2D* create(Image2D* image);
	public:
		void setFilter(FsInt min,FsInt mag);
		void setWrap(FsInt wraps,FsInt wrapt);
		FsInt getFilterMin(){return m_filterMin;}
		FsInt getFilterMag(){return m_filterMag;}
		FsInt getWrapS(){return m_wrapS;}
		FsInt getWrapT(){return m_wrapT;}
		FsInt getFormat(){return m_format;}
		FsUint getWidth(){return m_width;}
		FsUint getHeight(){return m_height;}
	public:
		void bind();
	private:
		Texture2D(){}
	private:
		FsUint m_width;
		FsUint m_height;
		FsInt m_format;
		FsInt m_filterMin;
		FsInt m_filterMag;
		FsInt m_wrapS;
		FsInt m_wrapT;
		PlatformTexture m_platformTexture;
};

FAERIS_NAMESPACE_END 

#endif /*_FS_TEXTURE_2D_H_*/

