#include "material/FsBaseMaterial.h"
#include "graphics/FsRender.h"

const FsChar* s_base_material_vert[]=
"

";

const FsChar* s_base_material_frag[]=
" \
";


void BaseMaterial::load(Render* r)
{
	r->setBlend(blendEquation,blendSrc,blendDst);
	r->setDepthMask(depthMask);
	r->enableDepthTest(depthTest);
}

void BaseMaterial::unload(Render* r);
{
}




