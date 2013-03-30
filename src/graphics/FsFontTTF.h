#ifndef _FS_FONT_TTF_H_
#define _FS_FONT_TTF_H_
#include "FsMacros.h"
#include "mgr/FsResource.h"

NS_FS_BEGIN


class GlyphMetrices
{
	public:

}
class Glyph:public FsObject
{
	public:


};


class FontTTFData:public FsResource
{

};


class FontTTF
{
	public:
		FontTTF* create(const char* name,int size);

	private:
		FontTTFData* m_data;
		int m_size;
};



#endif /*_FS_FONT_TTF_H_*/

