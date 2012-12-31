#ifndef _FAERY_FACE3_H_
#define _FAERY_FACE3_H_

#include "FsMacros.h"

NS_FS_BEGIN
class Face3 
{
	public:
		union
		{
			struct
			{
				FsUint a;
				FsUint b;
				FsUint c;
			};
			FsUint v[3];
		};
	public:
		Face3(FsUint _a,FsUint _b,FsUint _c)
			:a(_a),b(_b),c(_c)
		{}
		Face3(){}
};
NS_FS_END

#endif 

