#ifndef _FAERY_FACE3_H_
#define _FAERY_FACE3_H_

#include "FsMacros.h"

FAERIS_NAMESPACE_BEGIN
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
FAERIS_NAMESPACE_END

#endif 

