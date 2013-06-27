#ifndef _FS_TASK_H_
#define _FS_TASK_H_
#include "FsMacros.h"
#include "core/FsObject.h"

NS_FS_BEGIN
class Task:public FsObject 
{
	public:
		virtual void run()=0;
};
NS_FS_END


#endif /*_FS_TASK_H_ */


