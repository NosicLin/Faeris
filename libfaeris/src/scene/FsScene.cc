#include "scene/FsScene.h"
#include "scene/FsLayer.h"
#include "util/FsSlowArray.h"
NS_FS_BEGIN

Scene* Scene::create()
{
	Scene* ret=new Scene;
	return ret;
}

/* layer operation */
void Scene::push(Layer* layer)
{
	m_layers->push(layer);
}

void Scene::pop()
{
	m_layers->pop();
}

void Scene::insert(int pos,Layer* layer)
{
	m_layers->insert(pos,layer);
}
void Scene::replace(int pos,Layer* layer)
{
	m_layers->set(pos,layer);
}

void Scene::remove(Layer* layer)
{
	m_layers->remove(layer);
}

Layer* Scene::top()
{
	return (Layer*)m_layers->top();
}

int Scene::layerNu()
{
	return m_layers->size();
}

Layer* Scene::getLayer(int index)
{
	return (Layer*)m_layers->get(index);
}


/* event */

void Scene::enter()
{
	/* do nothing */
}
void Scene::exit()
{
	/* do nothing */
}

void Scene::update(float dt)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->visible())
		{
			layer->update(dt);
		}
		layer->decRef();
	}
	m_layers->unlock();
	m_layers->flush();
}
void Scene::draw(Render* render)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=0;i<layer_nu;i++)
	{
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->visible())
		{
			layer->draw(render);
		}
		layer->decRef();
	}
	m_layers->unlock();
	m_layers->flush();
}
void Scene::touchBegin(float x,float y)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->visible())
		{
			handle=layer->touchBegin(x,y);
		}
		layer->decRef();
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}
void Scene::touchMove(float x,float y)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->visible())
		{
			handle=layer->touchMove(x,y);
		}
		layer->decRef();
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}

void Scene::touchEnd(float x,float y)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->visible())
		{
			handle=layer->touchEnd(x,y);
		}
		layer->decRef();
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}

void Scene::touchesBegin(Vector2* points,int num)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->visible())
		{
			handle=layer->touchesBegin(points,num);
		}
		layer->decRef();
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}
void Scene::touchesMove(Vector2* points,int num)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->visible())
		{
			handle=layer->touchesMove(points,num);
		}
		layer->decRef();
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}
void Scene::touchesEnd(Vector2* points,int num)
{
	m_layers->lock();
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		bool handle=false;
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->touchEnabled()&&layer->visible())
		{
			handle=layer->touchesEnd(points,num);
		}
		layer->decRef();
		if(handle)
		{
			break;
		}
	}
	m_layers->unlock();
	m_layers->flush();
}



const char* Scene::className()
{
	return FS_SCENE_CLASS_NAME;
}

Scene::Scene()
{
	init();
}
Scene::~Scene()
{
	destroy();
}

void Scene::init()
{
	m_layers=FsSlowArray::create();
}

void Scene::destroy()
{
	m_layers->decRef();
}


NS_FS_END
