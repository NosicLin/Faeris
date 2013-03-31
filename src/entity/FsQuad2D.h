#ifndef _FS_QUAD_2D_H_
#define _FS_QUAD_2D_H_ 

#include "FsMacros.h"
#include "entity/FsEntity.h"
#include "math/FsRect2D.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN
class Texture2D;
class PositionTextureMaterial;
class Quad2D:public Entity 
{
	public:
		static Quad2D* create(const char* tex);

	public:

		/* color */
		void setColor(Color c);
		Color getColor();

		/* opacity */
		void setOpacity(float opacity);
		float getOpacity();

		/* texture */
		void setTexture(Texture2D* tex);
		Texture2D* getTexture();

		/* texture coord */
		void setTextureCoord(const Rect2D& coord);
		Rect2D getTextureCoord();


		/* Rect2D */
		void setRect2D(const Rect2D& rect);
		Rect2D getRect2D();
	public:
		virtual void draw(Render* r,bool updateMatrix);
		virtual const char* className();


	protected:
		Quad2D();
		~Quad2D();
		bool init(const char* tex);
		bool init(Texture2D* tex);
		void destory();

	private:
		Rect2D m_rect;
		Rect2D m_textureCoord;
		Texture2D* m_texture;
		Color m_color;
		float m_opacity;

		PositionTextureMaterial* m_material;
};




NS_FS_END 



#endif /*_FS_QUAD_2D_H_*/

