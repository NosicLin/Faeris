#include "FsSpineSprite.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN 

const char* SpineSprite::className()
{
	return "SpineSprite";
}

SpineSprite* SpineSprite::create(const char* filename)
{
	SpineSprite* ret=new SpineSprite;
	if(!ret->init(filename))
	{
		delete ret;
		ret=NULL;
	}

	return ret;
}


int SpineSprite::setSkin(const char* skin)
{
	bool ret=Skeleton_setSkinByName(m_skeleton,skin);
	return ret;
}


void SpineSprite::setColor(Color c)
{
	m_color=c;
}

Color SpineSprite::getColor()
{
	return m_color;
}


void SpineSprite::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float SpineSprite::getOpacity()
{
	return m_opacity;
}

void SpineSprite::setAnimation(const char* anim,bool loop)
{
	AnimationState_setAnimation(m_animationState,anim,loop);
}

void SpineSprite::addAnimation(const char* anim,bool loop,float delay)
{
	AnimationState_addAnimation(m_animationState,anim,loop,delay);
}


void SpineSprite::clearAnimation()
{
	AnimationState_clearAnimation(m_animationState);
}

void SpineSprite::updateAnimation(float dt)
{
	if(m_stop)
	{
		return;
	}
	else 
	{
		m_elapseTime+=dt;
	}
}


void SpineSprite::playAnimation()
{
	if(m_stop)
	{
		m_stop=false;
	}
}

void SpineSprite::startAnimation()
{
	m_elapseTime=0.0f;
	m_stop=false;
}

void SpineSprite::stopAnimation()
{
	m_stop=true;
}

bool SpineSprite::isAnimationPlaying()
{
	if(m_stop||AnimationState_isComplete(m_animationState))
	{
		return false;
	}
	return true;
}

void SpineSprite::setCurTime(float time)
{
	m_elapseTime=time;
}

float SpineSprite::getCurTime()
{
	return m_elapseTime;
}


float SpineSprite::update(float dt)
{
	updateAnimation();
}



float SpineSprite::draw(Render* render,bool update_matrix)
{
	if(!m_material)
	{
		return;
	}

	m_skeleton->r=(float)m_color.r/255.0f;
	m_skeleton->g=(float)m_color.g/255.0f;
	m_skeleton->r=(float)m_color.b/255.0f;
	m_skeleton->a=(float)m_color.a/255.0f*m_opacity;

	AnimationState_update(m_animationState,m_elapseTime);
	AnimationState_applay(m_animationState,m_skeleton);
	Skeleton_updateWorldTransform(m_skeleton);

	int slot_nu=m_skeleton->slotCount;
	for(int i=0;i<slot_nu;i++)
	{
		Slot* slot=m_skeleton->slots[i];
		if(!slot->attachment||slot->attachment->type!=ATTACHMENT_REGION)
		{
			continue;
		}
		TextureAttachment* attachment=(TextureAttachment*)slot->attachment;
		Texture2D* texture=(Texture2D*)attachment->rendererObject;

		if(!texture)
		{
			continue;
		}

		float vertices[8];
		Fs_V2F_T2F_C2F quad;










	}





}




NS_FS_END




























