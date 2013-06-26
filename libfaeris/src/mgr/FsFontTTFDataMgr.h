#ifndef _FS_FONT_TTF_DATA_MGR_H_
#define _FS_FONT_TTF_DATA_MGR_H_

#include "mgr/FsResourceMgr.h"

NS_FS_BEGIN
class FontTTFData;
class FontTTFDataMgr:public ResourceMgr
{
	public:
		static FontTTFDataMgr* create();

	public:
		FontTTFData* loadFontTTFData(const char* name);

	public:
		virtual const char* className();

	protected:
		FontTTFDataMgr();
		virtual ~FontTTFDataMgr();

};


NS_FS_END


#endif /*_FS_FONT_TTF_DATA_MGR_H_*/

