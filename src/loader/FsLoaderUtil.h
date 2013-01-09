#ifndef _FS_LOADER_UTIL_H_
#define _FS_LOADER_UITL_H_ 
#include "FsMacros.h"

NS_FS_BEGIN
class LoaderUtil
{
	public:
		static FsInt fileType(FsFile* file){return FS_FTYPE_SCRIPT;}
};
NS_FS_END

#endif /*_FS_LOADER_UTIL_H_*/

