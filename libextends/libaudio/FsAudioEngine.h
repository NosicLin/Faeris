#ifndef _FS_AUDIO_ENGINE_H_
#define _FS_AUDIO_ENGINE_H_

#include <map>

#include "FsMacros.h"
#include "core/FsObject.h"

NS_FS_BEGIN 
class Sound;
class Channel;
class AudioPlayer;
class AudioEngine:public FsObject
{
	public:
		enum
		{
			PRIORITY_HIGH,
			PRIORITY_MIDDLE,
			PRIORITY_LOW,
		};
		typedef std::map<std::string,Sound*> SoundSet;

	public:
		static AudioEngine* create();

	public:
		/* load and unload sound */
		bool loadSound(const char* name);
		bool unloadSound(const char* name);
		void unloadSounds();

		/* play */
		Channel* playSound(const char* name,bool loop=false,int priority=PRIORITY_HIGH);


		/* single channel */
		void pauseChannel(Channel* channel);
		void resumeChannel(Channel* channel);
		void stopChannel(Channel* channel);

		void setChannelVolume(Channel* channel,float value);
		float getChannelVolume(Channel* channel);

		/* all channel */
		void pause();
		void resume();
		void stop();
		void setVolume(float value);


	protected:
		bool init();
		void destory();
		AudioEngine();
		virtual ~AudioEngine();
		virtual const char* className();

	protected:
		AudioPlayer* m_player;
		SoundSet m_sounds;
};

NS_FS_END


#endif /*_FS_AUDIO_ENGINE_H_*/


