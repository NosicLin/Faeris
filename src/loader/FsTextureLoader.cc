#include <string.h>

#include "util/FsScriptUtil.h"
#include "util/FsDict.h"
#include "loader/FsTextureLoader.h"
#include "util/FsImgDecoder.h"
#include "fsys/FsVFS.h"

NS_FS_BEGIN
Texture2D* TextureLoader::loadFromFile(FsFile* file)
{
	FsInt type=checkFileType(file);
	Texture2D* ret=NULL;
	switch(type)
	{
		case FS_FILE_SCRIPT:
			ret=loadFromScriptFile(file);
			break;
		case FS_FILE_BINARY:
			ret=loadFromBinaryFile(file);
			break;
		default:
			FS_TRACE_WARN("File Is Not Texture2D File Format");
			ret=NULL;
			break;
	}
	return ret;
}

static void s_getFilters(FsDict* dict,FsInt* filter_mag,FsInt* filter_min,FsInt* filter_mipmap)
{
	FsString* sct_mag=ScriptUtil::getString(dict,"filter_mag");
	if(sct_mag!=NULL)
	{
		if(strcmp(sct_mag->cstr(),"linear")==0)
		{
			*filter_mag=Texture2D::FILTER_LINEAR;
		}
		else if(strcmp(sct_mag->cstr(),"nearest")==0)
		{
			*filter_mag=Texture2D::FILTER_NEAREST;
		}
		sct_mag->decRef();
		sct_mag=NULL;
	}
	
	FsString* sct_min=ScriptUtil::getString(dict,"filter_mip");
	if(sct_min!=NULL)
	{
		if(strcmp(sct_min->cstr(),"linear")==0)
		{
			*filter_min=Texture2D::FILTER_LINEAR;
		}
		else if(strcmp(sct_min->cstr(),"nearest")==0)
		{
			*filter_min=Texture2D::FILTER_NEAREST;
		}
		sct_min->decRef();
		sct_min=NULL;
	}

	FsString* sct_mipmap=ScriptUtil::getString(dict,"filter_mipmap");
	if(sct_mipmap!=NULL)
	{
		if(strcmp(sct_mipmap->cstr(),"linear")==0)
		{
			*filter_mipmap=Texture2D::FILTER_LINEAR;
		}
		else if(strcmp(sct_mipmap->cstr(),"nearest")==0)
		{
			*filter_mipmap=Texture2D::FILTER_NEAREST;
		}
		sct_mipmap->decRef();
		sct_mipmap=NULL;
	}
}

static FsVoid s_getWrap(FsDict* dict,FsInt* wraps,FsInt* wrapt)
{
	FsString* sct_wraps=ScriptUtil::getString(dict,"swap_s");
	if(sct_wraps!=NULL)
	{
		const char* str=sct_wraps->cstr();
		FsInt* target=wraps;

		if(strcmp(str,"clamp_to_edge")==0)
		{
			*target=Texture2D::WRAP_CLAMP_TO_EDGE;
		}
		else if(strcmp(str,"repeat")==0)
		{
			*target=Texture2D::WRAP_REPEAT;
		}
		else if(strcmp(str,"clamp")==0)
		{
			*target=Texture2D::WRAP_CLAMP;
		}

		sct_wraps->decRef();
		sct_wraps=NULL;
	}


	FsString* sct_wrapt=ScriptUtil::getString(dict,"swap_t");
	if(sct_wrapt!=NULL)
	{
		const char* str=sct_wrapt->cstr();
		FsInt* target=wrapt;

		if(strcmp(str,"clamp_to_edge")==0)
		{
			*target=Texture2D::WRAP_CLAMP_TO_EDGE;
		}
		else if(strcmp(str,"repeat")==0)
		{
			*target=Texture2D::WRAP_REPEAT;
		}
		else if(strcmp(str,"clamp")==0)
		{
			*target=Texture2D::WRAP_CLAMP;
		}
		sct_wrapt->decRef();
		sct_wrapt=NULL;
	}
}

