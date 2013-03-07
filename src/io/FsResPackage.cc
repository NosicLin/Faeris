#include "io/FsResPackage.h"
#include "io/FsFile.h"

NS_FS_BEGIN
#define FS_RES_PACKAGE_VERSION 0x1
static const uint8_t kResPackageID[16]={
	0,   0,  0,  'R', 'e','s','P','a',
	'c', 'k', 'a','g','e',  0,  0, 0,
};

struct ResFileHeader 
{
	char m_magicId[16];
	int32_t m_version;
	uint32_t m_fileNu;
	uint32_t m_fileInfoOffset;
};

ResPackage::ResPackage()
{
	m_fileInfos=NULL;
	m_packFile=NULL;
}

bool ResPackage::init(FsFile* file)
{
	struct ResFileHeader header;
	int readbyte;
	readbyte=file->read(&header,sizeof(header));
	if(readbyte<sizeof(header))
	{
		FS_TRACE_WARN("File Is Not ResPackage File Format:At Least Expect %d Bytes Header,But Only %d Bytes",sizeof(header),readbyte);
		goto error;
	}
	if(memcpy(header.m_magicId,kResPackageID,16)!=0)
	{
		FS_TRACE_WARN("File IS not ResPackage File Format:Error MagicId");
		goto error;
	}
	if(header.m_version!=FS_RES_PACKAGE_VERSION)
	{
		FS_TRACE_WARN("ResPackage File Version Is Not Support");
		goto error;
	}
error:
	return false;
}






NS_FS_END




