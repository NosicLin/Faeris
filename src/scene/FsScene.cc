#include "scene/FsScene.h"
#include "scene/FsLayer.h"
#include "util/FsArray.h"
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
}
void Scene::draw(Render* render)
{
	int layer_nu=m_layers->size();
	for(int i=layer_nu-1;i>=0;i--)
	{
		Layer* layer=(Layer*)m_layers->get(i);
		if(layer->visible())
		{
			layer->draw(render);
		}
		layer->decRef();
	}
}
void Scene::touchBegin(float x,float y)
{
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
}
void Scene::touchMove(float x,float y)
{
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
}

void Scene::touchEnd(float x,float y)
{
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
	m_layers=FsArray::create();
}

void Scene::destroy()
{
	m_layers->decRef();
}


NS_FS_END