#ifndef _FS_GEOMETRY_LOADER_H_
#define _FS_GEOMETRY_LOADER_H_

#include "FsMacros.h"
#include "util/FsResourceMgr.h"


NS_FS_BEGIN
class Geometry;
class FsFile;
class FsDict;
class GeometryLoader
{
	private:
		static ResourceMgr* m_mgr;
	public:
		static ResourceMgr* getMgr();
		static Geometry* loadFromMgr(const FsChar* name);

	public:
		static Geometry* create(const FsChar* filename);
		static Geometry* create(FsFile* file);
		static void saveGeometry(Geometry* g,FsFile* file,FsInt type);
	public:
		static Geometry* createFromScript(FsFile* file);
		static Geometry* createFromDict(FsDict* dict);
		static Geometry* createFromBinary(FsFile* file);
		static void saveGeometryWithScript(Geometry* g,FsFile* file);
		static void saveGeometryWithBinary(Geometry* g,FsFile* file);
};

NS_FS_END 

#endif /*_FS_GEOMETRY_LOADER_H_*/

