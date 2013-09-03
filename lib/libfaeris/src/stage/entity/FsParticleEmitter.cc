#include "stage/entity/FsParticleEmitter.h"
#include "stage/entity/FsParticleEffect.h"
#include "sys/io/FsVFS.h"
#include "graphics/FsTexture2D.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN

ParticleEmitter* ParticleEmitter::create()
{
	ParticleEmitter* ret=new ParticleEmitter;
	if(!ret->init())
	{
		delete ret;
		return NULL;
	}
	return ret;
}

ParticleEmitter* ParticleEmitter::create(const char* filename)
{
	ParticleEmitter* ret=new ParticleEmitter;
	if(!ret->init(filename))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

ParticleEmitter* ParticleEmitter::create(FsFile* file)
{
	ParticleEmitter* ret=new ParticleEmitter;
	if(!ret->init(file))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

void ParticleEmitter::generateParticle(Particle* p)
{
	float fbegin,fend;

	memset(p,sizeof(*p));

	float lifetime=m_lifeTime+m_lifeTime*Math::random(0.0f,1.0f);

	p->m_timeElapse=0;
	p->m_lifeTime=lifetime;

	if(lifetime==0)
	{
		return ;
	}
	
	fbegin=m_beginSize+m_beginSizeVar*Math::random(0.0f,1.0f);
	fend=m_endSize+m_endSizeVar*Math::random(0.0f,1.0f);

	p->m_size=fbegin
	p->m_sizeDt=(fend-fbegin)/lifetime;

	fbegin=m_startColor.r+m_startColorVar.r*Math::random(0.0f,1.0f);
	fend=m_endColor.r+m_endColorVar.r*Math::random(0.0f,1.0f);
	p->m_colorRed=Math::clampf(fbegin/255.0,0,1.0f);
	p->m_colorRedDt=(Math::clampf(fend/255.0,0,1.0f)-p->m_colorRed)/lifetime;

	fbegin=m_startColor.g+m_startColorVar.g*Math::random(0.0f,1.0f);
	fend=m_endColor.g+m_endColorVar.g*Math::random(0.0f,1.0f);
	p->m_colorGreen=Math::clampf(fbegin/255.0,0,1.0f);
	p->m_colorGreenDt=(Math::clampf(fend/255.0,0,1.0f)-p->m_colorGreen)/lifetime;

	fbegin=m_startColor.b+m_startColorVar.b*Math::random(0.0f,1.0f);
	fend=m_endColor.b+m_endColorVar.b*Math::random(0.0f,1.0f);
	p->m_colorBlue=Math::clampf(fbegin/255.0,0,1.0f);
	p->m_colorBlueDt=(Math::clampf(fend/255.0,0,1.0f)-p->m_colorBlue)/lifetime;

	fbegin=m_startColor.a+m_startColorVar.a*Math::random(0.0f,1.0f);
	fend=m_endColor.a+m_endColorVar.a*Math::random(0.0f,1.0f);
	p->m_colorAlpha=Math::clampf(fbegin/255.0,0,1.0f);
	p->m_colorAlphaDt=(Math::clampf(fend/255.0,0,1.0f)-p->m_colorAlpha)/lifetime;

	p->m_angle=m_angle+m_angleVar*Math::random(0.0f,1.0f);

	fbegin=m_startRotation+m_startRotationVar*Math::random(0.0f,1.0f);
	fend=m_endRotation+m_endRotationVar*Math::random(0.0f,1.0f);

	p->m_rotation=fbegin;
	p->m_rotationDt=(fend-fbegin)/lifetime;

	p->m_position=m_position+m_positionVar*Math::random(0.0f,1.0f);

	p->m_startPos=p->m_position;

	p->m_gravityMode.m_gravity=m_gravity;
	p->m_gravityMode.m_speed=m_speed+m_speedVar*Math::random(0.0f,1.0f);
	p->m_gravityMode.m_radialAcceleration=m_radialAcceleration+m_radialAccelerationVar*Math::random(0.0f,1.0f);
	p->m_gravityMode.m_tangentialAcceleration=m_tangentialAcceleration+m_tangentialAccelerationVar*Math::random(0.0f,1.0f);


	fbegin=m_startRadius+m_startRadiusVar*Math::random(0.0f,1.0f);
	fend=m_endRadius+m_endRadiusVar*Math::random(0.0f,1.0f);

	p->m_radialMode.m_radius=fbegin;
	p->m_radialMode.m_radiusDt=(fend-fbegin)/m_lifeTime;
	p->m_radiusDt.m_angleDt=m_rotateSpeed+m_rotateSpeedVar*Math::random(0.0f,1.0f);
}



ParticleEmitter::ParticleEmitter()
	:m_durationTime(0),
	m_durationTimeVar(0),
	m_maxParticleNu(0),
	m_emitSpeed(0),
	m_lifeTime(0),
	m_lifeTimeVar(0),
	m_startSize(0),
	m_startSizeVar(0),
	m_endSize(0),
	m_endSizeVar(0),
	m_startColor(255,255,255,255),
	m_startColorVar(0,0,0,0),
	m_endColor(255,255,255,255),
	m_endColorVar(0,0,0,0),
	m_angle(0),
	m_angleVar(0),
	m_startRotation(0),
	m_startRotationVar(0),
	m_endRotation(0),
	m_endRotationVar(0),
	m_position(0,0),
	m_positionVar(0,0),
	m_moveMode(FOLLOW_MOVE),
	m_blendSrc(Render::FACTOR_ONE),
	m_blendDst(Render::FACTOR_ONE_MINUS_SRC_ALPHA),
	m_texture(NULL),
	m_enviromentMode(ENV_GRAVITY),
	m_speed(0),
	m_speedVar(0),
	m_gravity(0,0),
	m_radialAcceleration(0),
	m_radialAccelerationVar(0),
	m_tangentialAcceleration(0),
	m_tangentialAccelerationVar(0),
	m_beginRadius(0),
	m_beginRadiusVar(0),
	m_endRadius(0),
	m_endRadiusVar(0),
	m_rotateSpeed(0),
	m_rotateSpeedVar(0)
{
}

bool ParticleEmitter::init()
{
	return true;
}

bool ParticleEmitter::init(const char* filename)
{
	FsFile* file=VFS::open(filename);
	if(file==NULL)
	{
		FS_TRACE_WARN("can't open file:%s for particle",filename);
		return NULL;
	}
	bool ret=init(file);
	file->decRef();
	return ret;
}

bool ParticleEmitter::init(FsFile* file)
{
	FsDict* dict=ScriptUtil::parseScript(file);

	if(dict==NULL)
	{
		FS_TRACE_WARN("Parse file for particle Failed");
		return false;
	}

	FsDict* emmitor=ScriptUtil::getDict(dict,"emittor");
	if (!emmitor) 
	{
		FS_TRACE_WARN("Can't Get Emmitor Infoamtion");
	}
	else 
	{
		ScriptUtil::getFloat(emittor,"durationTime",&m_durationTime);
		ScriptUtil::getFloat(emittor,"durationTimeVar",&m_durationTimeVar);
		ScriptUtil::getInteger(emittor,"emitSpeed",&m_emitSpeed);
		ScriptUtil::getInteger(emittor,"maxParticleNu",&m_maxParticleNu);
	}
	emittor->decRef();

	FsDict* particle=ScriptUtil::getDict(dict,"particle");
	if(!particle)
	{
		FS_TRACE_WARN("Can't Get Particle Information");
	}
	else 
	{
		ScriptUtil::getFloat(particle,"lifeTime",&m_lifeTime);
		ScriptUtil::getFloat(particle,"lifetimeVar",&m_lifeTimeVar);
		ScriptUtil::getFloat(particle,"startSize",&m_startSize);
		ScriptUtil::getFloat(particle,"startSizeVar",&m_startSizeVar);
		ScriptUtil::getFloat(particle,"endSize",&m_endSize);
		ScriptUtil::getFloat(particle,"endSizeVar",&m_endSizeVar);

		FsArray* start_color=ScriptUtil::getArray(particle,"startColor");
		if(start_color)
		{
			ScriptUtil::getInteger(start_color,0,&m_startColor.r);
			ScriptUtil::getInteger(start_color,1,&m_startColor.g);
			ScriptUtil::getInteger(start_color,2,&m_startColor.b);
			ScriptUtil::getInteger(start_color,3,&m_startColor.a);
		}

		FsArray* start_color_var=ScriptUtil::getArray(particle,"startColorVar");
		if (start_color_var)
		{
			ScriptUtil::getInteger(start_color_var,0,&m_startColorVar.r);
			ScriptUtil::getInteger(start_color_var,1,&m_startColorVar.g);
			ScriptUtil::getInteger(start_color_var,2,&m_startColorVar.b);
			ScriptUtil::getInteger(start_color_var,3,&m_startColorVar.a);
		}

		FsArray* end_color=ScriptUtil::getArray(particle,"endColor");
		if(end_color)
		{
			ScriptUtil::getInteger(end_color,0,&m_endColor.r);
			ScriptUtil::getInteger(end_color,1,&m_endColor.g);
			ScriptUtil::getInteger(end_color,2,&m_endColor.b);
			ScriptUtil::getInteger(end_color,3,&m_endColor.a);
		}


		FsArray* end_color_var=ScriptUtil::getArray(particle,"endColorVar");
		if(end_color_var)
		{
			ScriptUtil::getInteger(end_color_var,0,&m_endColorVar.r);
			ScriptUtil::getInteger(end_color_var,1,&m_endColorVar.g);
			ScriptUtil::getInteger(end_color_var,2,&m_endColorVar.b);
			ScriptUtil::getInteger(end_color_var,3,&m_endColorVar.a);
		}
		FS_SAFE_DEC_REF(start_color);
		FS_SAFE_DEC_REF(start_color_var);
		FS_SAFE_DEC_REF(end_color);
		FS_SAFE_DEC_REF(end_color_var);

		ScriptUtil::getFloat(particle,"angle",&m_angle);
		ScriptUtil::getFloat(particle,"angleVar",&m_angleVar);
		ScriptUtil::getFloat(particle,"startRotation",&m_rotation);
		ScriptUtil::getFloat(particle,"startRotationVar",&m_rotationVar);

		FsArray* position=ScriptUtil::getArray(particle,"position");
		if(position)
		{
			ScriptUtil::getFloat(position,0,&m_position.x);
			ScriptUtil::getFloat(position,1,&m_position.y);
		}
		FS_SAFE_DEC_REF(position);

		FsArray* position_var=ScriptUtil::getArray(particle,"positionVar");
		if(position_var)
		{
			ScriptUtil::getFloat(position_var,0,&m_positionVar.x);
			ScriptUtil::getFloat(position_var,1,&m_positionVar.y);
		}
		FS_SAFE_DEC_REF(position_var);

		FsString* move_mode=ScriptUtil::getString(particle,"moveMode");
		if(move_mode)
		{
			if(move_mode->equal("free"))
			{
				m_moveMode=MOVE_FREE;
			}
			else if(move_mode->equal("group"))
			{
				m_moveMode=MOVE_GROUP;
			}
		}
		FS_SAFE_DEC_REF(move_mode);
	}
	FS_SAFE_DEC_REF(particle);

	FsDict* texture=ScriptUtil::getDict(dict,"texture");
	if(texture)
	{
		FsString* blendSrc=ScriptUtil::getString(texture,"blendSrc");
		if(blendSrc)
		{
			if(blendSrc->equal(" xxx x"))
			{
				/* TODO */
			}
		}
		FS_SAFE_DEC_REF(blendSrc);


		FsString* blendDst=ScriptUtil::getString(texture,"blendDst")
		if(blendDst)
		{
			if(blendDst->equal("xxx xxx"))
			{
				/* TODO */
			}
		}
		FS_SAFE_DEC_REF(blendDst);

		FsString* url=ScriptUtil::getString(texture,"url");
		if(url)
		{
			Texture2D* t=Global::textureMgr()->loadTexture(url.cstr());
			m_texture=t;
		}
		FS_SAFE_DEC_REF(url);

	}
	

	FsDict* environment=ScriptUtil::getDict(dict,"environment");
	if(environment)
	{
		FsString* mode=ScriptUtil::getString(dict,"mode");
		if(mode)
		{
			if(mode->equal("gravity"))
			{
				m_enviromentMode=ENV_GRAVITY;
			}
			else if(mode->equal("radial"))
			{
				m_enviromentMode=ENV_RADIAL;
			}
		}
		FS_SAFE_DEC_REF(mode);

		FsDict* gravity=ScriptUtil::getString(dict,"gravity");
		if(gravity)
		{
			ScriptUtil::getFloat(gravity,"speed",&m_speed);
			ScriptUtil::getFloat(gravity,"speedVar",&m_speedVar);

			FsArray* g=ScriptUtil::getArray(gravity,"gravity");
			if(g)
			{
				ScriptUtil::getFloat(g,0,&m_gravity.x);
				ScriptUtil::getFloat(g,1,&m_gravity.y);
			}
			FS_SAFE_DEC_REF(g);
			ScriptUtil::getFloat(gravity,"radialAcceleration",m_radialAcceleration);
			ScriptUtil::getFloat(gravity,"radialAccelerationVar",m_radialAccelerationVar);
			ScriptUtil::getFloat(gravity,"tangentialAcceleration",m_tangentialAcceleration);
			ScriptUtil::getFloat(gravity,"tangentialAccelerationVar",m_tangentialAccelerationVar);
		}
		FS_SAFE_DEC_REF(gravity);

		FsDict* radial=ScriptUtil::getString(dict,"radial");
		if(radial)
		{
			ScriptUtil::getFloat(radial,"beginRadius",&m_beginRadius);
			ScriptUtil::getFloat(radial,"beginRadiusVar",&m_beginRadiusVar);
			ScriptUtil::getFloat(radial,"rotateSpeed",&m_rotateSpeed);
			ScriptUtil::getFloat(radial,"rotateSpeedVar",&m_rotateSpeedVar);
		}
		FS_SAFE_DEC_REF(radial);

	}
	return true;

}

NS_FS_END
















