#include "mgr/FsFontTTFDataMgr.h"
#include "graphics/FsFontTTF.h"

NS_FS_BEGIN
FontTTFDataMgr* FontTTFDataMgr::create()
{
	return  new FontTTFDataMgr;
}

FontTTFData* FontTTFDataMgr::loadFontTTFData(const char* name)
{
	return (FontTTFData*)load(name);
}

const char* FontTTFDataMgr::className()
{
	return FS_FONT_TTF_DATA_MGR_CLASS_NAME;
}

FontTTFDataMgr::FontTTFDataMgr()
	:ResourceMgr((ResourceMgr::ResourceCreateFunc)FontTTFData::create)
{
}

FontTTFDataMgr::~FontTTFDataMgr()
{
}
NS_FS_END



