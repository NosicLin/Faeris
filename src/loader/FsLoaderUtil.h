#ifndef _FS_LOADER_UTIL_H_
#define _FS_LOADER_UITL_H_ 
#include "FsMacros.h"

NS_FS_BEGIN
class FsFile;
class LoaderUtil
{
	public:
		static FsInt fileType(FsFile* file){return FS_FTYPE_SCRIPT;}
		static FsInt parseFsType(const FsChar* t);
		static FsInt parseUniformType(const FsChar* t);
};
NS_FS_END

#endif /*_FS_LOADER_UTIL_H_*/

