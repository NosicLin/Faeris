#ifndef _FS_STAGE_ELEMENT_H_
#define _FS_STAGE_ELEMENT_H_

#include "FsMacros.h"
#include "FsObject.h"

NS_FS_BEGIN
class Action;
class FsSlowArray;
class StageElement:public FsObject
{
	public:
		void doAction(Action* action);
		void removeAction(Action* action);
		void clearAction(Action* action);

		void stopAction();
		bool isActionStop();
		void resumeAction();

	public:
		virtual void update(float dt);
		virtual const char* className();

	public:
		void updateAction(float dt);

	protected:
		StageElement();
		virtual ~StageElement();


	protected:
		FsSlowArray* m_actions;
		bool m_stop;
};
NS_FS_END

#endif /*_FS_STAGE_ELEMENT_H_*/


