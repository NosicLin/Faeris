#include "scene/FsSceneNode.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
const char* s_SceneNodeName="SceneNodeObject";

 const char* SceneNode::className()
{
	return s_SceneNodeName;
}

SceneNode::SceneNode(FsString* name)
{
	name->addRef();
	initData();
	m_name=name;
}
SceneNode::SceneNode()
{
	initData();
}
SceneNode::~SceneNode()
{
	FS_SAFE_DEC_REF(m_name);
	FS_SAFE_DEC_REF(m_chirdren);
}

void SceneNode::update(long msec)
{
	updateSelf(msec);

	FsArray::Iterator iter(m_chirdren);
	while(!iter.done())
	{
		SceneNode* node=(SceneNode*)iter.getValue();
		node->update(msec);
		node->decRef();
		iter.next();
	}
}
void SceneNode::updateSelf(long mesc)
{
}
void SceneNode::draw(Render* r)
{
	updateLocalMatrix();
	r->pushMatrix();
	r->mulMatrix(m_localMatrix);

	drawSelf(r);
//#define FS_SCENE_COORD_DEBUG
#ifdef FS_SCENE_COORD_DEBUG
	r->setMaterial(NULL);
	r->setProgram(NULL);
	r->drawLine(Vector3(-1.0,0,0),Vector3(1.0,0,0),2,Color(255,0,0));

	r->drawLine(Vector3(0.95f,0.05f,0),Vector3(1.0,0,0),1,Color(255,0,0));
	r->drawLine(Vector3(0.95f,-0.05f,0),Vector3(1.0,0,0),1,Color(255,0,0));

	r->drawLine(Vector3(0.95f,0,0.05f),Vector3(1.0,0,0),1,Color(255,0,0));
	r->drawLine(Vector3(0.95f,0,-0.05f),Vector3(1.0,0,0),1,Color(255,0,0));

//	--label X
	r->drawLine(Vector3(1.0,0.05f,0),Vector3(1.06f,-0.05f,0),1,Color(255,0,0));
	r->drawLine(Vector3(1.0,-0.05f,0),Vector3(1.06f,0.05f,0),1,Color(255,0,0));



//	--axis Y
	r->drawLine(Vector3(0,1,0),Vector3(0,-1.0,0),2,Color(0,255,0));

//	--arrow >
	r->drawLine(Vector3(-0.05f,0.95f,0),Vector3(0,1.0,0),1,Color(0,255,0));
	r->drawLine(Vector3(0.05f,0.95f,0),Vector3(0,1.0,0),1,Color(0,255,0));

	r->drawLine(Vector3(0,0.95f,-0.05f),Vector3(0,1.0,0),1,Color(0,255,0));
	r->drawLine(Vector3(0,0.95f,0.05f),Vector3(0,1.0,0),1,Color(0,255,0));

//	--label Y
	r->drawLine(Vector3(0,1.01f,0),Vector3(0,1.07f,0),1,Color(0,255,0));
	r->drawLine(Vector3(-0.03f,1.12f,0),Vector3(0,1.07f,0),1,Color(0,255,0));
	r->drawLine(Vector3(0.03f,1.12f,0),Vector3(0,1.07f,0),1,Color(0,255,0));


//	--axis Z
	r->drawLine(Vector3(0,0,-1.0),Vector3(0,0,1.0),2,Color(0,0,255));

//	--arrow >
	r->drawLine(Vector3(0.05f,0,0.95f),Vector3(0,0,1.0),1,Color(0,0,255));
	r->drawLine(Vector3(-0.05f,0,0.95f),Vector3(0,0,1.0),1,Color(0,0,255));
	r->drawLine(Vector3(0,0.05f,0.95f),Vector3(0,0,1.0),1,Color(0,0,255));
	r->drawLine(Vector3(0,-0.05f,0.95f),Vector3(0,0,1.0),1,Color(0,0,255));
#endif 



	FsArray::Iterator iter(m_chirdren);
	while(!iter.done())
	{
		SceneNode* node=(SceneNode*)iter.getValue();
		node->draw(r);
		node->decRef();
		iter.next();
	}
	r->popMatrix();
}

void SceneNode::drawSelf(Render* r)
{
}

