#ifndef _FAERIS_WINDOW_H_
#define _FAERIS_WINDOW_H_ 
#include <vector>
#include <string>

#include "FsMacros.h"
#include "graphics/FsRenderTarget.h"
#include "FsConfig.h"
#include "core/FsEvent.h"
#include "core/FsEventListener.h"

FAERIS_NAMESPACE_BEGIN

class PlatformWindow;
class Window:public RenderTarget
{
	public:
		static Window* create(FsLong flags);
		
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

		FsInt getWidth();
		FsInt getHeight();
		FsInt getPosX();
		FsInt getPosY();

	public:
		void addEventListener(EventListener* l);
		void removeEventListener(EventListener* l);
		void dropAllEventListener();
	public:
		virtual const char* getName();
		virtual void onDestry();
		virtual ~Window();

	public:
		void handleEvent(Event* e);

	protected:
		Window(FsLong flags);
		bool init(FsLong flags);
		void destroy();

	public:
		PlatformWindow* getPlatformWindow(){return m_window;}

	private:
		Render* m_render;

		std::string m_caption;
		/* EventListener*/
		typedef std::vector<EventListener*>::iterator Iterator;
		std::vector<EventListener*> m_listeners;

		/* PlatformWindow */
		PlatformWindow* m_window;
};
FAERIS_NAMESPACE_END

#endif /*_FAERIS_WINDOW_H_*/















