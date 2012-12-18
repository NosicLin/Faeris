#include "FsObject.h"

FAERIS_NAMESPACE_BEGIN 

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
FAERIS_NAMESPACE_END 

