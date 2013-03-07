#ifndef _FAERY_TYPES_H_
#define _FAERY_TYPES_H_

#include "FsConfig.h"
#if FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "c99/stdint.h"
#else 
	#include <stdint.h>
#endif 
typedef unsigned long ulong;
typedef unsigned int uint;


#endif  /*_FAERY_TYPES_H_*/

