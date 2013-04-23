#include "fmod/fmod.hpp"
#include "fmod/fmod_errors.h"

#include "FsMacros.h"
#include "FsFmodPlayer.h"

#include "io/FsVFS.h"


NS_FS_BEGIN

FmodPlayer* FmodPlayer::create(int channel_nu)
{
	FmodPlayer* ret=new FmodPlayer;
	if(!ret->init(channel_nu))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Sound* FmodPlayer::createSound(const char* filename)
{
	m_system->update();
	FMOD_RESULT result;
	FMOD::Sound* sound=NULL;
	FMOD_CREATESOUNDEXINFO exinfo;


	FsFile* file=VFS::open(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("Open File %s For Load Sound Failed",filename);
		return NULL;

	}
	int length=file->getLength();
	if(length<=0)
	{
		FS_TRACE_WARN("No File Content");
		file->decRef();
		return NULL;
	}


	char* buffer=new  char[length];
	int readbyte=file->read(buffer,length);
	file->decRef(); /* file is no used */

	if(readbyte!=length)
	{
		FS_TRACE_WARN("Can't load %d byte For Sound File,Only %d byte Loaded",length,readbyte);
		delete[] buffer;
		return NULL;
	}

	memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
    exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.length = length;    


	result=m_system->createSound(buffer,FMOD_LOOP_NORMAL |FMOD_OPENMEMORY,&exinfo,&sound);
	delete[] buffer; /* buffer is no used */


	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
		return NULL;
	}
	return (Sound*) sound;
}

void FmodPlayer::releaseSound(Sound* s)
{
	m_system->update();
	FMOD_RESULT result;
	FMOD::Sound* sound=(FMOD::Sound*) s;
	result=sound->release();

	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
	}
}


Channel* FmodPlayer::playSound(Sound* s,int loop,int priority)
{
	m_system->update();
	FMOD_RESULT result;
	FMOD::Channel* channel=NULL;
	FMOD::Sound* sound=NULL;

	sound= (FMOD::Sound*) s;
	result=m_system->playSound(FMOD_CHANNEL_FREE,sound,true,&channel);


	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
		return NULL;
	}

	channel->setChannelGroup(m_channelGroup);
	channel->setLoopCount(loop);
	switch(priority)
	{
		case PRIORITY_HIGH:
			channel->setPriority(0);
			break;
		case PRIORITY_MIDDLE: 
			channel->setPriority(128);
			break;
		case PRIORITY_LOW:
			channel->setPriority(256);
			break;
	}

	channel->setPaused(false);
	return (Channel*) channel;
}


void FmodPlayer::pauseChannel(Channel* c)
{
	m_system->update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	channel->setPaused(true);
}

void FmodPlayer::resumeChannel(Channel* c)
{
	m_system->update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	channel->setPaused(false);
}

void FmodPlayer::stopChannnel(Channel* c)
{
	m_system->update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	channel->stop();
}

void FmodPlayer::setChannelVolume(Channel* c,float value)
{
	m_system->update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	channel->setVolume(value);
}
float FmodPlayer::getChannelVolume(Channel* c)
{
	m_system->update();
	FMOD::Channel* channel=(FMOD::Channel*) c;
	float volume;
	channel->getVolume(&volume);
	return volume;
}


void FmodPlayer::pauseChannels()
{
	m_system->update();
	m_channelGroup->setPaused(true);
}
void FmodPlayer::resumeChannels()
{
	m_system->update();
	m_channelGroup->setPaused(false);
}
void FmodPlayer::stopChannnels()
{
	m_system->update();
	m_channelGroup->stop();
}

void FmodPlayer::setVolume(float value)
{
	m_system->update();
	m_channelGroup->setVolume(value);
}

FmodPlayer::FmodPlayer()
{
	m_system=0;
	m_channelGroup=0;
	m_channelNu=0;
}
FmodPlayer::~FmodPlayer()
{
	destory();
}

bool FmodPlayer::init(int channel_nu)
{
	FMOD_RESULT result;
	FMOD::ChannelGroup* master_grounp;
	result=FMOD::System_Create(&m_system);
	if(result!=FMOD_OK)
	{
		goto error;
	}

	result=m_system->init(channel_nu,FMOD_INIT_NORMAL,0);
	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("init failed");
		goto error;
	}


	result=m_system->createChannelGroup("ChannelGroup",&m_channelGroup);
	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("create ChannelGroup Failed");
		goto error;
	}

	result = m_system->getMasterChannelGroup(&master_grounp);
	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("getMasterChannelGroup Failed");
		goto error;
	}

	result= master_grounp->addGroup(m_channelGroup);
	if(result!=FMOD_OK)
	{
		FS_TRACE_WARN("add to Master Grounp Failed");
		goto error;
	}

	m_channelNu=channel_nu;
	return true;

error:

	FS_TRACE_WARN("FMOD error! (%d) %s", result, FMOD_ErrorString(result));
	return false;


}
void FmodPlayer::destory()
{
	if(m_channelGroup) m_channelGroup->release();
	if(m_system)
	{
		m_system->close();
		m_system->release();
	}
}



NS_FS_END














