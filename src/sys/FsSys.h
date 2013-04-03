#ifndef _FAERIS_SYS_H_
#define _FAERIS_SYS_H_
#include <string>
#include "FsMacros.h"

NS_FS_BEGIN
class Sys
{
	public:
		static void usleep(long time);
		static std::string currentDir();
};
NS_FS_END
#endif /*_FAERIS_SYS_H_*/

