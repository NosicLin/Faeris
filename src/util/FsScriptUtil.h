#ifndef _FS_SCRIPT_UTIL_H_
#define _FS_SCRIPT_UTIL_H_

#include "FsMacros.h"
#include "util/FsDict.h"
#include "fsys/FsFile.h"

FAERIS_NAMESPACE_BEGIN
class ScriptUtil
{
	public:
		static FsDict* parseScript(FsFile* file);
		static bool saveScript(FsFile* file,FsDict* dict,FsInt indent=0);
};

FAERIS_NAMESPACE_END 



#endif /*_FS_SCRIPT_UTIL_H_*/

