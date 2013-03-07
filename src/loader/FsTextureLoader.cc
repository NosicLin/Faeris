#include <string.h>

#include "util/FsScriptUtil.h"
#include "util/FsDict.h"
#include "image/FsImgDecoder.h"

#include "loader/FsTextureLoader.h"
#include "loader/FsLoaderUtil.h"

#include "io/FsVFS.h"

NS_FS_BEGIN


Texture2D* TextureLoader::create(const char* name)
{
	FsFile* file=VFS::open(name);
	if(file==NULL)
	{
		FS_TRACE_WARN("Open File(%s) For Texture Failed",name);
		return NULL;
	}
	Texture2D* ret=create(file);
	file->decRef();
	return ret;
}
Texture2D* TextureLoader::create(FsFile* file)
{
	int type=LoaderUtil::fileType(file);
	Texture2D* ret=NULL;
	switch(type)
	{
		case FS_FILE_SCRIPT:
			ret=createFromScript(file);
			break;
		case FS_FILE_BINARY:
			ret=createFromBinary(file);
			break;
		default:
			FS_TRACE_WARN("File Is Not Texture2D File Format");
			ret=NULL;
			break;
	}
	return ret;
}

static void s_getFilters(FsDict* dict,int* filter_mag,int* filter_min,int* filter_mipmap)
{
	FsString* sct_mag=ScriptUtil::getString(dict,"filter_mag");
	if(sct_mag!=NULL)
	{
		int filter=LoaderUtil::parseTextureFilter(sct_mag->cstr());
		if(filter!=-1)
		{
			*filter_mag=filter;
		}
		sct_mag->decRef();
	}
	
	FsString* sct_min=ScriptUtil::getString(dict,"filter_min");
	if(sct_min!=NULL)
	{
		int filter=LoaderUtil::parseTextureFilter(sct_min->cstr());
		if(filter!=-1)
		{
			*filter_min=filter;
		}
		sct_min->decRef();
	}

	FsString* sct_mipmap=ScriptUtil::getString(dict,"filter_mipmap");
	if(sct_mipmap!=NULL)
	{
		int filter=LoaderUtil::parseTextureFilter(sct_mipmap->cstr());
		if(filter!=-1)
		{
			*filter_mipmap=filter;
		}
		sct_mipmap->decRef();
	}
}

static void s_getWrap(FsDict* dict,int* wraps,int* wrapt)
{
	FsString* sct_wraps=ScriptUtil::getString(dict,"swap_s");
	if(sct_wraps!=NULL)
	{
		int s=LoaderUtil::parseTextureSwap(sct_wraps->cstr());
		if(s!=-1)
		{
			*wraps=s;
		}
		sct_wraps->decRef();
	}


	FsString* sct_wrapt=ScriptUtil::getString(dict,"swap_t");
	if(sct_wrapt!=NULL)
	{
		const char* str=sct_wrapt->cstr();
		int s=LoaderUtil::parseTextureSwap(sct_wrapt->cstr());
		if(s!=-1)
		{
			*wrapt=s;
		}
		sct_wrapt->decRef();
	}
}




static void s_getAutoMipmap(FsDict* dict,bool* value)
{
	FsString* sct_auto_mipmap=ScriptUtil::getString(dict,"auto_mipmap");
	if(sct_auto_mipmap!=NULL)
	{
		if(strcmp(sct_auto_mipmap->cstr(),"true")==0)
		{
			*value=true;
		}
		else if(strcmp(sct_auto_mipmap->cstr(),"false")==0)
		{
			*value=false;
		}
		sct_auto_mipmap->decRef();
		sct_auto_mipmap=NULL;
	}
}

static void s_getFormat(FsDict* dict,int* format)
{
	FsString* sct_format=ScriptUtil::getString(dict,"format");
	if(sct_format!=NULL)
	{
		int f=LoaderUtil::parseTextureFormat(sct_format->cstr());
		if(f!=-1)
		{
			*format=f;
		}
		sct_format->decRef();
	}
}

