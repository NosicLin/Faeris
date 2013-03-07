#ifndef _FS_RESOURCE_MGR_H_
#define _FS_RESOURCE_MGR_H_ 

#include <string>
#include <vector>
#include <map>
#include "FsMacros.h"


NS_FS_BEGIN

class Resource;
class FsFile;
class Texture2D;
class Program;
class Mesh;
class Geometry;
class Material;

class ResourceMgr
{
	public:
		/* texture */
		static ResourceMgr* texture2DMgr();
		static Texture2D* loadTexture2D(const char* name);

		/* program */
		static ResourceMgr* programMgr();
		static Program* loadProgram(const char* name);

		/* mesh */
		static ResourceMgr* meshMgr();
		static Mesh* loadMesh(const char* name);

		/* geometry */
		static ResourceMgr* geometryMgr();
		static Geometry* loadGeometry(const char* name);

		/* material */
		static ResourceMgr* materialMgr();
		static Material* loadMaterial(const char* name);

		/* aux for all mgr*/
		static void purgeAllMgr();


	public:
		typedef Resource* (*ResourceCreateFunc)(FsFile* file);
	public:
		ResourceMgr(ResourceCreateFunc func);
	public:
		void addSearchPath(const char* path);
		bool existSearchPath(const char* path);
		void removeSearchPath(const char* path);
		Resource* load(const char* path,bool search_path=true);
		void remove(Resource* res);
		void setResouceRoot(const char* path);
	private:
		ResourceCreateFunc m_func;
};
NS_FS_END

#endif  /*_FS_RESOURCE_MGR_H_*/


