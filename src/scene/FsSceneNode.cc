#include "core/FsNode.h"

NS_FS_BEGIN
void SceneNode::initData()
{
	m_name=NULL;
	m_tx=0;m_ty=0;m_tz=0;
	m_rx=0;m_ry=0;m_rz=0;
	m_sx=1;m_sy=0;m_sz=0;

	m_localMatrixDirty=1;
	m_worldMatrixDirty=1;
	m_hasBoundSphere=0;
	m_hasBoundBox=0;
	m_visible=1;

	m_parent=NULL;
}
NS_FS_END

