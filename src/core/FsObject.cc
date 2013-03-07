#include "FsObject.h"

NS_FS_BEGIN 

FsObject::~FsObject()
{
}

long FsObject::getHashCode()
{
	return (long)this;
}

bool FsObject::equal(FsObject* ob)
{
	return this==ob;
}
NS_FS_END 

