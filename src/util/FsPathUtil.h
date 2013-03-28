#ifndef _FS_PATH_UTIL_H_
#define _FS_PATH_UTIL_H_
#include "FsMacros.h"

NS_FS_BEGIN
class  PathUtil 
{
	public:
		static bool absolutePath(const char* name);
};

NS_FS_END 

#endif /*_FS_PATH_UTIL_H_*/

