#ifndef _FS_SCRIPT_ENGINE_H_
#define _FS_SCRIPT_ENGINE_H_

#include "FsMacros.h"
#include "core/FsObject.h"
NS_FS_BEGIN

class ScriptEngine:public FsObject
{
	public:
		virtual void releaseData(int data)=0;
		virtual ~ScriptEngine();
};

NS_FS_END 


#endif /*_FS_SCRIPT_ENGINE_H_*/

