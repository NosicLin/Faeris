#ifndef FS_MATH_UTIL_H_
#define FS_MATH_UTIL_H_

#include <math.h>
#include "FsMacros.h"

NS_FS_BEGIN
FS_BEGIN_NAMESPACE(Math)
#ifndef FS_PI 
#define FS_PI 3.1415926f
#endif 

inline float radianToAngle(float radian)
{
	return radian/FS_PI*180.0f;
}
inline float angleToRadian(float  angle)
{
	return angle/180.0f*FS_PI;
}

inline float cosr(float radian){return ::cosf(radian);}
inline float sinr(float radian){return ::sinf(radian);}
inline float tanr(float radian){return ::tanf(radian);}
inline float acosr(float radian){return ::acosf(radian);}

inline float cosa(float angle){return ::cosf(angleToRadian(angle));}
inline float sina(float angle){return ::sinf(angleToRadian(angle));}
inline float tana(float angle){return ::tanf(angleToRadian(angle));}
inline float acosa(float angle){return ::acosf(angleToRadian(angle));}

inline float sqrt(float v){return ::sqrt(v);}

template<typename T> T abs(T f){return f<0?-f:f;}

FsVoid srand(FsUlong s);
FsInt random();
FsInt random(FsInt begin,FsInt end);

inline FsInt floatEqual(float a,float b)
{
	return abs(a-b)<0.0001?1:0;
}

FS_END_NAMESPACE(Math)



NS_FS_END

#endif 

