#ifndef _FS_PROGRAM_LOADER_H_
#define _FS_PROGRAM_LOADER_H_ 
#include "graphics/FsProgram.h"
#include "mgr/FsResourceMgr.h"

NS_FS_BEGIN
class Program;
class ProgramLoader
{
	public:
		/* it will check the file type */
		static Program* create(const char* name);
		static Program* create(FsFile* file);

		/* caller must make sure the file is the right type */
		static Program* createFromScript(FsFile* file);
		static Program* createFromBinary(FsFile* file);
		static Program* createFromDict(FsDict* file);
};

NS_FS_END

#endif /*_FS_PROGRAM_LOADER_H_*/

