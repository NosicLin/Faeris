#ifndef FY_MATH_VECTOR4_H_
#define FY_MATH_VECTOR4_H_
#include "FsMacros.h"
#include "FsMathUtil.h"

NS_FS_BEGIN
class Vector4
{
	public:
		union
		{
			struct 
			{
				FsFloat x;
				FsFloat y;
				FsFloat z;
				FsFloat w;
			};
			FsFloat v[4];
		};
	public:
		Vector4(FsFloat fx,FsFloat fy,FsFloat fz,FsFloat fw);
		Vector4(FsFloat fx,FsFloat fy,FsFloat fz);
		Vector4();
		Vector4 add(const Vector4& v)const ;
		Vector4 sub(const Vector4& v)const;
		Vector4 scale(FsFloat k)const ;
		FsFloat dot(const Vector4& v)const;

		Vector4 normal() const ;
		FsVoid normalize() ;
		FsFloat length() const;
		FsFloat length2() const;

		FsBool equal(const Vector4& v) const;
};

#include"FsVector4.inl"

NS_FS_END
#endif



