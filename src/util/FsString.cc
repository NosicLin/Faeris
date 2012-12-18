#include "util/FsString.h"

static FsChar* s_FsStringName="FsStringObject";

FAERIS_NAMESPACE_BEGIN
size_t FsString::getHashCode()const
{
	return m_hash_code;
}

const char* FsString::getName()const 
{
	return s_FsStringName;
}

FsBool FsString::checkType(FsObject* ob)
{
	return ob->getName()==s_FsStringName();
}

FAERIS_NAMESPACE_END

