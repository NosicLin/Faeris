#ifndef _FS_MATERIAL_LOADER_H_
#define _FS_MATERIAL_LOADER_H_ 
#include "FsMacros.h"
#include "material/FsMaterial.h"
#include "material/FsShaderMaterial.h"

NS_FS_BEGIN 
class FsFile;
class FsDict;
class MaterialLoader 
{
	public:
		static Material* create(const char* name);
		static Material* create(FsFile* file);

		static ShaderMaterial* createShaderMaterial(FsFile* file);
	public:
		static Material* createFromScript(FsFile* file);
		static Material* createFromBinary(FsFile* file);
	protected:
		static void setMaterial(Material* mat,FsDict* dict);
		static void setShaderMaterial(ShaderMaterial* mat,FsDict* dict);

	public:
		/* debug */
		static void saveShaderMaterialWithScript(ShaderMaterial* mat,FsFile* file);


};

NS_FS_END 

#endif /*_FS_MATERIAL_LOADER_H_*/

