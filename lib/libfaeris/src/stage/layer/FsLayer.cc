#include "stage/layer/FsLayer.h"
#include "stage/entity/FsEntity.h"
#include "stage/FsScene.h"
#include "support/util/FsDict.h"
#include "support/util/FsSlowDict.h"
#include "mgr/FsObjectMgr.h"

NS_FS_BEGIN
 const char* Layer::className()
{
	return FS_LAYER_CLASS_NAME;
}

int Layer::getEntityNu()
{
	return m_ownerEntity->size();
}

void Layer::add(Entity* entity)
{
	FS_TRACE_WARN_ON(entity==NULL,"Entity Is NULL");
	if(entity->layer()==this)
	{
		FS_TRACE_WARN("object all ready add to this layer");
		return ;
	}

	if(entity->parent()!=NULL)
	{
		FS_TRACE_WARN("object is indirect owner by another layer");
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

	entity->setAddOlder(m_addOlder++);
	m_ownerEntity->insert(entity,entity);
	entity->setLayer(this);

	if(entity->childNu()!=0) /* add child  */
	{
		FsArray* array=entity->takeAllChild();
		int chirld_nu=array->size();
		for(int i=0;i<chirld_nu;i++)
		{
			Entity* child=(Entity*)array->get(i);
			m_ownerEntity->insert(child,child);

			child->setAddOlder(m_addOlder++);
			child->setLayer(this);
		}

		array->decRef();
	}
}


void Layer::dropOwnership(Entity*  entity )
{

	if(entity->childNu()!=0)
	{
		FsArray* array=entity->takeAllChild();
		int child_nu=array->size();
		for(int i=0;i<child_nu;i++)
		{
			Entity* child=(Entity*)array->get(i);
			child->setLayer(NULL);

			m_ownerEntity->remove(child);
		}
		array->decRef();
	}

	entity->setLayer(NULL);
	m_ownerEntity->remove(entity);
}

Layer::Layer()
{
	init();
}

Layer::~Layer()
{
	destruct();
}

void Layer::update(float dt)
{
	updateAction(dt);
	updateEntity(dt);
}

void Layer::updateEntity(float dt)
{
	m_ownerEntity->lock();
	FsDict::Iterator* iter=m_ownerEntity->takeIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		if( entity->visible()&&entity->getLayer()==this) 
		{
			entity->update(dt);
		}
		iter->next();
	}
	delete iter;

	m_ownerEntity->unlock();
	m_ownerEntity->flush();

}


void Layer::draw(Render* render)
{
	updateAllWorldMatrix();
	FsDict::Iterator* iter=m_ownerEntity->takeIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		entity->draw(render,false);
		iter->next();
	}
	delete iter;

}

void Layer::clearEntity()
{
	FsDict::Iterator iter(m_entity);
	while(!iter.done())
	{
		Entity* entity=(Entity*)iter.getValue();
		dropOwnership(entity);
		iter.next();
	}
	m_entity->clear();
}


Scene* Layer::getScene()
{
	return m_scene;
}

void Layer::setScene(Scene* scene)
{
	m_scene=scene;
}




/* scissor */ 
void Layer::setScissorArea(float x,float y,float width,float height)
{
	m_scissorArea.set(x,y,width,height);
}
void Layer::getScissorArea(float* x,float* y,float* width,float* height)
{
	*x=m_scissorArea.x;
	*y=m_scissorArea.y;
	*width=m_scissorArea.width;
	*height=m_scissorArea.height;
}


bool Layer::touchBegin(float x,float y)
{
	return m_touchEnabled;
}
bool Layer::touchMove(float x,float y)
{
	return m_touchEnabled;
}
bool Layer::touchEnd(float x,float y)
{
	return m_touchEnabled; 
}
/* touches event */
bool Layer::touchesBegin(TouchEvent* event)
{
	return m_touchEnabled;
}

bool Layer::touchesPointerDown(TouchEvent* event)
{
	return m_touchEnabled;
}

bool Layer::touchesMove(TouchEvent* event)
{
	return m_touchEnabled;
}

bool Layer::touchesPointerUp(TouchEvent* event)
{
	return m_touchEnabled;
}

bool Layer::touchesEnd(TouchEvent* event)
{
	return m_touchEnabled;
}




void Layer::init()
{
	m_addOlder=0;

	m_entity=FsDict::create();
	FS_NO_REF_DESTROY(m_entity);

	m_ownerEntity=FsSlowDict::create();
	FS_NO_REF_DESTROY(m_ownerEntity);

	m_visible=true;
	m_touchEnabled=false;
	m_scissorEnabled=false;
	m_scissorArea.set(0,0,1,1);
	m_scene=NULL;
}

void Layer::destruct()
{
	clearEntity();

	FS_DESTROY(m_entity);
	FS_DESTROY(m_ownerEntity);

}

void Layer::updateAllWorldMatrix()
{
	FsDict::Iterator iter_entity(m_entity);

	while(!iter_entity.done())
	{
		Entity* entity=(Entity*) iter_entity.getValue();
		entity->updateAllWorldMatrix();
		iter_entity.next();
	}
}

NS_FS_END









