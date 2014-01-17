#ifndef _FS_RICH_LABEL_TTF_H_
#define _FS_RICH_LABEL_TTF_H_ 


#include "FsMacros.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN
class RichLabelTTF 
{
	public:
		static RichLabelTTF* create(const char* ttf_file,int size);
		static RichLabelTTF* create(const char* ttf_file);


};


NS_FS_END 


#endif /*_FS_RICH_LABEL_TTF_H_*/

