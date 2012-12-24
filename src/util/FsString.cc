#include <string.h>

#include "util/FsString.h"

static const FsChar* s_FsStringName="FsStringObject";

FAERIS_NAMESPACE_BEGIN

FsString::FsString(FsInt value)
{
	FsChar buf[128];
	sprintf(buf,"%d",value);
	m_string=std::string(buf);
	mCalHashCode();
}
FsLong FsString::getHashCode()
{
	return m_hash_code;
}

const FsChar* FsString::getName()
{
	return s_FsStringName;
}

FsBool FsString::checkType(FsObject* ob)
{
	return ob->getName()==s_FsStringName;
}
FsBool FsString::equal(FsObject* ob)
{
	if(!FsString::checkType(ob))
	{
		return false;
	}
	if(ob==this)
	{
		return true;
	}

	FsString* sob=(FsString*)ob;
	if(sob->getHashCode()!=getHashCode())
	{
		return false;
	}
	if(strcmp(m_string.c_str(),sob->m_string.c_str())==0)
	{
		return true;
	}
	else 
	{
		return false;
	}

}
FsBool FsString::equal(const FsChar* str)
{
	return strcmp(m_string.c_str(),str)==0;
}



FAERIS_NAMESPACE_END

