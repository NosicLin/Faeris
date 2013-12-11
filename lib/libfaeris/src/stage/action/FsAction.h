#ifndef _FS_ACTION_H_
#define _FS_ACTION_H_

#include "FsMacros.h"
#include "FsObject.h"


NS_FS_BEGIN

class StageElement;

class Action:public FsObject
{
	public:
		virtual bool run(StageElement* target,float dt)=0;
		const char* className();

};

NS_FS_END 

#endif /*_FS_ACTION_H_*/

