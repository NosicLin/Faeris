#ifndef _FS_COLOR_QUAD_2D_H_
#define _FS_COLOR_QUAD_2D_H_

#include "entity/FsEntity.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN

/* points
 *   D ------ C
 *   |        |
 *   |        |
 *   A ------ B
 */

class PositionColorMaterial;
class ColorQuad2D:public Entity
{
	public:
		enum 
		{
			VERTEX_A=0x1,
			VERTEX_B=0x2,
			VERTEX_C=0x4,
			VERTEX_D=0x8,
			VERTEX_ALL=VERTEX_A|VERTEX_B|VERTEX_C|VERTEX_D,
		};

	public:
		static ColorQuad2D* create();
		static ColorQuad2D* create(const Rect2D& rect,Color c);
		static ColorQuad2D* create(float width,float height,Color c);

	public:
		/* inherit Entity */
		virtual void update(float dt);
		virtual void draw(Render* render,bool updateMatrix=true);
		virtual bool hit2D(float x,float y);

		/* inherit FsObject */
		virtual const char* className()const;


	public:
		void setColor(Color c,int vertex=VERTEX_ALL);
		void setRect(const Rect2D& rect);
		void setOpacity(float opacity);
		float getOpacity();

	protected:
		ColorQuad2D();
		~ColorQuad2D();
		void init(const Rect2D& rect,Color c);
		void init(float width,float height,Color c);
		void init();
		void destroy();

	private:
		Color m_va;
		Color m_vb;
		Color m_vc;
		Color m_vd;
		Rect2D m_rect;
		float m_opacity;
		PositionColorMaterial* m_material;
};

NS_FS_END

#endif /*_FS_COLOR_QUAD_2D_H_*/



