#ifndef _FS_QUAD_2D_H_
#define _FS_QUAD_2D_H_ 

#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "math/FsRect2D.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN
class Texture2D;
class Mat_V4F_T2F;
class Quad2D:public Entity 
{
	public:
		static Quad2D* create(const char* tex);
		static Quad2D* create(const char* tex,const Rect2D& rect);
		static Quad2D* create(const char* tex,float width,float height);

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

		//void setTexture(const char* tex,bool new_rect=true); 


		/* texture coord */
		void setTextureCoord(const Rect2D& coord);
		Rect2D getTextureCoord();


		/* Rect2D */
		void setRect2D(const Rect2D& rect);
		Rect2D getRect2D();

		void setRectAnchor(float x,float y);

	public:
		/* inherit Entity */
		virtual void draw(Render* r,bool updateMatrix);
		virtual bool hit2D(float x,float y);

		/* inherit FsObject */
		virtual const char* className();


	protected:
		Quad2D();
		~Quad2D();
		bool init(const char* tex);
		bool init(Texture2D* tex);
		void destruct();

	private:
		Rect2D m_rect;
		Rect2D m_textureCoord;
		Texture2D* m_texture;
		Color m_color;
		float m_opacity;

		Mat_V4F_T2F* m_material;
};




NS_FS_END 



#endif /*_FS_QUAD_2D_H_*/

