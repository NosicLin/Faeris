#include "stage/FsActionTarget.h"
#include "support/util/FsSlowArray.h"
#include "action/FsAction.h"
#include "stage/FsScene.h"
#include "mgr/FsObjectMgr.h"

NS_FS_BEGIN


const char* ActionTarget::className()
{
	return FS_ACTION_TARGET_CLASS_NAME;
}



Scene* ActionTarget::takeScene()
{
	return NULL;
}


void ActionTarget::giveScene(Scene* scene )
{
	if(scene)
	{
		ObjectMgr* mgr=scene->takeObjectMgr();
		if(mgr)
		{
			mgr->manageObject(this);
			int size=m_actions->size();
			for(int i=0;i<size;i++)
			{
				Action* action=(Action*)m_actions->get(i);
				action->giveScene(scene);
				action->decRef();
			}
		}
	}
}



void ActionTarget::doAction(Action* action)
{

	m_actions->push(action);
	Scene* scene=takeScene();

	if(scene) 
	{
		ObjectMgr* mgr=scene->takeObjectMgr();
		if(mgr)
		{
			action->giveScene(scene);
		}
	}
}

void ActionTarget::removeAction(Action* action)
{
	m_actions->remove(action);
}

void ActionTarget::clearAction()
{
	m_actions->clear();
}

void ActionTarget::update(float dt)
{
	updateAction(dt);
}
void ActionTarget::stopAction()
{
	m_stop=true;
}
bool ActionTarget::isActionStop()
{
	return m_stop;
}
void ActionTarget::resumeAction()
{
	m_stop=false;
}



void ActionTarget::updateAction(float dt)
{
	if(m_stop)
	{
		return;
	}

	m_actions->lock();

	int action_nu=m_actions->size();
	bool finish=false;

	for(int i=0;i<action_nu;i++)
	{
		Action* action=(Action*)m_actions->get(i);
		finish=action->run(this,dt);
		if(finish)
		{
			m_actions->remove(action);
		}
		action->decRef();
	}

	m_actions->unlock();
	m_actions->flush();
}

void ActionTarget::dropData()
{
	m_actions->clear();
	FsObject::dropData();
}


ActionTarget::ActionTarget()
{
	m_actions=FsSlowArray::create();
	m_stop=false;
}

ActionTarget::ActionTarget(bool mgr)
	:FsObject(mgr)
{
	m_actions=FsSlowArray::create();
	m_stop=false;
}


ActionTarget::~ActionTarget()
{
	FS_SAFE_DEC_REF(m_actions);
}





NS_FS_END
























