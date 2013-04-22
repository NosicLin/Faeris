#include "FsAudioEngine.h"
#include "FsAudioPlayer.h"

NS_FS_BEGIN
AudioEngine* AudioEngine::create()
{
	AudioEngine* ret=new AudioEngine;
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	return ret;
}

bool AudioEngine::loadSound(const char* name)
{

	SoundSet::iterator iter=m_sounds.find(name);
	if(iter==m_sounds.end())
	{
		Sound* s=m_player->createSound(name);
		if(s)
		{
			m_sounds[name]=s;
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool AudioEngine::unloadSound(const char* name)
{
	SoundSet::iterator iter=m_sounds.find(name);
	if(iter==m_sounds.end())
	{
		return false;
	}
	m_player->releaseSound(iter->second);

	m_sounds->erase(name);
	return true;
}

bool AudioEngine:::unloadSounds()
{
	SoundSet::iterator iter=m_sounds.begin();
	for(;iter!=m_sounds.end();++iter)
	{
		m_player->releaseSound(iter->second);
	}
	m_sounds.clear();
	return true;
}

Channel* AudioEngine::playSound(const char* name,bool loop,int priority)
{
	SoundSet::iterator iter=m_sounds.find(name);
	if(iter==m_sounds.end())
	{
		return NULL;
	}

	return m_player->playSound(iter->second,loop,priority);
}


void AudioEngine::setVolume(Channel* channel,float value)
{
	m_player->setVolume(channel,value);
}

float AudioEngine::getVolume(Channel* channel)
{
	return m_player->getVolume(channel);
}


float AudioEngine::pauseChannel(Channel* channel)
{
	return m_player->pauseChannel(channel);
}

float AudioEngine::resumeChannel(Channel* channel)
{
	return m_player->resumeChannel(channel);
}

float AudioEngine::stopChannel(Channel* channel)
{
	return m_player->stopChannel(channel);
}











NS_FS_END

























