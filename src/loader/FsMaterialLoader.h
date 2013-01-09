#ifndef _FS_MATERIAL_LOADER_H_
#define _FS_MATERIAL_LOADER_H_ 
#include "FsMacros.h"
#include "material/FsMaterial.h"
#include "util/FsResourceMgr.h"

NS_FS_BEGIN 
class FsFile;
class MaterialLoader 
{
	private:
		static ResourceMgr* m_mgr;
	public:
		static ResourceMgr* getMgr();
		static loadFromMgr(const FsChar* name);
	public:
		Material* create(FsChar* name);
		Material* create(FsFile* file);

		ShaderMaterial* createShaderMaterial(FsFile* file);
	public:
		Material* createFromScript(FsFile* file);
		Material* createFromBinary(FsFile* file);
	protected:
		void setMatrial(Material* mat,FsDict* dict);
		void setShaderMaterial(ShaderMaterial* mat,FsDict* dict);

};

NS_FS_END 

#define _FS_MATERIAL_LOADER_H_

