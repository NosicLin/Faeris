#include "FsObject.h"
#include "FsGlobal.h"
#include "extends/FsScriptEngine.h"

NS_FS_BEGIN 

int FsObject::m_objectNu=0;

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
	FsObject::m_objectNu--;
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

