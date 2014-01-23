#include "stage/entity/FsPanel.h"
#include "stage/layer/FsLayer.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
const char* Panel::className()
{
	return FS_PANEL_CLASS_NAME;
}

Panel* Panel::create()
{
	return Panel::create(0,0);
}

Panel* Panel::create(float width,float height)
{
	Panel* ret=new Panel();
	if(!ret->init(width,height))
	{
		delete ret;
		return NULL;
	}
	return ret;
}

Panel::Panel()
{
	m_anchorX=0.5;
	m_anchorY=0.5;
	m_width=0;
	m_height=0;
	m_touchFocus=NULL;
	m_touchEnabled=true;;
	m_scissorEnabled=true;
}

Panel::~Panel()
{
	FS_SAFE_DEC_REF(m_touchFocus);
}

bool Panel::init(float width,float height)
{
	m_width=width;
	m_height=height;
	return true;
}

void Panel::setSize(float width,float height)
{
	m_width=width;
	m_height=height;
}
void Panel::getSize(float* width,float* height)
{
	*width=m_width;
	*height=m_height;
}

void Panel::setAnchor(float x,float y)
{
	m_anchorX=x;
	m_anchorY=y;
}
void Panel::getAnchor(float* x,float* y)
{
	*x=m_anchorX;
	*y=m_anchorY;
}

void Panel::setScissorEnabled(bool enabled)
{
	m_scissorEnabled=enabled;
}
bool Panel::getScissorEnabled()
{
	return m_scissorEnabled;
}

void Panel::dropTouchFocus()
{
	FS_SAFE_ASSIGN(m_touchFocus,(Entity*)NULL);
}


bool Panel::touchBegin(float x,float y)
{
	FS_SAFE_ASSIGN(m_touchFocus,(Entity*)NULL);
	if(m_zorderDirty)
	{
		sortChildren();
		m_zorderDirty=false;
	}



	m_chirdren->lock();
	int child_nu=m_chirdren->size();

	for(int i=0;i<child_nu;i++)
	{
		Entity* e=(Entity*)m_chirdren->get(i);
		if(e->getVisible()&&e->getTouchEnabled()&&e->getParent()==this&&e->hit2D(x,y))
		{
			/* NOTE: entity will detach when called touchBegin */
			bool ret=e->touchBegin(x,y);
			if(ret&&e->getParent()==this)
			{
				FS_SAFE_ASSIGN(m_touchFocus,e);
				break;
			}
		}
	}
	m_chirdren->unlock();
	m_chirdren->flush();
	return m_touchFocus!=NULL;
}
bool Panel::touchMove(float x,float y)
{
	if(m_touchFocus)
	{
		if(m_touchFocus->getParent()==this)
		{
			return m_touchFocus->touchMove(x,y);
		}
		else 
		{
			FS_SAFE_ASSIGN(m_touchFocus,(Entity*)NULL);
		}
	}
	return false;
}
bool Panel::touchEnd(float x,float y)
{
	if(m_touchFocus)
	{
		if(m_touchFocus->getParent()==this)
		{
			return m_touchFocus->touchEnd(x,y);
		}
	}

	FS_SAFE_ASSIGN(m_touchFocus,(Entity*)NULL);
	return false;
}

void Panel::draws(Render* r,bool updateMatrix)
{

	if(updateMatrix)
	{
		updateWorldMatrix();
	}

	if(m_scissorEnabled&&m_layer!=NULL)
	{
		bool old_scissor_enabled=r->getScissorEnabled();
		Rect2D old_scissor_area=r->getScissorArea();
		
		float minx=-m_anchorX*m_width;
		float maxx=minx+m_width;
		float miny=-m_anchorY*m_height;
		float maxy=miny+m_height;

		Vector3 a(minx,miny,0);
		Vector3 b(maxx,miny,0);
		Vector3 c(maxx,maxy,0);
		Vector3 d(minx,maxy,0);

		Vector3 t[4];

		t[0]=m_worldMatrix.mulVector3(a);
		t[1]=m_worldMatrix.mulVector3(b);
		t[2]=m_worldMatrix.mulVector3(c);
		t[3]=m_worldMatrix.mulVector3(d);


		float tminx=t[0].x;
		float tmaxx=t[0].x;
		float tminy=t[0].y;
		float tmaxy=t[0].y;


		for (int i=1;i<4;i++)
		{
			if (tminx>t[i].x) { tminx=t[i].x ;}
			if(tmaxx<t[i].x) { tmaxx=t[i].x; }
		   	if(tminy>t[i].y) { tminy=t[i].y; }
			if(tmaxy<t[i].y) { tmaxy=t[i].y ;}
		}
		Matrix4 proj=m_layer->getProjectMatrix();
		Vector3 sminv=proj.mulVector3(Vector3(tminx,tminy,0));
		Vector3 smaxv=proj.mulVector3(Vector3(tmaxx,tmaxy,0));

		float sminx=(sminv.x+1.0f)/2;
		float sminy=(sminv.y+1.0f)/2;

		float smaxx=(smaxv.x+1.0f)/2;
		float smaxy=(smaxv.y+1.0f)/2;

		r->setScissorEnabled(true);
		r->setScissorArea(sminx,sminy,smaxx-sminx,smaxy-sminy);

		Entity::draws(r,updateMatrix);

		r->setScissorEnabled(old_scissor_enabled);
		r->setScissorArea(old_scissor_area);
	}
	else 
	{
		Entity::draws(r,updateMatrix);
	}
}

bool Panel::hit2D(float x,float y)
{
	Vector3 tv=worldToLocal(Vector3(x,y,0));

	float diffx=tv.x-(-m_anchorX*m_width);
	float diffy=tv.y-(-m_anchorY*m_height);
	if(diffx>=0 && diffy <=m_width)
	{
		if(diffy>=0 && diffy<=m_height)
		{
			return true;
		}
	}
	return false;

}





NS_FS_END





















