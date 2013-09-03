#include "action/FsSeqAction.h"

NS_FS_BEGIN

const char* SeqAction::className()
{
	return FS_SEQ_ACTION_CLASS_NAME;
}

SeqAction::SeqAction()
{
	m_actions=NULL;
}


SeqAction::~SeqAction()
{
	destory();
}

bool SeqAction::init()
{
	m_actions=FsArray::create();
}

bool SeqAction::destory()
{
	FS_SAFE_DEC_REF(m_actions);
}


void SeqAction::addAction(Action* action)
{
	m_actions->push(action);
}

void SeqAction::removeAction(Action* action)
{
	m_actions->remove(action);
}

void SeqAction::clearAction()
{
	m_actions->clear();
}

bool SeqAction::run(StageElement* target,float dt)
{
	int action_nu=m_actions->size();
	if(action_nu==0)
	{
		return true;
	}

	bool finish=false;

	Action* cur=m_actions->get(0);
	finish=cur->run(target,dt);
	if(finish)
	{
		m_actions->remove(cur);
	}
	cur->decRef();
	return false;
}

NS_FS_END























