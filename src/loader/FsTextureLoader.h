#ifndef _FS_TEXTURE_LOADER_H_
#define _FS_TEXTURE_LOADER_H_
#include "FsMacros.h"
#include "graphics/FsTexture2D.h"
#include "util/FsResourceMgr.h"

NS_FS_BEGIN

class TextureLoader
{
	private:
		static ResourceMgr* m_mgr;
	public:
		static ResourceMgr* shareMgr();
	public:
		Texture2D* loadFromMgr(const FsChar* filename);
		Texture2D* loadFromFile(FsFile* file);
		Texture2D* loadFromScriptFile(FsFile* file);
		Texture2D* loadFromBinaryFile(FsFile* file);
		FsInt checkFileType(FsFile* file);
};


NS_FS_END

#endif /*_FS_TEXTURE_LOADER_H_*/

