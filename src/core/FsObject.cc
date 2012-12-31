#include "FsObject.h"

NS_FS_BEGIN 

FsObject::~FsObject()
{
}
void FsObject::onDestory()
{
	delete this;
}
FsLong FsObject::getHashCode()
{
	return (FsLong)this;
}
FsBool FsObject::equal(FsObject* ob)
{
	return this==ob;
}
NS_FS_END 

