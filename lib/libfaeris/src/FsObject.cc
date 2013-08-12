#include "FsObject.h"
#include "FsGlobal.h"
#include "extends/FsScriptEngine.h"

NS_FS_BEGIN 

FsObject::~FsObject()
{
#if FS_CONFIG(FS_SCRIPT_SUPPORT)
	if(m_scriptData!=-1)
	{
		ScriptEngine* se=Global::scriptEngine();
		if(se!=NULL)
		{
			se->releaseData(m_scriptData);
		}
	}
#endif 
}

long FsObject::getHashCode()
{
	return (long)this;
}

bool FsObject::equal(FsObject* ob)
{
	return this==ob;
}

#if FS_CONFIG(FS_SCRIPT_SUPPORT)
void FsObject::dropScriptData()
{
	if(m_scriptData!=-1)
	{
		ScriptEngine* se=Global::scriptEngine();
		if(se!=NULL)
		{
			se->releaseData(m_scriptData);
		}
		m_scriptData=-1;
	}
}
#endif 

NS_FS_END 

