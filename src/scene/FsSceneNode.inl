#ifndef _FS_SCENE_NODE_INL_
#define _FS_SCENE_NODE_INL_


inline void SceneNode::rotate(float rx,float ry,float rz)
{
	m_rotate.x+=rx;
	m_rotate.y+=ry;
	m_rotate.z+=rz;
	m_localMatrixDirty=1;
}
inline void SceneNode::rotateX(float r)
{
	m_rotate.x+=r;
	m_localMatrixDirty=1;
}
inline void SceneNode::rotateY(float r)
{
	m_rotate.y+=r;
	m_localMatrixDirty=1;
}
inline void SceneNode::rotateZ(float r)
{
	m_rotate.z+=r;
	m_localMatrixDirty=1;
}

inline void SceneNode::scale(float sx,float sy,float sz)
{
	m_scale.x*=sx;
	m_scale.y*=sy;
	m_scale.z*=sz;
	m_localMatrixDirty=1;
}
inline void SceneNode::scaleX(float s)
{
	m_scale.x*=s;
	m_localMatrixDirty=1;
}
inline void SceneNode::scaleY(float s)
{
	m_scale.y*=s;
	m_localMatrixDirty=1;
}
inline void SceneNode::scaleZ(float s)
{
	m_scale.z*=s;
	m_localMatrixDirty=1;
}

inline void SceneNode::move(float tx,float ty,float tz)
{
	m_translate.x+=tx;
	m_translate.y+=ty;
	m_translate.z+=tz;
	m_localMatrixDirty=1;
}
inline void SceneNode::moveX(float t)
{
	m_translate.x+=t;
	m_localMatrixDirty=1;
}
inline void SceneNode::moveY(float t)
{
	m_translate.y+=t;
	m_localMatrixDirty=1;
}
inline void SceneNode::moveZ(float t)
{
	m_translate.z+=t;
	m_localMatrixDirty=1;
}

inline void SceneNode::setRotate(float rx,float ry,float rz)
{
	m_rotate.set(rx,ry,rz);
	m_localMatrixDirty=1;
}
inline void SceneNode::setRotateX(float r)
{
	m_rotate.x=r;
	m_localMatrixDirty=1;
}
inline void SceneNode::setRotateY(float r)
{
	m_rotate.y=r;
	m_localMatrixDirty=1;
}
inline void SceneNode::setRotateZ(float r)
{
	m_rotate.z=r;
	m_localMatrixDirty=1;
}

inline void SceneNode::setScale(float sx,float sy,float sz)
{
	m_scale.set(sx,sy,sz);
	m_localMatrixDirty=1;
}
inline void SceneNode::setScaleX(float s)
{
	m_scale.x=s;
	m_localMatrixDirty=1;
}
inline void SceneNode::setScaleY(float s)
{
	m_scale.y=s;
	m_localMatrixDirty=1;
}
inline void SceneNode::setScaleZ(float s)
{
	m_scale.z=s;
	m_localMatrixDirty=1;
}

inline void SceneNode::setPosition(float tx,float ty,float tz)
{
	m_translate.set(tx,ty,tz);
	m_localMatrixDirty=1;
}
inline void SceneNode::setPositionX(float t)
{
	m_translate.x=t;
	m_localMatrixDirty=1;
}
inline void SceneNode::setPositionY(float t)
{
	m_translate.y=t;
	m_localMatrixDirty=1;
}
inline void SceneNode::setPositionZ(float t)
{
	m_translate.z=t;
	m_localMatrixDirty=1;
}

#endif /*_FS_SCENE_NODE_INL_*/

