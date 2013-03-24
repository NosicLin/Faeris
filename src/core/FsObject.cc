#include "core/FsObject.h"
#include "common/FsGlobal.h"
#include "common/FsScriptEngine.h"

NS_FS_BEGIN 

FsObject::~FsObject()
{
	if(m_data!=-1)
	{
		ScriptEngine* se=Global::scriptEngine();
		if(se!=NULL)
		{
			se->releaseData(m_data);
		}
	}
}

long FsObject::getHashCode()
{
	return (long)this;
}

bool FsObject::equal(FsObject* ob)
{
	return this==ob;
}
NS_FS_END 

