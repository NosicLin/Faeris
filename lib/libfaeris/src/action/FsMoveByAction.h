#ifndef _FS_MOVE_BY_ACTION_H_
#define _FS_MOVE_BY_ACTION_H_

#include "action/FsAction.h"
#include "math/FsVector3.h"

NS_FS_BEGIN
class MoveByAction:public Action
{
	public:
		MoveByAction* create(const Vector3& pos,float time);

	public:
		virtual bool run(StageElement* target,float dt);
		virtual const char* className();

	protected:
		MoveByAction(const Vector3& pos,float time);

	private:
		float m_lifeTime;
		float m_elapse;
		Vector3& m_stepPos;
};



NS_FS_END

#endif /*_FS_MOVE_BY_ACTION_H_*/
