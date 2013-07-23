#include <stdlib.h>
#include <string.h>

#include "unzip.h"
#include "io/FsFile.h"
#include "io/FsZipPackage.h"
#include "io/FsMemFile.h"

NS_FS_BEGIN

class ZipPackageInternal 
{
	public:
		static ZipPackageInternal* create(FsFile* file);

	public:
		FsFile* getBlock(const char* file);

	public:
		ZipPackageInternal();
		~ZipPackageInternal();
	protected:
		bool init(FsFile* file);
	private:
		zlib_filefunc_def* m_filefunc;
		unzFile m_unzfile;
};

ZipPackageInternal* ZipPackageInternal::create(FsFile* file)
{
	ZipPackageInternal* ret=new ZipPackageInternal();
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

FsFile* ZipPackageInternal::getBlock(const char* file_name)
{
	if(unzLocateFile(m_unzfile,file_name,true)!=UNZ_OK)
	{
		FS_TRACE_WARN("File(%s) Not Found Int Zip Package",file_name);
		return NULL;
	}

	if(unzOpenCurrentFile(m_unzfile)!=UNZ_OK)
	{
		FS_TRACE_WARN("Open Current File Failed");
		return NULL;
	}


	char file_path[256];
	unz_file_info file_info;

	if(unzGetCurrentFileInfo(m_unzfile,&file_info,file_path,sizeof(file_path),NULL,0,NULL,0)!=UNZ_OK)
	{
		FS_TRACE_WARN("Get Current File Failed");
		unzCloseCurrentFile(m_unzfile);
		return NULL;
	}

	int file_size=file_info.uncompressed_size;
	MemFile* ret=MemFile::create(file_size);
	char* buffer=(char*)ret->getInternalBuffer();

	int read_byte=unzReadCurrentFile(m_unzfile,buffer,file_size);

	if(read_byte!=file_size)
	{
		FS_TRACE_WARN("Can't Read Full Size Of File");
		ret->decRef();
		unzCloseCurrentFile(m_unzfile);
		return NULL;
	}
	unzCloseCurrentFile(m_unzfile);
	return ret;

}

ZipPackageInternal::ZipPackageInternal()
{
	m_filefunc=NULL;
	m_unzfile=NULL;
}

ZipPackageInternal::~ZipPackageInternal()
{
	if(m_unzfile)
	{
		unzClose(m_unzfile);
	}
	if(m_filefunc)
	{
		free(m_filefunc);
	}
}

bool ZipPackageInternal::init(FsFile* file)
{
	zlib_filefunc_def*  func=zip_package_create_filefunc(file);
	unzFile ret=unzOpen2(NULL,func);
	if(ret==NULL)
	{
		free(func);
		return false;
	}
	m_filefunc=func;
	m_unzfile=ret;
	return true;
}

ZipPackage* ZipPackage::create(FsFile* file)
{
	ZipPackage* ret=new ZipPackage;
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

FsFile* ZipPackage::getBlock(const char* filename)
{
	return m_imp->getBlock(filename);
}

const char* ZipPackage::className()
{
	return FS_ZIP_PACKAGE_CLASS_NAME;
}

bool ZipPackage::init(FsFile* file)
{
	m_imp=ZipPackageInternal::create(file);
	if(m_imp==NULL)
	{
		return false;
	}
	file->addRef();
	m_stream=file;
	return true;
}
ZipPackage::ZipPackage()
{
	m_imp=NULL;
	m_stream=NULL;
}

ZipPackage::~ZipPackage()
{
	if(m_imp)
	{
		delete m_imp;
	}
	if(m_stream)
	{
		m_stream->decRef();
	}
}










NS_FS_END







































