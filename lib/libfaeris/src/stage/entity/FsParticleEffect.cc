#include <assert.h>
#include "stage/entity/FsParticleEffect.h"

NS_FS_BEGIN


const char* ParticleEffect::className()
{
	return FS_PARTICLE_EFFECT_CLASS_NAME;
}


ParticleEffect* ParticleEffect::create(const char* filename)
{
	ParticleEmitter* emit=ParticleEmitter::create(filename);
	if( emit==NULL) 
	{
		FS_TRACE_WARN("Create Emitter For File(%s) Failed",filename);
		return NULL;
	}
	ParticleEffect* ret=ParticleEffect::create(emit);
	FS_SAFE_DEC_REF(emit);
	return ret;
}

ParticleEffect* ParticleEffect::create(FsFile* file)
{
	ParticleEmitter* emit=ParticleEmitter::create(file);
	if(emit==NULL)
	{
		FS_TRACE_WARN("create Emiit for Failed");
		return NULL;
	}

	ParticleEffect* ret=ParticleEffect::create(emit);
	FS_SAFE_DEC_REF(emit);
	return ret;
}

ParticleEffect* ParticleEffect::create(ParticleEmitter* emitter)
{
	ParticleEffect* ret=new ParticleEffect;
	if(!ret->init(emitter))
	{
		delete ret;
	}
	return ret;
}


ParticleEffect::ParticleEffect()
{
	m_lifeTime=0;
	m_elapseTime=0;
	m_emitter=NULL;
	m_stop=true;
	m_pause=false;
	m_autoRemove=true;
}

ParticleEffectL::~ParticleEffect()
{
	destory();
}

bool ParticleEffect::init(ParticleEmitter* emitter)
{
	FS_SAFE_ASSIGN(m_emitter,emitter);
	return true;
}

void ParticleEffect::start()
{
	if(!m_emitter)
	{
		m_running=false;
		FS_TRACE_WARN("no emitter find, start faild");
		return;
	}

	m_lifeTime=m_emitter->getDurationTime()+m_emitter->getDurationTimeVar()*Math:random(0.0f,1.0f);
	m_elapseTime=0.0f;
	m_stop=false;
	m_pause=false;
}

void ParticleEffect::stop()
{
	m_stop=true;
}


void ParticleEffect::setPause(bool pause)
{
	m_pause=pause;
}


bool ParticleEffect::isPause()
{
	return m_pause;
}

bool ParticleEffect::isStop()
{
	return m_stop;
}

void ParticleEffect::setEmitter(ParticleEmitter* emit)
{
	FS_SAFE_ASSIGN(m_emitter,emit);
	m_stop=true;
	m_pause=false;
}

ParticleEmitter* ParticleEffect::getEmitter()
{
	FS_SAFE_ADD_REF(m_emitter);
	return m_emitter;
}

void ParticleEffect::setAutoRemoveOnStop(bool remove)
{
	m_autoRemove=remove;
}




void ParticleEffect::update(float dt)
{
	if(m_stop||m_pause)
	{
		return ;
	}

	/* update particle */
	int size=m_particles.size();
	int i=0;
	int pos=0;
	Particle* p=NULL;

	while(pos<size)
	{
		p=&m_particles[i];
		updateParticle(p,dt);

		if(p->m_timeElapse>p->m_lifeTime)
		{

			if(m_particles.size()-1>i)
			{
				m_particles[i]=m_particles[m_particles.size()-1];
			}
			m_particles.pop_back();
		}
		else 
		{
			i++;
		}
		pos++;
	}

	/* generate particle */
	generateParticle(dt);

	
	/* check particle stop */
	if ( m_elapseTime > m_lifeTime )
	{
		/* no particle exist,so will set the state to stop */
		if (m_particles.size()==0) 
		{
			m_stop=true;
			if(m_autoRemove)
			{
				Entity::detach();
			}
		}
	}
}


