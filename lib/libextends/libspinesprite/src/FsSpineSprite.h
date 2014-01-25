#ifndef _FS_SPINE_SPRITE_H_
#define _FS_SPINE_SPRITE_H_
#include "spine/spine.h"
#include "FsMacros.h"
#include "FsObject.h"
#include "graphics/FsColor.h"
#include "stage/entity/FsEntity.h"
#include "graphics/material/FsMat_V4F_T2F.h"
#include "FsSpineSpriteData.h"
#include "FsSpineSpriteDataMgr.h"

NS_FS_BEGIN
class Render;
class SpineSprite:public Entity 
{
	public:
		enum
		{
			ANIM_LOOP,
			ANIM_START,
			ANIM_END,
		};
	public:
		static SpineSprite* create(const char* filename);

	public:
		/* skin */
		bool setSkin(const char* skin);

		/* color */
		void setColor(Color c);
		Color getColor();

		/* opacity */
		void setOpacity(float opacity);
		float getOpacity();

		/* animation */
		void updateAnimation(float dt);
		void setAnimation(const char* anim);


		void playAnimation(int mode=ANIM_LOOP);
		void startAnimation(int mode=ANIM_LOOP);
		void stopAnimation();
		bool isAnimationPlaying();


		/* time */
		void setCurTime(float time);
		float getCurTime();
		float getDurationTime();


	public:
		virtual void update(float dt);
		virtual void draw(Render* render,bool update_matrix=true);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		bool init(const char* name);
		void destruct();
		SpineSprite();
		virtual ~SpineSprite();

	private:
		Color m_color;
		float m_opacity;
		float m_elapseTime;
		float m_duration;

		int m_mode;
		int m_stop;

		Skeleton* m_skeleton;
		SpineSpriteData* m_data;
		Mat_V4F_T2F* m_material;

		Animation* m_curAnimation;
};



NS_FS_END 

#endif /*_FS_SPINE_SPRITE_H_*/














