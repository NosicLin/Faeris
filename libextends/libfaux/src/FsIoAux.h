#include "FsMacros.h"


NS_FS_BEGIN 

class IoAux
{
	public:
		/* @return 
		 * 		-1: failed 
		 * 		 0: success 
		 */

		static int savefile(const char* filename,uint8_t* buff,int32_t len);
		static int loadfile(const char* filename,uint8_t** buff,int32_t* len);
};

NS_FS_END 



