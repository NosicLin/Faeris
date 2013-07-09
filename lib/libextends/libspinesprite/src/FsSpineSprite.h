#ifndef _FS_SPINE_SPRITE_H_
#define _FS_SPINE_SPRITE_H_
#include "spine/spine.h"
#include "FsMacros.h"
#include "core/FsObject.h"

NS_FS_BEGIN
class Render;
class SpineSprite:public FsObject 
{
	public:
		static SpineSprite* create(const char* filename);

	public:
		/* skin */
		int setSkin(const char* skin);

		/* color */
		void setColor(Color c);
		Color getColor();

		/* opacity */
		void setOpacity(float opacity);
		float getOpacity();

		/* animation */
		void updateAnimation(float dt);

		int setAnimation(const char* anim,bool loop=false);
		int addAnimation(const char* anim,bool loop=false,float delay=0.0f);
		int clearAnimation();


		void playAnimation();
		void startAnimation();
		void stopAnimation();
		bool isAnimationPlaying();


		/* time */
		void setCurTime(float time);
		float getCurTime(time);

		/* TODO (this is no api to call in spine runtimes)
		float getDurationTime();
		*/

	public:
		virtual void update(float dt);
		virtual void draw(Render* render,bool update_matrix=true);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		bool init(const char* name);
		SpineSprite();
		~SpineSprite();

	private:
		Color m_color;
		float m_opacity;
		float m_elapseTime;

		int m_stop;


		Skeleton* m_skeleton;
		AnimationState* m_animationState;
		AnimationStateData* m_animationStateData;

		Animation* m_curAnimation;

		SpineSpriteData* m_data;

		Mat_V4F_T2F_A1F* m_material;
};



NS_FS_END 

#endif /*_FS_SPINE_SPRITE_H_*/

