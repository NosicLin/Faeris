#include "scene/FsLayer.h"
#include "entity/FsEntity.h"
#include "util/FsDict.h"


NS_FS_BEGIN
 const char* Layer::className()
{
	return FS_LAYER_CLASS_NAME;
}
void Layer::add(Entity* entity)
{
	if(entity->layer()==this)
	{
		FS_TRACE_WARN("object all ready add to this layer");
		return ;
	}
	if(entity->parent()!=NULL)
	{
		FS_TRACE_WARN("object is indirect owner by another layer ");
		return ;
	}

	m_entity->insert(entity,entity);
	takeOwnership(entity);

}

void Layer::remove(Entity* entity)
{
	if(entity->layer()!=this)
	{
		FS_TRACE_WARN("Object is not Own by this layer");
		return ;
	}
	if(entity->parent()!=NULL)
	{
		FS_TRACE_WARN("object is indirect owner by this layer,can't remove");
	}
	m_entity->remove(entity);
	dropOwnership(entity);
}

void Layer::takeOwnership(Entity* entity)
{
	m_ownerEntity->insert(entity,entity);
	entity->setLayer(this);
	if(entity->childNu()==0) /* no child */
	{
		return;
	}

	FsArray* array=entity->allChild();
	int chirld_nu=array->size();
	for(int i=0;i<chirld_nu;i++)
	{
		Entity* child=(Entity*)array->get(i);
		m_ownerEntity->insert(child,child);
		child->setLayer(this);
		child->decRef();
	}
	array->decRef();
}


void Layer::dropOwnership(Entity*  entity )
{
	m_ownerEntity->remove(entity);
	entity->setLayer(NULL);

	if(entity->childNu()==0)
	{
		return;
	}

	FsArray* array=entity->allChild();
	int child_nu=array->size();
	for(int i=0;i<child_nu;i++)
	{
		Entity* child=(Entity*)array->get(i);
		m_ownerEntity->remove(child);
		child->setLayer(NULL);
		child->decRef();
	}
	array->decRef();
}

Layer::Layer()
{
	init();
}

Layer::~Layer()
{
	destroy();
}

void Layer::update(float dt)
{
	FsDict::Iterator iter(m_ownerEntity);
	while(!iter.done())
	{
		Entity* entity=(Entity*)iter.getValue();
		entity->update(dt);
		entity->decRef();
		iter.next();
	}
}

void Layer::draw(Render* render)
{
	updateAllWorldMatrix();
	FsDict::Iterator iter(m_ownerEntity);
	while(!iter.done())
	{
		Entity* entity=(Entity*)iter.getValue();
		entity->draw(render,false);
		entity->decRef();
		iter.next();
	}

}
bool Layer::touchBegin(float x,float y)
{
	return false;
}
bool Layer::touchMove(float x,float y)
{
	return false;
}
bool Layer::touchEnd(float x,float y)
{
	return false;
}
/* touches event */
bool Layer::touchesBegin(Vector2* points,int num)
{
	return false;
}
bool Layer::touchesMove(Vector2* points,int num)
{
	return false;
}
bool Layer::touchesEnd(Vector2* points,int num)
{
	return false;
}




void Layer::init()
{
	m_entity=FsDict::create();
	m_ownerEntity=FsDict::create();
	m_visible=true;
	m_touchEnabled=false;
}

void Layer::destroy()
{
	FsDict::Iterator iter(m_ownerEntity);
	while(!iter.done())
	{
		Entity* entity=(Entity*)iter.getValue();
		entity->setLayer(NULL);
		entity->decRef();
		iter.next();
	}
	m_entity->decRef();
	m_ownerEntity->decRef();
}

void Layer::updateAllWorldMatrix()
{
	FsDict::Iterator iter_entity(m_entity);

	while(!iter_entity.done())
	{
		Entity* entity=(Entity*) iter_entity.getValue();
		entity->updateAllWorldMatrix();
		entity->decRef();
		iter_entity.next();
	}
}





NS_FS_END








