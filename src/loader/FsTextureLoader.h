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
		static ResourceMgr* getMgr();
		static Texture2D* loadFromMgr(const FsChar* filename);

	public:
		static Texture2D* create(const FsChar* name);
		static Texture2D* create(FsFile* file);
		static Texture2D* createFromScript(FsFile* file);
		static Texture2D* createFromBinary(FsFile* file);
};


NS_FS_END

#endif /*_FS_TEXTURE_LOADER_H_*/

