#include "material/FsMaterial.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN
static const char* s_MaterialName="MaterialObject";
const char* Material::getName(){return s_MaterialName;}

Material::~Material(){}

void Material::configRender(Render* r)
{
	r->setBlend(m_blendEquation,m_blendSrc,m_blendDst);
	r->setDepthMask(m_depthMask);
	r->enableDepthTest(m_depthTest);
	r->setShadeMode(m_shadeMode);
	r->setOpacity(m_opacity);
}
NS_FS_END