static FsVoid s_getAutoMipmap(FsDict* dict,FsBool* value)
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
static FsVoid s_getEnvMode(FsDict* dict,FsInt* env_mode)
{
	FsString* sct_evn_mode=ScriptUtil::getString(dict,"env_mode");
	if(sct_evn_mode!=NULL)
	{
		const FsChar* str=sct_evn_mode->cstr();
		if(strcmp(str,"replace")==0)
		{
			*env_mode=Texture2D::ENV_REPLEACE;
		}
		else if(strcmp(str,"decal")==0)
		{
			*env_mode=Texture2D::ENV_DECAL;
		}
		else if(strcmp(str,"modulate")==0)
		{
			*env_mode=Texture2D::ENV_MODULATE;
		}
		else if(strcmp(str,"blend")==0)
		{
			*env_mode=Texture2D::ENV_BLEND;
		}
		else if(strcmp(str,"add")==0)
		{
			*env_mode=Texture2D::ENV_ADD;
		}
		else if(strcmp(str,"combine")==0)
		{
			*env_mode=Texture2D::ENV_COMBINE;
		}
		sct_evn_mode->decRef();
		sct_evn_mode=NULL;
	}
}
static FsVoid s_getImageNu(FsDict* dict,FsInt* image_nu)
{
	ScriptUtil::getInteger(dict,"imageNu",image_nu);
}
static FsVoid s_getImages(FsDict* dict,Image2D** images,FsInt* image_nu)
{
	FsArray* sct_images=ScriptUtil::getArray(dict,"source");
	if(sct_images==NULL)
	{
		*image_nu=0;
	}

	FsInt num=sct_images->size();
	if(num>*image_nu)
	{
		num=*image_nu;
	}

	FsInt realNum=0;
	for(FsInt i=0;i<num;i++)
	{
		FsString* cur_source=ScriptUtil::getString(sct_images,i);
		if(cur_source==NULL)
		{
			FS_TRACE_WARN("Error Entry(%d) In Source Array",i);
			continue;
		}

		FsInt image_type=FsUtil_ImageType(cur_source->cstr());
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
		images[realNum++]=cur_image;
	}
	*image_nu=realNum;
}



Texture2D* TextureLoader::loadFromScriptFile(FsFile* file)
{
	Texture2D* ret=NULL;
	FsDict* dict=ScriptUtil::parseScript(file);
	if(dict==NULL)
	{
		return NULL;
	}
	/* filter */
	FsInt filter_mag=Texture2D::FILTER_LINEAR;
	FsInt filter_min=Texture2D::FILTER_LINEAR;
	FsInt filter_mipmap=Texture2D::FILTER_LINEAR;
	
	/* wraps */
	FsInt wraps=Texture2D::WRAP_CLAMP_TO_EDGE;
	FsInt wrapt=Texture2D::WRAP_CLAMP_TO_EDGE;

	/* internal_format */
	FsInt internal_format=Texture2D::FORMAT_RGBA;

	/* env_mode */
	FsInt env_mode=Texture2D::ENV_REPLEACE;

	/* mipmap */
	FsBool mipmap=false;

	/* image */
	FsUint image_nu;
	Image2D** images=NULL;

	s_getFilters(dict,&filter_mag,&filter_min,&filter_mipmap);
	s_getWrap(dict,&wraps,&wrapt);
	s_getAutoMipmap(dict,&mipmap);
	s_getImageNu(dict,(FsInt*)&image_nu);
	s_getEnvMode(dict,&env_mode);
	if(image_nu==0)
	{
		FS_TRACE_WARN("ImageNu Is Zero, So No Need To Create Texture2D");
		return NULL;
	}
	images=new Image2D* [image_nu];
	memset(images,0,sizeof(Image2D*)*image_nu);

	s_getImages(dict,images,(FsInt*)&image_nu);

	if(image_nu==1)
	{
		ret=Texture2D::create(images[0],
				filter_mag, filter_min,
				wraps,wrapt,
				internal_format,
				env_mode,
				mipmap);
	}
	else 
	{

		ret=Texture2D::create(images,
				image_nu,
				filter_mag,
				filter_min,
				filter_mipmap,
				wraps,
				wrapt,
				internal_format,
				env_mode);
	}
	for(FsUint i=0;i<image_nu;i++)
	{
		images[i]->decRef();
	}
	delete images;
	return ret;

}

Texture2D* TextureLoader::loadFromBinaryFile(FsFile* file)
{
	/* TODO(load from binary file )*/
	return NULL;
}

FsInt TextureLoader::checkFileType(FsFile* file)
{
	/*TODO(Add Type CheckHere)*/
	return FS_FILE_SCRIPT;
}
NS_FS_END

