#ifndef _FS_RECT_2D_H_
#define _FS_RECT_2D_H_
#include "FsMacros.h"
#include "math/FsVector2.h"
NS_FS_BEGIN

class Rect2D
{
	public:
		Rect2D(float x,float y,float width,float height);
		Rect2D(const Vector2& start,float width,float height);
		Rect2D();
	public:
		void setX(float x){m_x=x;}
		void setY(float y){m_y=y;}
		void setWidth(float width){m_width=width;}
		void setHeight(float height){m_height=height;}

		float x(){return m_x;}
		float y(){return m_y;}
		float width(){return m_width;}
		float height(){return m_height;}

	private:
		float m_x;
		float m_y;
		float m_width;
		float m_height;
};
NS_FS_END

#endif /*_FS_RECT_2D_H_*/

