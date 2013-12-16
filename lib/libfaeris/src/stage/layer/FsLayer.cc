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

	if(m_scene)
	{
		entity->giveScene(m_scene);
	
	}


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

		child->setAddOlder(m_addOlder++);
		child->setLayer(this);

		if(m_scene)
		{
			child->giveScene(m_scene);
		}

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
	updateAction(dt);
	updateEntity(dt);
}

void Layer::updateEntity(float dt)
{
	m_ownerEntity->lock();
	FsDict::Iterator* iter=m_ownerEntity->getIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		if( entity->visible()) 
		{
			entity->update(dt);
		}
		entity->decRef();
		iter->next();
	}
	delete iter;
	m_ownerEntity->unlock();
	m_ownerEntity->flush();

}


void Layer::draw(Render* render)
{
	updateAllWorldMatrix();
	FsDict::Iterator* iter=m_ownerEntity->getIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		entity->draw(render,false);
		entity->decRef();
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
		entity->decRef();
		iter.next();
	}
	m_entity->clear();
}

Scene* Layer::getScene()
{
	FS_SAFE_ADD_REF(m_scene);
	return m_scene;
}

Scene* Layer::takeScene()
{
	return m_scene;
}

void Layer::giveScene(Scene* scene)
{
	if(scene)
	{
		ActionTarget::giveScene(scene);
		FsDict::Iterator* iter=m_ownerEntity->getIterator();
		while(!iter->done())
		{
			Entity* entity=(Entity*)iter->getValue();
			entity->giveScene(scene);
			entity->decRef();
			iter->next();
		}
		delete iter;
	}

	m_scene=scene;
}


void Layer::dropData()
{
	FsDict::Iterator iter(m_entity);

	while(!iter.done())
	{
		Entity* entity=(Entity*)iter.getValue();
		dropOwnership(entity);
		entity->decRef();
		iter.next();
	}

	m_entity->clear();

	ActionTarget::dropData();

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
	m_ownerEntity=FsSlowDict::create();
	assert(m_entity);
	assert(m_ownerEntity);
	m_visible=true;
	m_touchEnabled=false;
	m_scissorEnabled=false;
	m_scissorArea.set(0,0,1,1);
	m_scene=NULL;
}

void Layer::destroy()
{
	FsDict::Iterator* iter=m_ownerEntity->getIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		entity->setLayer(NULL);
		entity->decRef();
		iter->next();
	}
	m_entity->decRef();
	m_ownerEntity->decRef();
	delete iter;
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









