#ifndef _FS_ACTION_TARGET_H_
#define _FS_ACTION_TARGET_H_

#include "FsMacros.h"
#include "FsObject.h"


NS_FS_BEGIN
class Action;
class FsSlowArray;
class Scene;
class ActionTarget:public FsObject
{
	public:
		virtual Scene* takeScene();
		virtual void giveScene(Scene* scene);

	public:
		void doAction(Action* action);
		void removeAction(Action* action);
		void clearAction();

		void stopAction();
		bool isActionStop();
		void resumeAction();

	public:

		virtual void update(float dt);
		virtual const char* className();
		virtual void dropData();

	public:
		void updateAction(float dt);

	protected:
		ActionTarget();
		ActionTarget(bool mgr);
		virtual ~ActionTarget();

	protected:
		FsSlowArray* m_actions;
		bool m_stop;
};

NS_FS_END

#endif /*_FS_ACTION_TARGET_H_*/



