#ifndef _FAERIS_WINDOW_H_
#define _FAERIS_WINDOW_H_ 
#include <vector>
#include <string>

#include "FsMacros.h"
#include "graphics/FsRenderTarget.h"
#include "FsConfig.h"
#include "fsys/FsEvent.h"
#include "fsys/FsEventListener.h"

#define FS_DEFAULT_WINDOW_NAME "FaerisEngine"

NS_FS_BEGIN
class PlatformWindow;
class Window:public RenderTarget
{
	public:
		enum
		{
			STYLE_MAXBOX=0x1,
			STYLE_MINBOX=0x2,
			STYLE_CLOSEBOX=0x4,
		};
	public:
			static Window* shareWindow();
			static void purgeShareWindow();

	public:
			virtual void makeCurrent(Render* r);
			virtual void loseCurrent(Render* r);
			virtual void swapBuffers();
	public:
			void setCaption(const FsChar* name);
			std::string getCaption(){return m_caption;}
			void setPosition(FsInt x,FsInt y);
			void setSize(FsUint width,FsUint height);
			void show();
			void hide();
			void setStyle(FsLong flags);

			void setFullScreen(FsBool full);

			FsInt getWidth();
			FsInt getHeight();
			FsInt getPosX();
			FsInt getPosY();
			void setCenter();
	public:
			virtual const FsChar* getName();

	public:
			void handleEvent(Event* e);

	protected:
			Window();
			virtual ~Window();

	public:
			PlatformWindow* getPlatformWindow(){return m_window;}

	private:
			Render* m_render;
			std::string m_caption;
			PlatformWindow* m_window;
};

NS_FS_END
#endif /*_FAERIS_WINDOW_H_*/















