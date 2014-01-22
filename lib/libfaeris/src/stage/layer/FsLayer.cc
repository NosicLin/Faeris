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
	return m_entity->size();
}

void Layer::add(Entity* entity)
{
	FS_TRACE_WARN_ON(entity==NULL,"Entity Is NULL");
	if(entity->getLayer()==this)
	{
		FS_TRACE_WARN("object all ready add to this layer");
		return ;
	}

	if(entity->getParent()!=NULL)
	{
		FS_TRACE_WARN("object is indirect owner by another layer");
		return ;
	}

	m_entity->insert(entity,entity);
	entity->setAddOlder(m_addOlder++);
}


void Layer::remove(Entity* entity)
{
	if(entity->getLayer()!=this)
	{
		FS_TRACE_WARN("Object is not Own by this layer");
		return ;
	}

	if(entity->getParent()!=NULL)
	{
		FS_TRACE_WARN("object is indirect owner by this layer,can't remove");
	}
	entity->setLayer(NULL);
	m_entity->remove(entity);
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
	m_entity->lock();
	FsDict::Iterator* iter=m_entity->takeIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		if(entity->getLayer()==this) 
		{
			entity->updates(dt);
		}
		iter->next();
	}
	delete iter;

	m_entity->unlock();
	m_entity->flush();

}


void Layer::draw(Render* render)
{
	updateAllWorldMatrix();
	FsDict::Iterator* iter=m_entity->takeIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		entity->draws(render,false);
		iter->next();
	}
	delete iter;

}

void Layer::clearEntity()
{
	FsDict::Iterator* iter=m_entity->takeIterator();
	while(!iter->done())
	{
		Entity* entity=(Entity*)iter->getValue();
		entity->setLayer(NULL);
		iter->next();
	}
	m_entity->clear();
	delete iter;
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

	m_entity=FsSlowDict::create();
	FS_NO_REF_DESTROY(m_entity);


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
}

void Layer::updateAllWorldMatrix()
{
	FsDict::Iterator* iter= m_entity->takeIterator();

	while(!iter->done())
	{
		Entity* entity=(Entity*) iter->getValue();
		entity->updateAllWorldMatrix();
		iter->next();
	}
	delete iter;
}

NS_FS_END

