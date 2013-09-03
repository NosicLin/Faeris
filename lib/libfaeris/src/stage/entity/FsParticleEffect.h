#ifndef _FS_PARTICLE_EFFECT_H_
#define _FS_PARTICLE_EFFECT_H_
#include "FsMacros.h"
#include "FsObject.h"
#include "stage/entity/FsEntity.h"

NS_FS_BEGIN

class ParticleEmitter;


class Particle 
{
	public:
		float m_timeElapse;
		float m_lifeTime;
		float m_size;
		float m_sizeDt;
		float m_colorRed,m_colorGreen,m_colorBlue,m_colorAlpha;
		float m_colorRedDt,m_colorGreenDt,m_colorBlueDt,m_colorAlphaDt;
		float m_angle;

		float m_rotation;
		float m_rotationDt;

		Vector2f m_position;
		Vector2f m_startPos;

		/* gravity mode */
		struct 
		{
			Vector2f m_gravity;
			float m_speed;
			float m_radialAcceleration;
			float m_tangentialAcceleration;
		}m_gravityMode;

		/* radial mode */
		struct 
		{
			float m_radius;
			float m_radiusDt;
			float m_angleDt;
		}m_radialMode;

};

class ParticleEffect:public Entity 
{
	public:
		ParticleEffect* create(const char* filename);
		ParticleEffect* create(FsFile* file);
		ParticleEffect* create(ParticleEmitter* emitter);

	public:


};


NS_FS_END


#endif /*_FS_PARTICLE_EFFECT_H_*/

















