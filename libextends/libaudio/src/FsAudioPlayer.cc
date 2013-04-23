#include "FsMacros.h"
#include "FsAudioPlayer.h"


#define FS_AUDIO_FMOD 

#if FS_CONFIG(FS_AUDIO_FMOD)
	#include "platform/FsFmodPlayer.h"
#else 
	#error "UNKOWN AUDIO TYPE"
#endif


NS_FS_BEGIN
AudioPlayer* AudioPlayer::create(int channel_nu)
{
#if FS_CONFIG(FS_AUDIO_FMOD) 
	return FmodPlayer::create(channel_nu);
#else 
	#error "Unkown Audio Player"
#endif 
}

AudioPlayer::~AudioPlayer()
{
}


NS_FS_END

#if FS_CONFIG(FS_AUDIO_FMOD)
	#include "platform/FsFmodPlayer.cc"
#else 
	#error "UNKOWN AUDIO TYPE"
#endif