static void s_getImageNu(FsDict* dict,int* image_nu)
{
	ScriptUtil::getInteger(dict,"imageNu",image_nu);
}
static void s_getImages(FsDict* dict,Image2D** images,int* image_nu)
{
	FsArray* sct_images=ScriptUtil::getArray(dict,"source");
	if(sct_images==NULL)
	{
		*image_nu=0;
	}

	int num=sct_images->size();
	if(num>*image_nu)
	{
		num=*image_nu;
	}

	int realNum=0;
	for(int i=0;i<num;i++)
	{
		FsString* cur_source=ScriptUtil::getString(sct_images,i);
		if(cur_source==NULL)
		{
			FS_TRACE_WARN("Error Entry(%d) In Source Array",i);
			continue;
		}

		int image_type=FsUtil_ImageType(cur_source->cstr());
		FsFile* file=VFS::open(cur_source->cstr());
		cur_source->decRef();
		cur_source=NULL;

		if(file==NULL)
		{
			FS_TRACE_WARN("Can't Open Image File %s",cur_source->cstr());
			continue;
		}

		Image2D* cur_image=FsUtil_ImageReader(file,image_type);
		file->decRef();

		if(cur_image==NULL)
		{
			FS_TRACE_WARN("Entry(%d) In Source  Array Is Not Image File",i);
			continue;
		}
		images[realNum]=cur_image;
		realNum++;
	}
	*image_nu=realNum;
	sct_images->decRef();
}



Texture2D* TextureLoader::createFromScript(FsFile* file)
{
	Texture2D* ret=NULL;
	FsDict* dict=ScriptUtil::parseScript(file);
	if(dict==NULL)
	{
		return NULL;
	}
	/* filter */
	int filter_mag=Texture2D::FILTER_LINEAR;
	int filter_min=Texture2D::FILTER_LINEAR;
	int filter_mipmap=Texture2D::FILTER_LINEAR;
	
	/* wraps */
	int wraps=Texture2D::WRAP_CLAMP_TO_EDGE;
	int wrapt=Texture2D::WRAP_CLAMP_TO_EDGE;

	/* internal_format */
	int internal_format=Texture2D::FORMAT_RGBA;


	/* mipmap */
	bool mipmap=false;

	/* image */
	uint image_nu=0;
	Image2D** images=NULL;

	s_getFormat(dict,&internal_format);
	s_getFilters(dict,&filter_mag,&filter_min,&filter_mipmap);
	s_getWrap(dict,&wraps,&wrapt);
	s_getAutoMipmap(dict,&mipmap);
	s_getImageNu(dict,(int*)&image_nu);

	if(image_nu==0)
	{
		dict->decRef();
		FS_TRACE_WARN("ImageNu Is Zero, So No Need To Create Texture2D");
		return NULL;
	}
	images=new Image2D* [image_nu];
	memset(images,0,sizeof(Image2D*)*image_nu);

	s_getImages(dict,images,(int*)&image_nu);
	if(image_nu==0)
	{
		delete[] images;
		dict->decRef();
		FS_TRACE_WARN("ImageNu Is Zero, So No Need To Create Texture2D");

	}

	if((image_nu==1)&&!mipmap)
	{
		ret=Texture2D::create(
				images[0],
				filter_mag, 
				filter_min,
				wraps,
				wrapt,
				internal_format
				);
	}
	else 
	{
		ret=Texture2D::create(
				images,
				image_nu,
				filter_mag,
				filter_min,
				filter_mipmap,
				wraps,
				wrapt,
				internal_format
				);
	}

	for(uint i=0;i<image_nu;i++)
	{
		images[i]->decRef();
	}

	dict->decRef();
	delete[] images;
	return ret;

}

Texture2D* TextureLoader::createFromBinary(FsFile* file)
{
	/* TODO(load from binary file )*/
	return NULL;
}

NS_FS_END

