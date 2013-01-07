#ifndef _FS_PROGRAM_LOADER_H_
#define _FS_PROGRAM_LOADER_H_ 
#include "graphics/FsProgram.h"
#include "util/FsResourceMgr.h"

NS_FS_BEGIN
class ProgramLoader
{
	public:
		/* load from mgr,it program already load before,
		 * it will return the program create before,
		 * if the program is the first time to load, mgr
		 * will create it and cache it
		 */
		static Program* loadFromMgr(const FsChar* name);
		static ResourceMgr* getMgr();
	public:
		/* it will check the file type */
		static Program* create(const char* FsFile* file);

		/* caller must make sure the file is the right type */
		static Program* createFromScript(FsFile* file);
		static Program* createFromBinary(FsFile* file);
		static Program* createFromDict(FsDict* file);
};

NS_FS_END

#endif /*_FS_PROGRAM_LOADER_H_*/

