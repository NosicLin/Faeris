#ifndef _FS_PARTICLE_EFFECT_H_
#define _FS_PARTICLE_EFFECT_H_
#include "FsMacros.h"
#include "FsObject.h"
#include "stage/entity/FsEntity.h"

NS_FS_BEGIN

class ParticleEmitter;
class FsMat_V4F_T2F_C4F;

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

		Vector2 m_position;
		Vector2 m_startPos;
		

		int m_envMode;
		int m_moveMode;

		/* gravity mode */
		struct 
		{

			Vector2 m_gravity;
			float m_speed;
			float m_radialAcceleration;
			float m_tangentialAcceleration;
			float m_direction;

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
		ParticleEffect* create();

	public:
		void start();
		void stop();
		void setPause(bool pause);
		bool isPause();
		bool isStop();

		void setEmitter(ParticleEmitter* emit);
		ParticleEmitter* getEmitter();

		void setAutoRemoveOnStop(bool remove);

	public:
		/* override entity */
		virtual void update(float dt);
		virtual void draw(Render* r,bool update_world_matrix);
		virtual const char* className();


	protected:
		virtual void updateParticle(Particle* p,float dt);
		virtual void generateParticle(float dt);
		ParticleEffect();
		~ParticleEffect();
		bool init(ParticleEmitter* emitter);
		void destory();


	private:
		std::vector<Particle> m_particles;

		int m_maxParticles;
		int m_emitSpeed;
		float m_lifeTime;
		float m_elapseTime;
		ParticleEmitter* m_emitter;

		bool m_stop;
		bool m_pause;
		bool m_autoRemove;

		FsMat_V4F_T2F_C4F* m_material;

};


NS_FS_END


#endif /*_FS_PARTICLE_EFFECT_H_*/


