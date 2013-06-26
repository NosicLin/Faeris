#include "FsMacros.h"
#include "FsAudioPlayer.h"



#if FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/FsFmodPlayer.h"
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	//#include "platform/FsAndroidAudioPlayer.h"
	#include "platform/FsFmodPlayer.h"
#else 
	#error "UNKOWN AUDIO TYPE"
#endif


NS_FS_BEGIN
AudioPlayer* AudioPlayer::create(int channel_nu)
{
#if FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_WIN32) 
	return FmodPlayer::create(channel_nu);
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
//	return AndroidAudioPlayer::create(channel_nu);
	return FmodPlayer::create(channel_nu);
#else 
	#error "Unkown Audio Player"
#endif 
}

AudioPlayer::~AudioPlayer()
{
}

NS_FS_END

#if FS_PLATFORM_OS(FS_OS_LINUX) || FS_PLATFORM_OS(FS_OS_WIN32) 
	#include "platform/FsFmodPlayer.cc"
#elif FS_PLATFORM_OS(FS_OS_ANDROID)
	//#include "platform/FsAndroidAudioPlayer.cc"
	#include "platform/FsFmodPlayer.cc"
#else 
	#error "UNKOWN AUDIO TYPE"
#endif

