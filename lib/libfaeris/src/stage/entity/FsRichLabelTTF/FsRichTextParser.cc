#include "FsRichTextParser.h"


RichTextParser::RichTextParser()
{
	m_color=Color.WHITE;
	m_u16str=NULL;
	m_strlength=0;
	m_curIndex=0;
}

RichTextParser::~RichTextParser()
{
	if(m_u16str)
	{
		delete m_u16str;
	}

}

void RichTextParser::setString(const char* u8str)
{
	uint16_t* u16str=FsUtf8_ToUtf16(u8str);
	int len=FsUtf16_StrLen(u16str);

	m_u16str=u16str;
	m_strlength=len;
	m_curIndex=0;
	m_color=Color.WHITE;
}

Color RichTextParser::getColor()
{
	return m_color;
}






