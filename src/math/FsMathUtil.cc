#include <math.h>
#include <stdlib.h>

#include "FsMathUtil.h"
#include "math/FsVector2.h"

NS_FS_BEGIN

void Math::srand(ulong s)
{
	::srand(s);
}

int Math::random()
{
	return ::rand();
}
int Math::random(int begin,int end)
{
	return begin+::rand()%(end-begin);
}
static float s_cross2d(const Vector2& u,const Vector2& v)
{
	return u.y*v.x-u.x*v.y;
}

bool Math::pointInTriangle2D(const Vector2& point,const Vector2& a,const Vector2& b,const Vector2& c)
{
	Vector2 pa=point.sub(a);
	Vector2 ba=b.sub(a);
	if(s_cross2d(pa,ba)<0.0f) return 0;

	Vector2 pb=point.sub(b);
	Vector2 cb=c.sub(b);
	if(s_cross2d(pb,cb)<0.0f) return 0;


	Vector2 pc=point.sub(c);
	Vector2 ac=a.sub(c);
	if(s_cross2d(pc,ac)<0.0f) return 0;

	return 1;
}



NS_FS_END


