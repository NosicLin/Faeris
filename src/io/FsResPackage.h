#ifndef _FS_RES_PACKAGE_H_
#define _FS_RES_PACKAGE_H_
#include "FsMacros.h"
#include "io/FsPackage.h"

NS_FS_BEGIN
class FsDict;
class ResPackage:public Package
{
	protected:
		class ResFileInfo:public FsObject
		{
			public:
				ResFileInfo(int compress_type,
						    int real_size,
							int packed_size,
							int offset);
			public:
				int m_compressMethod;
				int m_realSize;
				int m_packedSize;
				int m_offset;
		};
	public:
		static ResPackage* create(const char* name);
		static ResPackage* create(FsFile* file);
	public:
		virtual FsFile* getBlock(const char* name);
		virtual ~ResPackage();
	protected:
		ResPackage();
		bool init(FsFile* file);
	private:
		FsDict* m_fileInfos;
		FsFile* m_packFile;
};

NS_FS_END 

#endif /*_FS_RES_PACKAGE_H_*/




