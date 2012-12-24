#ifndef _FS_SCRIPT_UTIL_H_
#define _FS_SCRIPT_UTIL_H_

#include "FsMacros.h"
#include "util/FsDict.h"
#include "util/FsArray.h"
#include "util/FsString.h"
#include "fsys/FsFile.h"

FAERIS_NAMESPACE_BEGIN
class ScriptUtil
{
	public:
		static FsDict* parseScript(FsFile* file);
		static bool saveScript(FsFile* file,FsDict* dict,FsInt indent=0);

		/* if NULL return mean this no need to escape src */
		static FsChar* escapeStringToOrign(const FsChar* src);

		/* aux for quick get object in dict */
		static FsArray* getArray(FsDict* dict,const FsChar* key);
		static FsDict* getDict(FsDict* dict,const FsChar* key);
		static FsString* getString(FsDict* dict,const FsChar* key);
		static FsBool getInteger(FsDict* dict,const FsChar* key,FsInt* value);
		static FsBool getFloat(FsDict* dict,const FsChar* key,FsFloat* value);

		/* aux for translate string to float,integer*/
		static FsFloat parseFloat(const FsChar* str);
		static FsFloat parseFloat(FsString* str)
		{
			return parseFloat(str->cstr());
		}

		static FsInt parseInteger(const FsChar* str);
		static FsInt parseInteger(FsString* str)
		{
			return parseInteger(str->cstr());
		}
	
};

FAERIS_NAMESPACE_END 



#endif /*_FS_SCRIPT_UTIL_H_*/

