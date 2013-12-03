#include "FsRichLabelTTF.h"

NS_FS_BEGIN

RichTypoData* RichTypoData::create(FontTTF* font,const char* u8_str,int start,int num,float boundx,float boundy,int text_align)
{
	uint16_t* u16_str=FsUtf8_ToUtf16(u8_str);
	int len=FsUtf16_StrLen(u16_str);
	if(num==-1){num=len;}
	if(start+num>len){num=len-start;}
	if(num<=0)
	{
		delete[] u16_str;
		return NULL;
	}

}



RichLabelTTF::RichLabelTTF()
	:m_dirty(true),
	m_string(""),
	m_font(NULL),
	m_boundx(0),
	m_boundy(0),
	m_textAlign(RichLabelTTF::TEXT_ALIGN_LEFT),
	m_typoData(NULL),
	m_color(Color.WHITE),
	m_opacity(1.0f)
{

}


bool RichLabelTTF::init(FontTTF* font)
{
	FS_SAFE_ASSIGN(m_font,font);

	/* string  is empty, so no need to draw */
	m_dirty=false; 
	return true;
}

bool RichLabelTTF::init(const char* str,FontTTF* font)
{
	FS_SAFE_ASSIGN(m_font,font);
	m_string=str;
	m_dirty=true;
	return true;
}



bool RichLabelTTF::destory()
{
	FS_SAFE_DEF_REF(m_font);
	m_font=NULL;

	FS_SAFE_DELETE(m_typoData);
	m_typoData=NULL;
}


void RichLabelTTF::generateTypo()
{
	if(m_typoData)
	{
		delete m_typoData;
		m_typoData=NULL;
	}

	if(!m_font || m_string==std::string(""))
	{
		return;
	}

	m_typoData=RichTypoData::create(m_font,m_string.c_str(),m_boundx,m_boundy,m_textAlign);
}

RichLabelTTF* RichLabelTTF::create(FontTTF* font)
{
	RichLabelTTF* ret=new RichLabelTTF();

	if(!ret->init(font))
	{
		delete ret;
		return NULL;
	}
	return ret;
}


RichLabelTTF* RichLabelTTF::create(const char* str,FontTTF* font)
{
	RichLabelTTF* ret=new RichLabelTTF();
	if(!ret->init(str,font))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

void RichLabelTTF::setString(const char* str)
{
	if (m_string==str)
	{
		return ;
	}
	m_string=str;
	m_dirty=true;
}


void RichLabelTTF::setTextAlign(int align)
{
	if (m_textAlign==align) 
	{
		return;
	}

	m_textAlign=align;

	if(m_typoData)
	{
		m_typoData->adjustAlign(align);
	}
}


NS_FS_END





