#ifndef _AUDIO_PLAYER_H_
#define _AUDIO_PLAYER_H_

#include "FsMacros.h"
#include "core/FsObject.h"

NS_FS_BEGIN
class Channel;
class AudioPlayer:public FsObject 
{
	public:
		Sound* createSound(const char* name)=0;
		void ReleaseSound(Sound* sound)=0;
		Channel* playSound(Sound* s)=0;

		void setChannelVolume(Channel* channel,float value)=0;
		void getChannelVolume(Channel* channel)=0;

		void pauseChannel(Channel* channel)=0;
		void stopChannel(Channel* channel)=0;
		void resumeChannel(Channel* channel)=0;

		void pause()=0;
		void stop()=0;
		void resume()=0;
		void setVolume(float value)=0;
		void getVolume(float value)=0;
};

NS_FS_END
#endif /* _FS_AUDIO_PLAYER_H_ */

