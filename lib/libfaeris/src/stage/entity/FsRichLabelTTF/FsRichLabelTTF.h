#ifndef _FS_RICH_LABEL_TTF_H_
#define _FS_RICH_LABEL_TTF_H_ 

#include "FsMacros.h"
#include "FsObject.h"
#include "stage/entity/FsEntity.h"
#include "graphics/FsColor.h"


NS_FS_BEGIN

class Render;
class RichLabelTTF :public Entity
{
	public:
		enum
		{
			TEXT_ALIGN_LEFT,
			TEXT_ALIGN_CENTER,
			TEXT_ALIGN_RIGHT,
		};

	public:
		static RichLabelTTF* create(FontTTF* font);
		static RichLabelTTF* create(const char* str,FontTTF* font);


	public:
		void setString(const char* str);

		void setOpacity(float opacity) { m_opacity=opacity; }
		float getOpacity() { return m_opacity;} 

		void setColor(Color color){m_color=color;}
		Color getColor(){return m_color;}

		void setTextAlign(int align);


	public:
		virtual void draw(Render* r,bool update_matrix);
		virtual const char* className();


	protected:
		RichLabelTTF();
		virtual ~RichLabelTTF();


	protected:
		bool init(FontTTF* font);
		bool init(const char* str,FontTTF* font);
		void destory();
		void generateTypo();

	private:

		bool m_dirty;

		std::string m_string;

		FontTTF* m_font;

		float m_boundx;
		float m_boundy;

		int m_textAlign;

		RichTypoData* m_typoData;

		Color m_color;
		float m_opacity;
};

NS_FS_END 
#endif /*_FS_RICH_LABEL_TTF_H_*/






















