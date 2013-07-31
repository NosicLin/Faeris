#include <string.h>
#include "support/util/FsPathUtil.h"


NS_FS_BEGIN

bool PathUtil::absolutePath(const char* name)
{
	if(name[0]=='/')
	{
		return true;
	}
	return false;
}

std::string PathUtil::getDirName(const char* name)
{
	int split=0;
	int name_len=strlen(name);
	for(int i=name_len-1;i>=0;i--)
	{
		if(name[i]=='/')
		{
			split=i;
			break;
		}
	}
	return std::string(name,split);

}
std::string PathUtil::getFileName(const char* name)
{
	int split=0;
	int name_len=strlen(name);
	for(int i=name_len-1;i>=0;i--)
	{
		if(name[i]=='/')
		{
			split=i;
			break;
		}
	}
	return std::string(name+split);
}
std::string PathUtil::toStdPath(const char* name)
{
	std::string ret(name);

	int length=ret.size();
	for(int i=0;i<length;i++)
	{
		if(ret[i]=='\\')
		{
			ret[i]='/';
		}
	}
	return ret;
}
NS_FS_END


