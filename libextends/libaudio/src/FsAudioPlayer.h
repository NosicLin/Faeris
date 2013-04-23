#ifndef _AUDIO_PLAYER_H_
#define _AUDIO_PLAYER_H_

NS_FS_BEGIN
class Sound;
class Channel;

class AudioPlayer
{
	public:
		enum
		{
			PRIORITY_HIGH,
			PRIORITY_MIDDLE,
			PRIORITY_LOW,
		};
	public:
		static AudioPlayer* create(int channel_nu);

	public:
		virtual Sound* createSound(const char* filename)=0;
		virtual void releaseSound(Sound* s)=0;

	public:
		virtual Channel* playSound(Sound* s,int loop,int priority)=0;

	public:
		virtual void pauseChannel(Channel* c)=0;
		virtual void resumeChannel(Channel* c)=0;
		virtual void stopChannnel(Channel* c)=0;
		virtual void setChannelVolume(Channel* c,float value)=0;
		virtual float getChannelVolume(Channel* c)=0;

	public:
		virtual void pauseChannels()=0;
		virtual void resumeChannels()=0;
		virtual void stopChannnels()=0;
		virtual void setVolume(float value)=0;
	public:
		virtual ~AudioPlayer();


};

NS_FS_END

#endif /* _AUDIO_PLAYER_H_ */ 


