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

class ColorQuad2DMaterial;
class ColorQuad2D:Entity
{
	enum 
	{
		VERTEX_A=0x1,
		VERTEX_B=0x2,
		VERTEX_C=0x4,
		VERTEX_D=0x8,
		VERTEX_ALL=VERTEX_A|VERTEX_B|VERTEX_C|VERTEX_D,
	};

	public:
		static ColorQuad2D* create(const Rect2D& rect,Color c);

	public:
		/* inherit Entity */
		virtual void update(float dt);
		virtual void draw(Render* render);

		/* inherit FsObject */
		virtual const char* className()const;

	public:
		void setColor(Color c,int vertex=VERTEX_ALL);
		void setRect(const Rect2D& rect);
		void setOpacity(float opacity);

	protected:
		ColorQuad2D();
		~ColorQuad2D();
		void init(const Rect2D& rect,Color c);
		void destroy();

	private:
		Color m_va;
		Color m_vb;
		Color m_vc;
		Color m_vd;
		Rect2D m_rect;
		float m_opacity;

	private:
		static void unuseShareMaterial();
		static ColorQuad2DMaterial* useShareMaterial();
		static ColorQuad2DMaterial* m_shareMaterial;
};

NS_FS_END

#endif /*_FS_COLOR_QUAD_2D_H_*/



