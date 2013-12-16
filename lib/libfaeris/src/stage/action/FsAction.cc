#include "stage/action/FsAction.h"
#include "stage/FsScene.h"

#include "mgr/FsObjectMgr.h"

NS_FS_BEGIN

const char* Action::className()
{
	return FS_ACTION_CLASS_NAME;
}


void Action::giveScene(Scene* scene)
{

	if(scene) 
	{
		ObjectMgr* mgr=scene->takeObjectMgr();
		if(mgr)
		{
			mgr->manageObject(this);
		}
	}
}




NS_FS_END