void ParticleEffect::updateParticle(Particle* p,float dt)
{
	p->m_timeElapse+=dt;
	p->m_size+=p->m_sizeDt*dt;

	p->m_colorRed+=p->m_colorRedDt*dt;
	p->m_colorGreenDt+=p->m_colorGreenDt*dt;
	p->m_colorBlue+=p->m_colorBlueDt*dt;
	p->m_colorAlpha+=p->m_colorAlphaDt*dt;

	p->m_rotation+=p->m_rotationDt*dt;


	/* gravity mode */
	if(p->m_envMode==ParticleEmitter::ENV_GRAVITY)
	{
		Vector2f radial=p->m_position;
		radial.normalise();
		Vector2f tangent=Vector2f(-radial.y,radial.x);

		p->m_gravityMode.m_direction+=
						tangent*p->m_gravityMode.m_tangentialAcceleration+
					    radial *p->m_gravityMode.m_radialAcceleration+ 
					    p->m_gravityMode.m_gravity;

		p->m_position+=p->m_gravityMode.m_direction*dt;
	}
	/* radial mode */
	else if (p->m_envMode==ParticleEmitter::ENV_RADIAL)
	{
		p->m_radialMode.m_radius+=p->m_radialMode.m_radiusDt*dt;
		p->m_radialMode.m_angle+=p->m_radialMode.m_angleDt*dt;

		p->m_position=Vector2f(-Math::cosf(p->m_radialMode.m_angle),
							   -Math::sinf(p->m_radialMode.m_angle))*p->m_radialMode.m_radius;

	}
	else 
	{
		FS_TRACE_WARN("Error Env Mode");
	}
}

void ParticleEffect::generateParticle(float dt)
{
	if(m_elapseTime>m_lifeTime)
	{
		return;
	}

	float diff;
	if(m_lifeTime>0)
	{
		if(m_elapseTime+dt>m_lifeTime)
		{
			diff=m_lifeTime-m_elapseTime;
		}
		else 
		{
			diff=dt;
		}
	}
	else 
	{
		diff=dt;
	}

	assert(diff>=0):

	int generate_nu=m_emitSpeed*diff;

	int particle_size=m_particles.size();
	if(generate_nu+particle_size>m_maxParticles)
	{
		generate_nu=m_maxParticles=particle_size;
	}

	m_particles.resize(particle_size+generate_nu);

	for(int i=0;i<generate_nu;i++)
	{
		Particle* p=&m_particles[i+particle_size];
		m_emitter->generateParticle(p);
	}

	m_elapseTime+=dt;

}

void ParticleEffect::draw(Render* r,bool update_world_matrix)
{
	if(!m_emitter)
	{
		return;
	}
	if(m_stop||m_particles.size()==0)
	{
		return;
	}

	Texture2D* texture=m_emitter->getTexture();
	if(texture==NULL)
	{
		return;
	}


	if(update_world_matrix)
	{
		updateWorldMatrix();
	}


	render->pushMatrix();
	render->mulMatrix(&m_worldMatrix);

	m_material->setOpacity(m_opacity);
	render->setMaterial(m_material);

	render->setActiveTexture(1);
	render->bindTexture(texture,0);
	texture->decRef();

	render->disableAllAttrArray();

	int pos_loc=m_material->getV4FLocation();
	int tex_loc=m_material->getT2FLocation();
	int col_loc=m_material->getC4FLocation();

	static Face3 faces[2]=
	{
		Face3(0,1,2),
		Face3(2,3,0),
	};

	for(unsigned int i=0;i<m_vertices.size();i++)
	{
		render->setAndEnableVertexAttrPointer(pos_loc,2,FS_FLOAT,4,0,&m_vertices[i]);
		render->setAndEnableVertexAttrPointer(col_loc,4,FS_FLOAT,4,0,&m_vertices[i].c4);
		render->drawFace3(faces,2);
	}

	render->popMatrix();
}


NS_FS_END 


















