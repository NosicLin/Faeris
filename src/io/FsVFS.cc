#include "FsVFS.h"
#include "FsSysFile.h"

NS_FS_BEGIN

FS_BEGIN_NAMESPACE(VFS)

FsFile* open(const char* name,uint mode)
{
	return SysFile::open(name,mode);
}

FsFile* getStdout()
{
	return SysFile::getStdout();
}
FsFile* getStdin()
{
	return SysFile::getStdin();
}
FsFile* getStderr()
{
	return SysFile::getStderr();
}





FS_END_NAMESPACE(VFS)
NS_FS_END

