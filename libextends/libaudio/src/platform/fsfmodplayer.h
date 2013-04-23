#ifndef _FMOD_PLAYER_H_
#define _FMOD_PLAYER_H_ 

#include "fmod/fmod.hpp"

#include "FsMacros.h"
#include "FsAudioPlayer.h"


NS_FS_BEGIN

class FmodPlayer:public AudioPlayer 
{
	public:
		static FmodPlayer* create(int channel_nu);

	public:
		virtual Sound* createSound(const char* filename);
		virtual void releaseSound(Sound* s);

	public:
		virtual Channel* playSound(Sound* s,int loop,int priority);

	public:
		virtual void pauseChannel(Channel* c);
		virtual void resumeChannel(Channel* c);
		virtual void stopChannnel(Channel* c);
		virtual void setChannelVolume(Channel* c,float value);
		virtual float getChannelVolume(Channel* c);

	public:
		virtual void pauseChannels();
		virtual void resumeChannels();
		virtual void stopChannnels();
		virtual void setVolume(float value);

	protected:
		FmodPlayer();
		virtual ~FmodPlayer();
		bool init(int channel_nu);
		void destory();

	private:
		FMOD::System* m_system;
		FMOD::ChannelGroup* m_channelGroup;
		int m_channelNu;
};

NS_FS_END

#endif /*_FMOD_PLAYER_H_*/

