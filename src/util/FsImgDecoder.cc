#include <string.h>

#include "util/FsImgDecoder.h"
#include "graphics/FsImage2D.h"

NS_FS_BEGIN
FsInt FsUtil_ImageType(const FsChar* name)
{
	FsUint str_len=strlen(name);
	if(str_len<=5)  /*  *.jpg, *.png, *.bmp *.tga */
	{
		return Image2D::IMAGE_UNKWON;
	}

	const FsChar* ext=name+str_len-4;
	if(strcmp(ext,".jpg")==0)
	{
		return Image2D::IMAGE_JEPG;
	}
	else if(strcmp(ext,".png")==0)
	{
		return Image2D::IMAGE_PNG;
	}
	else if(strcmp(ext,".bmp")==0)
	{
		return Image2D::IMAGE_BMP;
	}
	else if(strcmp(ext,".tga")==0)
	{
		return Image2D::IMAGE_TGA;
	}

	if(str_len<=6)   /* *.jpeg */
	{
		return Image2D::IMAGE_UNKWON;
	}

	ext=name+str_len-5;
	if(strcmp(ext,".jpeg")==0)
	{
		return Image2D::IMAGE_JEPG;
	}

	return Image2D::IMAGE_UNKWON;
}

Image2D* FsUtil_ImageReader(FsFile* file,FsInt image_type)
{
	switch(image_type)
	{
		case Image2D::IMAGE_JEPG:
			/* TODO (add jpeg decoder here)*/
			return NULL;
		case Image2D::IMAGE_PNG:
			return FsUtil_PngReader(file);
		case Image2D::IMAGE_BMP:
			/*TODO add Bitmap Reader hear */
			//	return FsUtil_BmpReader(file);
			return NULL;
		default:
			FS_TRACE_WARN("Image Type Is Not Support");
			return NULL;
	}

}
NS_FS_END
