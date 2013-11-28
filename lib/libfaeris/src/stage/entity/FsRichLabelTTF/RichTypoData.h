#ifndef _FS_RICH_TYPO_DATA_H_
#define _FS_RICH_TYPO_DATA_H_ 

NS_FS_BEGIN
class RichTypoData
{

	public:
		static RichTypoData* create(FontTTF* font,const char* str,float boundx,float boundy,int text_align);

	public:
		void adjustAlign(int align);

	private:
		float m_width;
		float m_height;

};


NS_FS_END



#endif /*_FS_RICH_TYPO_DATA_H_*/

