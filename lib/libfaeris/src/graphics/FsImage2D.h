#ifndef _FAERIS_IMAGE2D_H_
#define _FAERIS_IMAGE2D_H_
#include "FsMacros.h"
#include "FsObject.h"
#include "graphics/FsColor.h"
NS_FS_BEGIN
class Image2D:public FsObject
{
	public:
		enum PixelFormat
		{
			PIXEL_UNKOWN=0,
			PIXEL_RGB888,
			PIXEL_RGBA8888,
			PIXEL_GRAY8,
		};

		enum ImageType
		{
			IMAGE_UNKWON=0,
			IMAGE_PNG,
			IMAGE_JEPG,
			IMAGE_TGA,
			IMAGE_BMP,
		};
	public:
		static Image2D* create(const char* filename,ImageType format=IMAGE_UNKWON);
		static Image2D* create(uint width,uint height,PixelFormat format);
		static Image2D* create(uint width,uint height,void* data,PixelFormat format);
		static uint PixelFormatSize(PixelFormat f);


	public:
		uint getWidth()const{return m_width;} 
        uint getHeight()const{return m_height;}
		void* getPixelData()const{return m_buffer;}
		PixelFormat getPixelFormat()const{return m_format;}
		Color getColor(uint x,uint y)const;
		void setColor(uint x,uint y,Color c);

		/* overide FsObject */
		virtual const char* className();

	protected:
		Image2D();
		virtual ~Image2D();
		void init(uint width,uint height,PixelFormat format);
		void init(uint width,uint height,void* data,PixelFormat format);
		void destruct();

	private:
		uint m_pixel_bytes;
		uint m_width;
		uint m_height;
		PixelFormat m_format;
		uint8_t* m_buffer;
};
NS_FS_END
#endif /* _FAERIS_IMAGE2D_H_*/





