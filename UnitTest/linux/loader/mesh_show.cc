#include "stdio.h"
#include "stdlib.h"
#include <GL/gl.h>
#include <GL/glut.h>

#include "util/FsMeshUtil.h"
#include "fsys/FsFile.h"
#include "fsys/FsVFS.h"
#include "fsys/FsSysFile.h"
#include "core/FsWindow.h"
#include "graphics/FsRender.h"
#include "core/FsFrame.h"



using namespace Faeris;

class MyFrameListener:public FrameListener 
{
	public:
		MyFrameListener(Mesh* mesh)
		{
			m_time=0;
			m_mesh=mesh;
		}

	public:
		virtual void frameUpdate(FsLong now,FsLong diff)
		{
			m_time++;
			Render::instance()->clear(true);
			printf("draw begin=%d,%d\n",m_time,Frame::instance()->getAvgFPS());
			for(FsInt i=0;i<500;i++)
			{
			//	m_mesh->draw(Render::instance());
			}
			printf("draw end\n");
			//Render::instance()->swapBuffers();
		}
	private:
		FsInt m_time;
		Mesh* m_mesh;
};

int main(int argc,char** argv)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if(argc!=2)
	{
		printf("usage:%s <filename>\n",argv[0]);
		exit(-1);
	}

	FsFile* file=VFS::open(argv[1]);
	if(file==NULL)
	{
		printf("Can't Open File(%s)\n",argv[1]);
		exit(-1);
	}

	Mesh* mesh =MeshUtil::loadMesh(file);
	file->decRef();

	if(mesh==NULL)
	{
		printf("Load Mesh Failed\n");
		return 0;
	}
	else 
	{
		printf("Load Mesh Success\n");
		MeshUtil::saveMesh(mesh,SysFile::getStdout());
	}

	Window* win=Window::create(0);
	Render* render=Render::instance();
	win->setSize(1024,800);
	win->setCaption("Faeris.V1.0.1");
	win->show();
	win->setPosition(100,200);
	render->setRenderTarget(win);
	//render->setViewport(0,0,100,100);
	render->rotate(Vector3(1,1,0),40);

	MyFrameListener* framelistener=new MyFrameListener(mesh);
	Frame::instance()->addListener(framelistener);
	Frame::instance()->setFPS(0);
	Frame::instance()->start();

	if(mesh) mesh->decRef();
	return 0;
}


