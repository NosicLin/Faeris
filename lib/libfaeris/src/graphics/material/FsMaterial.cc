#include "graphics/material/FsMaterial.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
const char* Material::className()
{
	return FS_MATERIAL_CLASS_NAME;
}

Material::~Material(){}

void Material::onUse(Render* r)
{
	r->setBlend(m_blendEquation,m_blendSrc,m_blendDst);
	r->setDepthTest(m_depthTest);
}
NS_FS_END

