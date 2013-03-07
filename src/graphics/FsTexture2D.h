#ifndef _FS_TEXTURE_2D_H_
#define _FS_TEXTURE_2D_H_ 

#include "FsMacros.h"
#include "FsConfig.h"
#include "io/FsResourceMgr.h"
#include "io/FsResource.h"
#include "io/FsFile.h"
#include "graphics/FsImage2D.h"

#if FS_CONFIG(FS_GL_RENDER)
	typedef uint PlatformTexture;
#else 
	#error "Unsupport PlatformTexture"
#endif 



NS_FS_BEGIN 
class Texture2D:public FsResource
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

		};

	public:
		static Texture2D* create(
				Image2D* image,
				int filter_mag,
				int filter_min,
				int wraps,
				int wrapt,
				int internal_format);

		static Texture2D* create(
				Image2D** images,
				uint imageCnt,
				int filter_mag,
				int fileter_min,
				int filter_mipmap,
				int wraps,
				int wrapt,
				int internal_format);

		/* for quick create texture from image */
		static Texture2D* create(Image2D* image);
	public:

		/* fileter */
		void setFilter(int mag,int min,int mip=FILTER_LINEAR);
		int getFilterMin(){return m_filterMin;}
		int getFilterMag(){return m_filterMag;}
		int getFilterMipmap(){return m_filterMipmap;}

		/* wrap */
		void setWrap(int wraps,int wrapt);
		int getWrapS(){return m_wrapS;}
		int getWrapT(){return m_wrapT;}

		/* format */
		int getFormat(){return m_format;}

		/* height,and width */
		uint getWidth(){return m_width;}
		uint getHeight(){return m_height;}

		/* mipmap */
		bool enableMipmap();


	public:
		void bind();

	private:
		Texture2D(){}
		~Texture2D();
	private:
		bool m_useMipmap;

		int m_width;
		int m_height;
		/* format */
		int m_format;
		/* filter */
		int m_filterMin;
		int m_filterMag;
		int m_filterMipmap;
		/* wrap */
		int m_wrapS;
		int m_wrapT;

		/* env */
		PlatformTexture m_platformTexture;
};

NS_FS_END 

#endif /*_FS_TEXTURE_2D_H_*/

