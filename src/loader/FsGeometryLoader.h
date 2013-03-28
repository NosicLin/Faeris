#ifndef _FS_GEOMETRY_LOADER_H_
#define _FS_GEOMETRY_LOADER_H_

#include "FsMacros.h"
#include "mgr/FsResourceMgr.h"


NS_FS_BEGIN

class Geometry;
class FsFile;
class FsDict;
class GeometryLoader
{
	public:
		static Geometry* create(const char* filename);
		static Geometry* create(FsFile* file);
		static void saveGeometry(Geometry* g,FsFile* file,int type);
	public:
		static Geometry* createFromScript(FsFile* file);
		static Geometry* createFromDict(FsDict* dict);
		static Geometry* createFromBinary(FsFile* file);
		static void saveGeometryWithScript(Geometry* g,FsFile* file);
		static void saveGeometryWithBinary(Geometry* g,FsFile* file);
};

NS_FS_END 

#endif /*_FS_GEOMETRY_LOADER_H_*/

