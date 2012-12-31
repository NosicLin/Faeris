#include "FsStringUtil.h"

NS_FS_BEGIN
FsUlong StringUtil::JHashCode(const char* str)
{
	FsUlong hash = 1315423911;
	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}
	return hash ;
}
NS_FS_END

