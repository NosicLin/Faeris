#include "FsVFS.h"
#include "FsSysFile.h"

FAERIS_NAMESPACE_BEGIN

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
FAERIS_NAMESPACE_END
