#ifndef _FS_SCHEDULER_TARGET_H_
#define _FS_SCHEDULER_TARGET_H_

#include "FsMacros.h"
#include "core/FsObject.h"

class SchedulerTarget:public FsObject
{
	public:
		virtual void update(int priority,float dt)=0;

	protected:
		virtual ~SchedulerTarget();
};

#endif /*_FS_SCHEDULER_TARGET_H_*/

