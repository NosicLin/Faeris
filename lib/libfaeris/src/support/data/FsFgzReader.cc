#include "support/data/FsFgzReader.h"

static char _FgzGLobalMagicNu[8]=FS_FGZ_MAGIC_NU;
static char _FgzFileMagicNu[8]=FS_FGZ_FILE_MAGIC_NU;


typedef struct  
{
	uint8_t 	m_magicNu[8]; 
	uint32_t 	m_fileNu;
	uint32_t	m_offset;

}FgzGlobalHeader;


typedef struct 
{
	uint8_t  m_magicNu[8];
	uint32_t m_method;
	uint32_t m_unsize;
	uint32_t m_ensize;
	uint32_t m_crc32;
	uint32_t m_filenameLength;
}FgzFileHeader;



class FgzFileInfo:public FsObject
{
	public:
		FgzFileInfo()
		{
			m_filename=NULL;
		}

		virtual ~FgzFileInfo()
		{
			FS_SAFE_DEC_REF(m_filename);
		}

		virtual const char* className()
		{
			return "FgzFileInfo";
		}

	public:
		void setFileName(const char* name)
		{
			FsString* str=FsString::create(name);
			FS_SAFE_ASSIGN(m_filename,str);
			str->decRef();
		}
		void setOffset(uint32_t offset)
		{
			m_dataOffset=offset;
		}

	public:
		FsString* m_filename;
		FgzFileHeader m_header;
		uint32_t m_dataOffset;
};


FgzReader* FgzReader::create(FsFile* file)
{
	FgzReader* ret=new FgzReader();
	if(!ret->init(file))
	{
		delete ret;
		ret=NULL;
	}
	return ret;
}




FsFile* FgzReader::getFile(const char* filename)
{
	FgzFileInfo* info=(FgzFileInfo*)m_files->lookup(filename);
	FsFile* ret=NULL;

	if(info==NULL)
	{
		FS_TRACE_INFO("Can't Find File(%s) In FgzPackage",filename);
		info->decRef();
		return NULL;
	}

	if(info->m_header.m_method==FS_FGZ_STORE)
	{
		ret=SegFile::create(
				m_stream,
				info.m_dataOffset,
				info.m_header.m_unsize);

	}
	else if(info->m_header.m_method==FS_FGZ_DEFLATE)
	{
		int file_size=info->m_header.m_unsize;
		ret=MemFile::create(file_size);
		char* buffer=(char*) ret->getInternalBuffer();
		char* compress_buf=new char[info->m_header.m_ensize];

		m_stream->seek(info->m_dataOffset);
		m_stream->read(compress_buf,info->m_header.m_ensize);

		FsDeflate_UnCompress(
				compress_buf,
				info->m_header.m_ensize,
				buffer,
				file_size);

		delete[] compress_buf;
		compress_buf=NULL;
	}
	else 
	{
		FS_TRACE_WARN("UnSupport Compress Method");
	}

	info->decRef();
	return ret;
}

const char* FgzReader::className()
{
	return "FgzReader";
}

FgzReader::FgzReader()
{
	m_files=NULL;
	m_stream=NULL;
}

FgzReader::~FgzReader()
{
	destroy();
}

bool FgzReader::init(FsFile* file)
{
	FgzGlobalHeader g_header;
	int i,file_nu=0,file_pos=0;
	FsDict* fileset=FsDict::create();

	int file_name_length;
	char* name_buf=NULL;




	int ret=file->seek(0,FsFile::FS_SEEK_SET);
	if(ret<0)
	{
		goto error;
	}

	/* read global header */
	ret=file->read(&g_header,sizeof(g_header));
	if(ret!=sizeof(g_header))
	{
		FS_TRACE_WARN("Can't Read Global Header Info For FgzPackage");
		goto error;
	}

	if(memcmp(&g_header.m_magicNu,_FgzGLobalMagicNu,8)!=0)
	{
		FS_TRACE_WARN("File Is Not FgzPackage");
		goto error;
	}

	file_nu=g_header.m_fileNu;
	ret=file->seek(g_header.m_offset,FsFile::FS_SEEK_SET);
	if(ret<0)
	{
		FS_TRACE_WARN("Seek Error");
		goto error;
	}

	for(i=0;i<file_nu;i++)
	{
		FgzFileInfo* info=new FgzFileInfo();

		ret=file->read(&info->m_header,sizeof(info->m_header));
		if(ret!=sizeof(info->m_header))
		{
			FS_TRACE_WARN("FgzPackage Damaged");
			info->decRef();
			goto error;
		}
		if(memcmp(info->m_header,_FgzFileMagicNu,8)!=0)
		{
			FS_TRACE_WARN("FgzPackage Damaged");
			info->decRef();
			goto error;
		}

		file_name_length=info->m_header.m_filenameLength;
		name_buf=new char[file_name_length+1];
		ret=file->read(name_buf,file_name_length);

		if(ret!=file_name_length)
		{
			delete[] name_buf;
			info->decRef();
			goto error;
		}
		name_buf[file_name_length]='\0';

		info->setFileName(name_buf);
		delete[] name_buf;

		file_pos=file->tell();
		info->setOffset(file_pos);

		fileset->insert(info->m_filename,info);
	}

	file->addRef();
	m_stream=file;
	m_files=fileset;

	return true;

error:
	fileset->decRef();
	return false;
}

void FgzReader::destroy()
{
	FS_SAFE_DEC_REF(m_files);
	FS_SAFE_DEC_REF(m_stream);
}
























