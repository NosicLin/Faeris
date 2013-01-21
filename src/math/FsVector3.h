#ifndef FY_MATH_VECTORE3_H_
#define FY_MATH_VECTORE3_H_
#include "FsMathUtil.h"
NS_FS_BEGIN
class Vector3
{
	public:
		union
		{
			struct
			{
				FsFloat x;
				FsFloat y;
				FsFloat z;
			};
			FsFloat v[3];
		};
	public:
		Vector3(FsFloat _x,FsFloat _y,FsFloat _z);
		Vector3();
		Vector3 add(const Vector3& v) const ;
		Vector3 sub(const Vector3& v) const ;
		Vector3 scale(FsFloat k) const ;
		FsFloat dot(const Vector3& v) const ;
		Vector3 cross(const Vector3& v)const;
		Vector3 normal() const ;
		void normalize() ;
		Vector3 proj(const Vector3& v) const;
		FsFloat angle(const Vector3& v) const;
		FsFloat length() const;
		FsFloat length2() const;
		FsBool equal(const Vector3& v) const;
		FsVoid set(FsFloat _x,FsFloat _y,FsFloat _z);


};
#include "FsVector3.inl"
NS_FS_END
#endif 

