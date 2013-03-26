#ifndef _FS_COLOR_LAYER_H_
#define _FS_COLOR_LAYER_H_

#include "FsMacros.h"
#include "scene/FsLayer.h"
#include "graphics/FsColor.h"

NS_FS_BEGIN

class Render;
class ColorLayer:public Layer 
{
	public:
		static ColorLayer* create();
		static ColorLayer* create(Color c);
	public:
		void setColor(Color c);
		Color getColor();

	public:
		/* inherit Layer */
		virtual void draw(Render*  r);

		/* inherit FsObject */
		virtual const char* className();

	protected:
		ColorLayer();
		~ColorLayer();

	private:
		Color m_color;
};
NS_FS_END

#endif /*_FS_COLOR_LAYER_H_*/


