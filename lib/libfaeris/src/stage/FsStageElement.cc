#include "stage/FsStageElement.h"
#include "support/util/FsSlowArray.h"
#include "action/FsAction.h"

NS_FS_BEGIN


const char* StageElement::className()
{
	return FS_STAGE_ELEMENT_CLASS_NAME;
}


void StageElement::doAction(Action* action)
{
	m_actions->push(action);
}

void StageElement::removeAction(Action* action)
{
	m_actions->remove(action);
}

void StageElement::clearAction(Action* action)
{
	m_actions->clear();
}

void StageElement::update(float dt)
{
	updateAction(dt);
}

void StageElement::updateAction(float dt)
{
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


StageElement::StageElement()
{
	m_actions=FsSlowArray::create();
}

StageElement::~StageElement()
{
	FS_SAFE_DEC_REF(m_actions);
}





NS_FS_END
























