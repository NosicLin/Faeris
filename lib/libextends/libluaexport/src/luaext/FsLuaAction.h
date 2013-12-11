#ifndef _FS_LUA_ACTION_H_
#define _FS_LUA_ACTION_H_

#include "stage/action/FsAction.h"

NS_FS_BEGIN

class LuaAction:public Action 
{
	public:
		static LuaAction* create();
	public:
		virtual bool run(StageElement* target,float dt);
		virtual const char* className();


};
NS_FS_END



#endif /*_FS_LUA_ACTION_H_*/

