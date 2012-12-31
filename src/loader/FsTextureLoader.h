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
		static Texture2D* loadFromMgr(const FsChar* filename);
		static Texture2D* loadFromFile(FsFile* file);
		static Texture2D* loadFromScriptFile(FsFile* file);
		static Texture2D* loadFromBinaryFile(FsFile* file);
		static FsInt checkFileType(FsFile* file);
};


NS_FS_END

#endif /*_FS_TEXTURE_LOADER_H_*/

