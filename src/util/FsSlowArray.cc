#include "util/FsSlowArray.h"

NS_FS_BEGIN
FsSlowArray* FsSlowArray::create()
{
	return new FsSlowArray();
}

const char* FsSlowArray::className() const 
{
	return FS_SLOW_ARRAY_CLASS_NAME;
}


void FsSlowArray::lock()
{
	m_lock=true;
}
void FsSlowArray::unlock()
{
	m_lock=false;
}

void FsSlowArray::flush()
{
	int delete_nu=m_deletes->size();
	int add_nu=m_adds->size();

	for(int i=0;i<delete_nu;i++)
	{
		FsObject* cur=m_deletes->get(i);
		m_items->remove(cur);
		cur->decRef();
	}
	for(int i=0;i<add_nu;i++)
	{
		FsObject* cur=m_adds->get(i);
		m_items->push(cur);
		cur->decRef();
	}
	m_deletes->clear();
	m_adds->clear();
}

void FsSlowArray::push(FsObject* object)
{
	if(m_lock)
	{
		m_adds->push(object);
	}
	else 
	{
		m_items->push(object);
	}
}
void FsSlowArray::remove(FsObject* object)
{
	if(m_lock)
	{
		m_deletes->push(object);
	}
	else 
	{
		m_items->remove(object);
	}
}
int FsSlowArray::size()
{
	return m_items->size();
}

FsSlowArray::FsSlowArray()
{
	init();
}
FsSlowArray::~FsSlowArray()
{
	destroy();
}

void FsSlowArray::init()
{
	m_lock=false;
	m_items=FsArray::create();
	m_deletes=FsArray::create();
	m_adds=FsArray::create();
}

void FsSlowArray::destroy()
{
	m_items->decRef();
	m_deletes->decRef();
	m_adds->decRef();
}

NS_FS_END









