#include "mgr/FsObjectMgr.h"
#include "support/util/FsArray.h"
NS_FS_BEGIN


const char* ObjectMgr::className()
{
	return FS_OBJECT_MGR_CLASS_NAME;
}

ObjectMgr::ObjectMgr()
{

}

ObjectMgr::~ObjectMgr()
{
	unManageAllObject();
}

bool ObjectMgr::init()
{
	return true;
}






ObjectMgr* ObjectMgr::create()
{
	ObjectMgr* ret=new ObjectMgr();
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	return ret;
}

void ObjectMgr::manageObject(FsObject* ob)
{

	ObjectMgr* pre_mgr=ob->takeObjectMgr();

	if(pre_mgr==this)
	{
		return;
	}

	if(pre_mgr) 
	{
		pre_mgr->unManageObject(ob);
	}

	ob->giveObjectMgr(this);
	m_mgr.insert(ob);
}


void ObjectMgr::unManageObject(FsObject* ob) 
{
	if(ob->takeObjectMgr()!=this)
	{
		FS_TRACE_WARN("Object Is Not Manage By This ObjectMgr");
		return;
	}
	assert(m_mgr.find(ob)!=m_mgr.end());
	m_mgr.erase(ob);
	ob->giveObjectMgr(NULL);
}


void ObjectMgr::dropObjectData()
{
	FsArray* obs=FsArray::create();
	for (MgrSet::iterator iter=m_mgr.begin();iter!=m_mgr.end();++iter)
	{
		obs->push(*iter);
		(*iter)->giveObjectMgr(NULL);
	}

	m_mgr.clear();
	int size=obs->size();
	for( int i=0;i<size;i++)
	{
		FsObject* o=obs->get(i);
		o->dropData();
		o->decRef();
	}
	obs->decRef();
}

void ObjectMgr::unManageAllObject()
{
	for(MgrSet::iterator iter=m_mgr.begin();iter!=m_mgr.end();++iter)
	{
		(*iter)->giveObjectMgr(NULL);
	}
	m_mgr.clear();
}


int ObjectMgr::getManageObjectNu()
{
	return m_mgr.size();
}






NS_FS_END















