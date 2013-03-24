#include "scene/FsLayer.h"
#include "entity/FsEntity.h"
#include "util/FsDict.h"


NS_FS_BEGIN
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

NS_FS_END









