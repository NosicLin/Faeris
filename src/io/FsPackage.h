#ifndef _FS_PACKAGE_H_
#define _FS_PACKAGE_H_ 
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
		virtual Package(){}

};
#endif /*_FS_PACKAGE_H_*/
