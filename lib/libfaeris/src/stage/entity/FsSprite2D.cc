#include "stage/entity/FsSprite2D.h"
#include "FsGlobal.h"
#include "stage/entity/FsSprite2DData.h"
#include "graphics/FsTexture2D.h"
#include "support/util/FsArray.h"
#include "support/util/FsDict.h"
#include "support/util/FsInteger.h"
#include "graphics/material/FsMat_V4F_T2F_A1F.h"

NS_FS_BEGIN

Sprite2D* Sprite2D::create(const char* name)
{

	Sprite2D* ret=new Sprite2D;
	if(!ret->init(name))
	{
		FS_TRACE_WARN("init Sprite Data Failed");
		delete ret;
		ret=NULL;
	}

	return ret;
}

void Sprite2D::setColor(Color  color)
{
	m_color=color;
}
Color Sprite2D::getColor()
{
	return m_color;
}
void Sprite2D::setOpacity(float opacity)
{
	m_opacity=opacity;
}

float Sprite2D::getOpacity()
{
	return m_opacity;
}

void Sprite2D::setAnimation(const char*  name)
{
	Sprite2DAnimation* anim=m_data->getAnimation(name);
	setAnimation(anim);

	FS_SAFE_DEC_REF(anim);
}

void Sprite2D::updateAnimation(float dt)
{
	if(!m_curAnimation||m_stop)
	{
		return ;
	}

	int fps=m_curFps;
	float frame_time=1.0f/(float)fps;
	int total_frame=m_curAnimation->getKeyFrameNu();


	m_elapseTime+=dt;

	int forward_frame=(int)floor(m_elapseTime/frame_time);
	m_elapseTime-=forward_frame*frame_time;
	
	m_curFrame+=forward_frame;

	if(m_curFrame>=total_frame)
	{
		switch(m_mode)
		{
			case ANIM_LOOP:
				m_curFrame=m_curFrame%total_frame;
				break;
			case ANIM_START:
				m_curFrame=0;
				m_stop=true;
				break;
			case ANIM_END:
				m_curFrame=total_frame-1;
				m_stop=true;
				break;
		}
	}
}

void Sprite2D::playAnimation(int mode)
{
	m_mode=mode;
	m_stop=false;
}


void Sprite2D::startAnimation(int mode)
{
	m_mode=mode;
	m_stop=false;
	m_elapseTime=0;
	m_curFrame=0;
}

void Sprite2D::stopAnimation()
{
	m_stop=true;
}

bool Sprite2D::isAnimationPlaying()
{
	return !m_stop;
}


void Sprite2D::setCurFrame(int frame)
{
	m_curFrame=frame;
	if(m_curAnimation)
	{
		int total_frame=m_curAnimation->getKeyFrameNu();
		m_curFrame=m_curFrame%total_frame;
	}
}


int Sprite2D::getCurFrame()
{
	return m_curFrame;
}

int Sprite2D::getTotalFrame()
{
	if(!m_curAnimation)
	{
		return 0;
	}
	return m_curAnimation->getKeyFrameNu();
}



void Sprite2D::update(float dt)
{
	updateAction(dt);
	updateAnimation(dt);
}


void Sprite2D::draw(Render* render,bool update_matrix)
{
	if(!m_curAnimation)
	{
		return ;
	}

	if(update_matrix)
	{
		updateWorldMatrix();
	}
	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);
	m_material->setOpacity(m_opacity);
	m_material->setColor(m_color);

	render->setMaterial(m_material);
	render->setActiveTexture(1);
	render->disableAllAttrArray();

	Sprite2DKeyFrame* frame=m_curAnimation->getKeyFrame(m_curFrame);

	Face3 faces[2]=
	{
		Face3(0,3,2),
		Face3(2,1,0),
	};
	int pos_loc=m_material->getV4FLocation();
	int alpha_loc=m_material->getA1FLocation();
	int tex_loc=m_material->getT2FLocation();

	for(int i=0;i<frame->getQuadNu();i++)
	{
		Sprite2DQuad* quad=frame->getQuad(i);
		Texture2D* tex=(Texture2D*)m_textures->get(quad->texture);
		render->bindTexture(tex,0);
		render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,4,0,quad->vertex);
		render->setAndEnableVertexAttrPointer(tex_loc,2,FS_FLOAT,4,0,quad->texcoord);
		render->setAndEnableVertexAttrPointer(alpha_loc,1,FS_FLOAT,4,0,quad->alpha);
		render->drawFace3(faces,2);
		tex->decRef();
	}
	render->popMatrix();
}

const char* Sprite2D::className()
{
	return FS_SPRITE2D_CLASS_NAME;
}

bool Sprite2D::init(const char* name)
{
	Sprite2DData* data=Global::sprite2DDataMgr()->loadSprite2DData(name);
	if(data==NULL)
	{
		FS_TRACE_WARN("Can't Find Sprite2DData(%s)",name);
		return false;
	}
	m_data=data;
	m_textures=data->getTextures();
	m_animationFps=FsDict::create();

	return true;
}

void Sprite2D::setAnimation(Sprite2DAnimation* anim)
{
	FS_SAFE_ADD_REF(anim);
	FS_SAFE_DEC_REF(m_curAnimation);
	m_curAnimation=anim;


	if(m_curAnimation)
	{
		FsString* anim_name=m_curAnimation->getName();
		m_curFrame=0;
		FsInteger* fps=(FsInteger*)m_animationFps->lookup(anim_name);
		if(fps)
		{
			m_curFps=fps->getValue();
		}
		else
		{
			m_curFps=m_curAnimation->getFps();
		}
		FS_SAFE_DEC_REF(anim_name);
		FS_SAFE_DEC_REF(fps);
		m_elapseTime=0.0f;
	}
	else 
	{
		m_curFps=0;
	}
}

int Sprite2D::getFps()
{
	return m_curFps;
}

void Sprite2D::setFps(int fps)
{
	if(m_curAnimation)
	{
		FsString* anim_name=m_curAnimation->getName();
		FsInteger* ifps=FsInteger::create(fps);
		m_animationFps->insert(anim_name,ifps);
		FS_SAFE_DEC_REF(anim_name);
		FS_SAFE_DEC_REF(ifps);
		m_curFps=fps;
	}
}


Sprite2D::Sprite2D()
{
	m_color=Color::WHITE;
	m_opacity=1.0f;
	m_curFrame=0;
	m_elapseTime=0.0f;

	m_mode=ANIM_LOOP;
	m_stop=true;
	m_curFps=0;


	m_data=NULL;
	m_curAnimation=NULL;
	m_textures=NULL;
	m_animationFps=NULL;
	m_material=Mat_V4F_T2F_A1F::shareMaterial();
}

Sprite2D::~Sprite2D()
{
	FS_SAFE_DEC_REF(m_data);
	FS_SAFE_DEC_REF(m_curAnimation);
	FS_SAFE_DEC_REF(m_textures);
	FS_SAFE_DEC_REF(m_material);
	FS_SAFE_DEC_REF(m_animationFps);
}


NS_FS_END
























