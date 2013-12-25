#include "FsObject.h"
#include "FsGlobal.h"
#include "extends/FsScriptEngine.h"

#include "mgr/FsObjectMgr.h"

NS_FS_BEGIN 

int FsObject::m_objectNu=0;

FsObject::~FsObject()
{
	if(m_objectMgr)
	{
		m_objectMgr->unManageObject(this);
	}

#if FS_CONFIG(FS_SCRIPT_SUPPORT)
	dropScriptData();
#endif 

	FsObject::m_objectNu--;
}

FsObject::FsObject(bool mgred)
	:m_refNu(1),
	m_objectMgr(NULL),

#if FS_CONFIG(FS_SCRIPT_SUPPORT)
	m_scriptData(-1)
#endif 
{
	FsObject::m_objectNu++;
	if(mgred)
	{
		ObjectMgr* mgr=Global::objectMgr();
		if(mgr)
		{
			mgr->manageObject(this);
		}
	}
}


void FsObject::giveObjectMgr(ObjectMgr* mgr)
{
	m_objectMgr=mgr;
}

ObjectMgr* FsObject::takeObjectMgr()
{
	return m_objectMgr;
}


long FsObject::getHashCode() 
{
	return (long)this;
}

bool FsObject::equal(FsObject* ob)
{
	return this==ob;
}

void FsObject::dropData()
{

#if FS_CONFIG(FS_SCRIPT_SUPPORT)
	dropScriptData();
#endif 

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

