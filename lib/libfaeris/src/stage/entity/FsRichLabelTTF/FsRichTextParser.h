#ifndef _FS_RICH_TEXT_PARSER_H_
#define _FS_RICH_TEXT_PARSER_H_

#include "FsMacros.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN

class RichTextParser
{
	public:

		RichTextParser();
		~RichTextParser();

	public:

		void setString(const char* u8str);
		uint16_t  getNextWord(); 
		Color getColor();

	protected:

		void destory();
		bool parseSpecialString();

	private:
		Color m_color;
		uint16_t* m_u16str;
		int m_strlength;
		int m_curIndex;

};

NS_FS_END
#endif /*_FS_RICH_TEXT_PARSER_H_*/




