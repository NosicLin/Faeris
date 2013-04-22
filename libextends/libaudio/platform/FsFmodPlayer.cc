#include "FsFmodPlayer.h"
NS_FS_BEGIN

FmodPlayer* FmodPlayer::create()
{
	FmodPlayer* ret=new FmodPlayer;
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	return ret;
}

FmodPlayer::FmodPlayer()
{
	m_system=NULL;
	m_channelGroup=NULL;
}

bool FmodPlayer::init()
{
	FMOD_RESULT result;
	FMOD::System_Create(&m_system);
	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMod Error!(%d) %s\n",result,FMOD_ErrorString(result));
		return false;
	}
	result=m_system->init(100,FMOD_INIT_NORMAL,0);
	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMod Error!(%d) %s\n",result,FMOD_ErrorString(result));
	}





}



NS_FS_END 

