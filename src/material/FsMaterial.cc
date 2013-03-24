#include "material/FsMaterial.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
const char* Material::className()
{
	return FS_MATERIAL_CLASS_NAME;
}

Material::~Material(){}

void Material::configRender(Render* r)
{
	r->setBlend(m_blendEquation,m_blendSrc,m_blendDst);
	r->setDepthMask(m_depthMask);
	r->enableDepthTest(m_depthTest);
	r->setShadeMode(m_shadeMode);
}
NS_FS_END

