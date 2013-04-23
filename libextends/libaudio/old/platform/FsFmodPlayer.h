#ifndef _FS_FMOD_PLAYER_H_
#define _FS_FMOD_PLAYER_H_
#include "fmod/fmod.hpp"
#include "FsAudioPlayer.h"

NS_FS_BEGIN
class FmodPlayer:public AudioPlayer
{
	public:
		static FsFmodPlayer* create();
	public:
		Sound* createSound(const char* name);
		void ReleaseSound(Sound* sound);
		Channel* playSound(Sound* s);

		void setChannelVolume(Channel* channel,float value);
		void getChannelVolume(Channel* channel);

		void pauseChannel(Channel* channel);
		void stopChannel(Channel* channel);
		void resumeChannel(Channel* channel);

		void pause();
		void stop();
		void resume();
		void setVolume(float value);
		void getVolume(float value);
	protected:
		FmodPlayer();
		bool init();
		void destory();
		virtual ~FmodPlayer();

	private:
		FMOD::System* m_system;
		FMOD::ChannelGroup* m_channelGroup;
};
NS_FS_END 
#endif /*_FS_FMOD_PLAYER_H_*/


