#include "FsMacros.h"
#include "sys/platform/android/FsJniUtil.h"
#include "FsAndroidAudioPlayer.h"

static const char* class_name="org/faeris/lib/FsAudioPlayer";

NS_FS_BEGIN

AndroidAudioPlayer* AndroidAudioPlayer::create(int channel_nu)
{

	AndroidAudioPlayer* ret=new AndroidAudioPlayer();
	if(!ret->init(channel_nu))
	{
		delete ret;
		return NULL;
	}
	return ret;
}


Sound* AndroidAudioPlayer::createSound(const char* filename)
{
	JNIEnv* env=JniUtil::getEnv();
	jstring jfile_name=env->NewStringUTF(filename);

	jint ret;
	FS_JNI_CALL_METHOD(m_audioPlayer,class_name,"createSound","(Ljava/lang/String;)I",Int,ret,jfile_name);
	env->DeleteLocalRef(jfile_name);


	if(ret==-1)
	{
		return NULL;
	}
	return (Sound*) ((int)ret);
}

void AndroidAudioPlayer::releaseSound(Sound* s)
{
	int sound_id=(int) s;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,class_name,"releaseSound","(I)V",sound_id);
}

Channel* AndroidAudioPlayer::playSound(Sound* s,int loop,int priority)
{
	int sound_id=(int) s;
	JniUtil::attachCurrentThread();

	int pri_nu=1;
	switch (priority)
	{
		case AudioPlayer::PRIORITY_HIGH:
			pri_nu=2;
			break;
		case AudioPlayer::PRIORITY_MIDDLE:
			pri_nu=1;
			break;
		case AudioPlayer::PRIORITY_LOW:
			pri_nu=0;
			break;
	}
	
	jint ret;
	FS_JNI_CALL_METHOD(m_audioPlayer,class_name,"playSound","(III)I",Int,ret,sound_id,loop,priority);
	if(ret==-1)
	{
		return NULL;
	}
	return (Channel*) ((int)ret);
}


void AndroidAudioPlayer::pauseChannel(Channel* c)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,class_name,"pauseChannel","(I)V",channel);
}
void AndroidAudioPlayer::resumeChannel(Channel* c)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,class_name,"resumeChannel","(I)V",channel);
}

void AndroidAudioPlayer::stopChannel(Channel* c)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,class_name,"stopChannel","(I)V",channel);
}

void AndroidAudioPlayer::setChannelVolume(Channel* c,float value)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,class_name,"stopChannel","(IF)V",channel,value);
}


float AndroidAudioPlayer::getChannelVolume(Channel* c)
{
	int channel=(int) c;
	JniUtil::attachCurrentThread();
	jfloat ret;
	FS_JNI_CALL_METHOD(m_audioPlayer,class_name,"stopChannel","(I)F",Float,ret,channel);
}

void AndroidAudioPlayer::pauseChannels()
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,class_name,"pauseChannels","()V");
}

void AndroidAudioPlayer::resumeChannels()
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,class_name,"resumeChannels","()V");
}
void AndroidAudioPlayer::stopChannnels()
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,class_name,"stopChannels","()V");
}

void AndroidAudioPlayer::setVolume(float value)
{
	JniUtil::attachCurrentThread();
	FS_JNI_CALL_VOID_METHOD(m_audioPlayer,class_name,"setVolume","(F)V",value);
}

bool AndroidAudioPlayer::init(int channel_nu)
{
	JNIEnv* env=JniUtil::getEnv();
	FS_JNI_NEW_OBJECT(class_name,"(I)V",m_audioPlayer,channel_nu);
	if(m_audioPlayer)
	{
		env->NewGlobalRef(m_audioPlayer);
		return true;
	}
	return false;
}

void AndroidAudioPlayer::destory()
{
	JNIEnv* env=JniUtil::getEnv();
	if(m_audioPlayer)
	{
		env->DeleteGlobalRef(m_audioPlayer);
		m_audioPlayer=0;
	}
}

AndroidAudioPlayer::AndroidAudioPlayer()
{
	m_audioPlayer=0;
}
AndroidAudioPlayer::~AndroidAudioPlayer ()
{
	destory();
}



NS_FS_END 




