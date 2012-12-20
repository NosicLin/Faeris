#ifndef _FS_UTIL_STRING_INL_
#define _FS_UTIL_STRING_INL_

#include "FsMacros.h"
#include "util/FsStringUtil.h"

FAERIS_NAMESPACE_BEGIN
inline FsString::FsString():m_string("")
{
	mCalHashCode();
}
inline FsString::FsString(const FsChar* str):m_string(str)
{
	mCalHashCode();
}
inline FsString& FsString::append(const FsChar* str)
{
	m_string.append(str);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::append(const FsChar* str,FsLong n)
{
	m_string.append(str,n);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::append(const FsString& str)
{
	m_string.append(str.m_string);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::append(const FsString& str,FsLong n)
{
	m_string.append(str.m_string,0,n);
	mCalHashCode();
	return *this;
}

inline FsString& FsString::assign(const FsString& str)
{
	m_string.assign(str.m_string);
	m_hash_code=str.m_hash_code;
	return *this;
}
inline FsString& FsString::assign(const FsString& str,FsLong n)
{
	m_string.assign(str.m_string,0,n);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::assign(const FsChar* str)
{
	m_string.assign(str);
	mCalHashCode();
	return *this;
}
inline FsString& FsString::assign(const FsChar* str,FsLong n)
{
	m_string.assign(str,n);
	mCalHashCode();
	return *this;
}
inline void FsString::clear()
{
	m_string.clear();
	mCalHashCode();
}
inline int FsString::compare(const FsString& str)const 
{
	return m_string.compare(str.m_string);
}
inline int FsString::compare(const FsChar* str)const
{
	return m_string.compare(str);
}
inline const FsChar* FsString::cstr()const
{
	return m_string.c_str();
}
inline bool FsString::empty()const 
{
	return m_string.empty();
}
inline FsUlong FsString::length()const 
{
	return m_string.length();
}
inline FsString& FsString::erase(FsLong pos,FsLong num)
{
	m_string.erase(pos,num);
	return *this;
}
inline void FsString::mCalHashCode()
{
	m_hash_code=FsUtil_JStringHashCode(m_string.c_str());
	if(m_hash_code==FS_INVALID_HASH_CODE)
	{
		m_hash_code+=1;
	}
}

inline FsChar FsString::operator[](FsUlong n)const 
{
	FS_ASSERT(n<length());
	return m_string[n];
}

FAERIS_NAMESPACE_END

#endif /*_FS_UTIL_STRING_INL_*/





