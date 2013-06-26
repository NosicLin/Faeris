#include <stdio.h>

#include "entity/FsLabelBitmap.h"
#include "scene/FsScene.h"
#include "scene/FsLayer2D.h"
#include "common/FsGlobal.h"
#include "graphics/FsFontBitmap.h"
#include "FsFaerisModule.h"

NS_FS_USE
class MyLayer:public Layer2D 
{
	public:
		static MyLayer* create()
		{

			MyLayer* ret=new MyLayer();
			return ret;
		}
	public:
		virtual bool touchBegin(float x,float y)
		{
			Global::scheduler()->stop();
			return true;
		}
};

int main()
{
	FsFaeris_ModuleInit();

	Window* win=Global::window();
	Render* render=Global::render();

	win->setPosition(100,100);
	win->show();
	render->setRenderTarget(win);
	render->setClearColor(Color(0,0,0));



	Global::director()->setAutoSwapBuffers(true);

	Scene* scene=Scene::create();
	Layer2D* layer=MyLayer::create();

	layer->setTouchEnabled(true);

	FontBitmap* font=FontBitmap::create("font.fnt");
	LabelBitmap* label=LabelBitmap::create(font);
	label->setString("My Name Is ChenLin(陈林)");
	label->setPosition(200,300,0);

	scene->push(layer);
	layer->add(label);

	layer->setViewArea(0,0,960,640);

	Global::director()->run(scene);

	scene->decRef();
	layer->decRef();
	font->decRef();
	label->decRef();

	Global::scheduler()->mainLoop();

	FsFaeris_ModuleExit();
	printf("FsFaeris_ModuleExit exit");

	return 0;
}












