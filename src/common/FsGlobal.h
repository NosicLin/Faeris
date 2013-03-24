#ifndef _FS_GLOBAL_H_
#define _FS_GLOBAL_H_

#include "FsMacros.h"
#include "scheduler/FsScheduler.h"


NS_FS_BEGIN
class Global
{
	public:
		static Scheduler* sheduler();
		static Director* director();
		static Render* render();

};
NS_FS_END 

#endif /*_FS_GLOBAL_H_*/

