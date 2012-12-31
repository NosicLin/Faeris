#include "FsVFS.h"
#include "FsSysFile.h"

NS_FS_BEGIN

FS_BEGIN_NAMESPACE(VFS)

FsFile* open(const FsChar* name,FsUint mode)
{
	return SysFile::open(name,mode);
}

FsFile* getStdout()
{
	return SysFile::getStdout();
}
FsFile* getStdinFile()
{
	return SysFile::getStdin();
}
FsFile* getStderr()
{
	return SysFile::getStderr();
}

FS_END_NAMESPACE(VFS)
NS_FS_END
