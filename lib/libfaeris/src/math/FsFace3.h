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
				uint32_t a;
				uint32_t b;
				uint32_t c;
			};
			uint32_t v[3];
		};
	public:
		Face3(uint32_t _a,uint32_t _b,uint32_t _c)
			:a(_a),b(_b),c(_c)
		{}
		Face3(){}
};
NS_FS_END

#endif 