void SceneNode::initData()
{
	m_name=NULL;
	m_translate.set(0,0,0);
	m_rotate.set(0,0,0);
	m_scale.set(1,1,1);

	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
	m_hasBoundSphere=0;
	m_hasBoundBox=0;
	m_visible=1;

	m_parent=NULL;
	m_chirdren=new FsArray();
}



void SceneNode::updateLocalMatrix()
{
	if(m_localMatrixDirty)
	{
		m_localMatrix.makeCompose(m_translate,m_rotate,FS_EULER_XYZ,m_scale);
		m_localMatrixDirty=0;
		m_worldMatrixDirty=1;
	}
}
void SceneNode::updateWorldMatrix()
{
	updateLocalMatrix();
	if(!m_parent)
	{
		if(m_worldMatrixDirty)
		{
			m_worldMatrix=m_localMatrix;
			m_worldMatrixDirty=0;
			notifyChirdWorldMatrixDirty();
		}
	}
	else 
	{
		m_parent->updateWorldMatrix();
		if(m_worldMatrixDirty)
		{
			m_worldMatrix=m_parent->m_worldMatrix;
			m_worldMatrix.mul(m_localMatrix);
			m_worldMatrixDirty=0;
			notifyChirdWorldMatrixDirty();
		}
	}

}

void SceneNode::updateAllWorldMatrix()
{
	bool force=false;
	updateLocalMatrix();
	if(!m_parent)
	{
		if(m_worldMatrixDirty)
		{
			m_worldMatrix=m_localMatrix;
			force=true;
		}
	}
	else 
	{
		m_parent->updateWorldMatrix();
		if(m_worldMatrixDirty)
		{
			m_worldMatrix=m_parent->m_worldMatrix;
			m_worldMatrix.mul(m_localMatrix);
			m_worldMatrixDirty=0;
			force=true;
		}
	}

	FsArray::Iterator iter(m_chirdren);
	while(!iter.done())
	{
		SceneNode* node=(SceneNode*)iter.getValue();
		node->updateAllWorldMatrixInternal(force);
		node->decRef();
		iter.next();
	}
}

void SceneNode::updateAllWorldMatrixInternal(bool force)
{
	updateLocalMatrix();
	if(force)
	{
		m_worldMatrix=m_parent->m_worldMatrix;
		m_worldMatrix.mul(m_localMatrix);
		m_worldMatrixDirty=0;
	}
	else 
	{
		if(m_worldMatrixDirty)
		{
			m_worldMatrix=m_parent->m_worldMatrix;
			m_worldMatrix.mul(m_localMatrix);
			m_worldMatrixDirty=0;
			force=true;
		}
	}


	FsArray::Iterator iter(m_chirdren);
	while(!iter.done())
	{
		SceneNode* node=(SceneNode*)iter.getValue();
		node->updateAllWorldMatrixInternal(force);
		node->decRef();
		iter.next();
	}
}
void SceneNode::notifyChirdWorldMatrixDirty()
{
	FsArray::Iterator iter(m_chirdren);
	while(!iter.done())
	{
		SceneNode* node=(SceneNode*)iter.getValue();
		node->m_worldMatrixDirty=1;
		node->decRef();
		iter.next();
	}
}

Vector3 SceneNode::localToWorld(const Vector3& v)
{
	updateWorldMatrix();
	return m_worldMatrix.mulVector3(v);
}

Vector3 SceneNode::worldToLocal(const Vector3& v)
{
	updateWorldMatrix();

	Matrix4 inverse;
	m_worldMatrix.getInverse(&inverse);

	return inverse.mulVector3(v);
}

void SceneNode::addChild(SceneNode* n)
{
	if(n->m_parent==this)
	{
		return;
	}
	if(n->m_parent)
	{
		n->m_parent->remove(n);
		n->m_parent=NULL;
	}
	m_chirdren->push(n);
	n->m_parent=this;

}
void SceneNode::remove(SceneNode* n)
{
	int length=m_chirdren->size();
	for(int i=0;i<length;i++)
	{
		SceneNode* node=(SceneNode*)m_chirdren->get(i);
		if(n==node)
		{
			m_chirdren->remove(i);
			node->m_parent=NULL;
			node->decRef();
			return;
		
		}
		node->decRef();
	}

	FS_TRACE_WARN("SceneNode Not Found");
}




NS_FS_END


