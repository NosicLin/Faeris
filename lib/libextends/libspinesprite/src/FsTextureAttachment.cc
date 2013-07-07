#include "FsTextureAttachment.h"
NS_FS_BEGIN

static void _TextureAttachment_Deinit(Attachment* att)
{
	TextureAttachment* self=SUB_CAST(TextureAttachment,att);
	FS_SAFE_DEC_REF(self->texture);
}

TextureAttachment* TextureAttachment_Create(const char* filename)
{
	TextureAttachment* self=NEW(TextureAttachment);
	Texture2D* texture=Global::textureMgr()->loadTexture(filename);
	if(texture==NULL)
	{
		FS_TRACE_WARN("Can't Load Texture(%s) For Spine Skeleton");
	}
	self->texture=texture;

	_Attachment_init(SUPER(self),name,ATTACHMENT_REGION,_TextureAttachment_Deinit);
	return self;
}


NS_FS_END 


