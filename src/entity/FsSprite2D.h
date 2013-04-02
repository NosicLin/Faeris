#ifndef _FS_SPRITE_2D_H_
#define _FS_SPRITE_2D_H_

#include "FsMacros.h"
#include "entity/FsEntity.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN

class Sprite2DData;
class Texture2D;
class FsArray;
class Sprite2DAnimation;
class PositionAlphaTextureMaterial;

class Sprite2D :public Entity 
{
	public:
		enum
		{
			ANIM_LOOP,
			ANIM_START,
			ANIM_END,
		};
	public:
		static Sprite2D* create(const char* name);

	public:

		/* color */
		void setColor(Color color);
		Color getColor();

		/* opacity */
		void setOpacity(float opacity);
		float getOpacity();

		/* animation */
		void setAnimation(const char* name);
		void updateAnimation(float dt);

		void playAnimation(int mode=ANIM_LOOP);
		void startAnimation(int mode=ANIM_LOOP);
		void stopAnimation();

		bool isAnimationPlaying();


		/* frame */
		void setCurFrame(int frame);
		int getCurFrame();
		int getTotalFrame();

		/* fps */
		int getFps();

	public:
		/* inherit Entity */
		virtual void update(float dt);
		virtual void draw(Render* render,bool update_matrix=true);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		bool init(Sprite2DData* data);
		void setAnimation(Sprite2DAnimation* anim);
		Sprite2D();
		~Sprite2D();

	private:
		Color  m_color;
		float m_opacity;

		int m_curFrame;
		int m_elapseTime;

		int m_mode;
		int m_stop;

		Sprite2DData* m_data;
		Sprite2DAnimation* m_curAnimation;
		FsArray* m_textures;

		/* material */

		PositionAlphaTextureMaterial* m_material;
};



NS_FS_END


#endif /*_FS_SPRITE_2D_H_*/




