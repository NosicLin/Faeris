#include "material/FsBaseMaterial.h"
#include "graphics/FsRender.h"
static const FsChar* s_MaterialName="MaterialObject";
const FsChar* getName(){return s_MaterialName;}

Material::~Material(){}

void Render::configRender(Render* r)
{
	r->setBlend(m_blendEquation,m_blendSrc,m_blendDst);
	r->setDepthMask(m_depthMask);
	r->enableDepthTest(m_depthTest);
	r->setShadeMode(m_shadeMode);
	r->setOpacity(m_opacity);
}
