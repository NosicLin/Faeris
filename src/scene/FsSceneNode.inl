#ifndef _FS_SCENE_NODE_INL_
#define _FS_SCENE_NODE_INL_


inline void SceneNode::rotate(FsFloat rx,FsFloat ry,FsFloat rz)
{
	m_rotate.x+=rx;
	m_rotate.y+=ry;
	m_rotate.z+=rz;
	m_localMatrixDirty=1;
}
inline void SceneNode::rotateX(FsFloat r)
{
	m_rotate.x+=r;
	m_localMatrixDirty=1;
}
inline void SceneNode::rotateY(FsFloat r)
{
	m_rotate.y+=r;
	m_localMatrixDirty=1;
}
inline void SceneNode::rotateZ(FsFloat r)
{
	m_rotate.z+=r;
	m_localMatrixDirty=1;
}

inline void SceneNode::scale(FsFloat sx,FsFloat sy,FsFloat sz)
{
	m_scale.x*=sx;
	m_scale.y*=sy;
	m_scale.z*=sz;
	m_localMatrixDirty=1;
}
inline void SceneNode::scaleX(FsFloat s)
{
	m_scale.x*=s;
	m_localMatrixDirty=1;
}
inline void SceneNode::scaleY(FsFloat s)
{
	m_scale.y*=s;
	m_localMatrixDirty=1;
}
inline void SceneNode::scaleZ(FsFloat s)
{
	m_scale.z*=s;
	m_localMatrixDirty=1;
}

inline void SceneNode::move(FsFloat tx,FsFloat ty,FsFloat tz)
{
	m_translate.x+=tx;
	m_translate.y+=ty;
	m_translate.z+=tz;
	m_localMatrixDirty=1;
}
inline void SceneNode::moveX(FsFloat t)
{
	m_translate.x+=t;
	m_localMatrixDirty=1;
}
inline void SceneNode::moveY(FsFloat t)
{
	m_translate.y+=t;
	m_localMatrixDirty=1;
}
inline void SceneNode::moveZ(FsFloat t)
{
	m_translate.z+=t;
	m_localMatrixDirty=1;
}

inline void SceneNode::setRotate(FsFloat rx,FsFloat ry,FsFloat rz)
{
	m_rotate.set(rx,ry,rz);
	m_localMatrixDirty=1;
}
inline void SceneNode::setRotateX(FsFloat r)
{
	m_rotate.x=r;
	m_localMatrixDirty=1;
}
inline void SceneNode::setRotateY(FsFloat r)
{
	m_rotate.y=r;
	m_localMatrixDirty=1;
}
inline void SceneNode::setRotateZ(FsFloat r)
{
	m_rotate.z=r;
	m_localMatrixDirty=1;
}

inline void SceneNode::setScale(FsFloat sx,FsFloat sy,FsFloat sz)
{
	m_scale.set(sx,sy,sz);
	m_localMatrixDirty=1;
}
inline void SceneNode::setScaleX(FsFloat s)
{
	m_scale.x=s;
	m_localMatrixDirty=1;
}
inline void SceneNode::setScaleY(FsFloat s)
{
	m_scale.y=s;
	m_localMatrixDirty=1;
}
inline void SceneNode::setScaleZ(FsFloat s)
{
	m_scale.z=s;
	m_localMatrixDirty=1;
}

inline void SceneNode::setPosition(FsFloat tx,FsFloat ty,FsFloat tz)
{
	m_translate.set(tx,ty,tz);
	m_localMatrixDirty=1;
}
inline void SceneNode::setPositionX(FsFloat t)
{
	m_translate.x=t;
	m_localMatrixDirty=1;
}
inline void SceneNode::setPositionY(FsFloat t)
{
	m_translate.y=t;
	m_localMatrixDirty=1;
}
inline void SceneNode::setPositionZ(FsFloat t)
{
	m_translate.z=t;
	m_localMatrixDirty=1;
}

#endif /*_FS_SCENE_NODE_INL_*/

