#include "FsRichTextParser.h"


NS_FS_BEGIN

#define FS_L_COLOR_STR  u"<color="
#define FS_L_COLOR_LEN  (sizeof(FS_L_COLOR_STR)-2)

#define FS_L_LP_STR     u"<lp>"
#define FS_L_LP_LEN		(sizeof(FS_L_LP_STR)-2)

#define FS_L_RP		u"<rp>"






RichTextParser::RichTextParser()
{
	m_color=Color.WHITE;
	m_u16str=NULL;
	m_strlength=0;
	m_curIndex=0;
}


RichTextParser::~RichTextParser()
{
	destory();
}



void RichTextParser::destory()
{
	if(m_u16str)
	{
		delete m_u16str;
		m_u16str=NULL;
	}
}


void RichTextParser::setString(const char* u8str)
{
	destory():

	uint16_t* u16str=FsUtf8_ToUtf16(u8str);
	int len=FsUtf16_StrLen(u16str);

	m_u16str=u16str;
	m_strlength=len;
	m_curIndex=0;
	m_color=Color.WHITE;
}

uint16_t RichTextParser::getNextWord()
{

	while(parseSpecialString());

	if(m_curIndex>=m_strlength)
	{
		return 0;
	}

	uint16_t cur_char=m_u16str[m_curIndex];
	m_curIndex++;

	return cur_char;
}


bool RichTextParser::parseSpecialString()
{
	if(m_curIndex>=m_strlength)
	{
		return false;
	}

	uint16_t cur_char=m_u16str[m_curIndex];

	if(cur_char!='<')
	{
		return false;
	}

	int begin_index=m_curIndex;
	bool find_end=false;
	int end_index=begin_index;

	for(int i=m_curIndex+1;i<m_strlength;i++)
	{
		if(m_u16str[i]=='>')
		{
			find_end=true;
			end_index=i;
			break;
		}
	}

	if(!find_end)
	{
		FS_TRACE_WARN("Can't Find Character '>' After '<' ");
		m_curIndex=m_strlength;
		return false;
	}
	else 
	{

	}
}


Color RichTextParser::getColor()
{
	return m_color;
}

NS_FS_END




















