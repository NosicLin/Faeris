#ifndef _FS_PACKAGE_H_
#define _FS_PACKAGE_H_ 

#include "core/FsObject.h"

NS_FS_BEGIN

class FsFile;


enum 
{
	PACKAGE_UNKOWN=0,
	PACKAGE_ZIP,
	PACKAGE_RES,
};

class Package:public FsObject
{
	public:
		static Package* create(const char* filename,int pak_type=PACKAGE_UNKOWN);
		static Package* create(FsFile* file,int pak_type=PACKAGE_UNKOWN);
	public:
		virtual FsFile* getBlock(const char* file)=0;
		virtual ~Package(){}

};

NS_FS_END

#endif /*_FS_PACKAGE_H_*/
