#ifndef _FS_ANDROID_AUDIO_PLAYER_H_
#define _FS_ANDROID_AUDIO_PLAYER_H_
#include <jni.h>

#include "FsMacros.h"

NS_FS_BEGIN

class AndroidAudioPlayer:public AudioPlayer
{
	public:
		static AndroidAudioPlayer* create(int channel_nu);

	public:
		virtual Sound* createSound(const char* filename);
		virtual void releaseSound(Sound* s);

	public:
		virtual Channel* playSound(Sound* s,int loop,int priority);

	public:
		virtual void pauseChannel(Channel* c);
		virtual void resumeChannel(Channel* c);
		virtual void stopChannel(Channel* c);
		virtual void setChannelVolume(Channel* c,float value);
		virtual float getChannelVolume(Channel* c);

	public:
		virtual void pauseChannels();
		virtual void resumeChannels();
		virtual void stopChannnels();
		virtual void setVolume(float value);

	protected:
		bool init(int channel_nu);
		void destory();
		AndroidAudioPlayer();
		virtual ~AndroidAudioPlayer();
	private:
		jobject m_audioPlayer;
};

NS_FS_END 

#endif /*_FS_ANDROID_AUDIO_PLAYER_H_*/
