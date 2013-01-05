#include "GL/glew.h"
#include "graphics/FsMaterial.h"
#include "graphics/FsRender.h"

NS_FS_BEGIN


static GLint s_blendToGLenum(FsInt value)
{
	switch(value)
	{
		case Render::EQUATION_ADD:
			return GL_ADD;
		case Render::EQUATION_SUBTRACT:
			return GL_SUBTRACT;
			/*
		case Render::EQUATION_REVERSE_SUBTRACT:
			return GL_REVERSE_SUBTRACT;
			*/
		case Render::EQUATION_MIN:
			return GL_MIN;
		case Render::EQUATION_MAX:
			return GL_MAX;
		case Render::EQUATION_LOGIC_OP:
			return GL_LOGIC_OP; 

		case Render::FACTOR_ZERO:
			return GL_ZERO;

		case Render::FACTOR_ONE:
			return GL_ONE;

		case Render::FACTOR_SRC_COLOR:
			return GL_SRC_COLOR;

		case Render::FACTOR_ONE_MINUS_SRC_COLOR:
			return GL_ONE_MINUS_SRC_COLOR;

		case Render::FACTOR_DST_COLOR:
			return GL_DST_COLOR;

		case Render::FACTOR_ONE_MINUS_DST_COLOR:
			return GL_ONE_MINUS_DST_COLOR;

		case Render::FACTOR_SRC_ALPHA:
			return GL_SRC_ALPHA;

		case Render::FACTOR_ONE_MINUS_SRC_ALPHA:
			return GL_ONE_MINUS_SRC_ALPHA;

		case Render::FACTOR_DST_ALPHA:
			return GL_DST_ALPHA;

		case Render::FACTOR_ONE_MINUS_DST_ALPHA:
			return GL_ONE_MINUS_DST_ALPHA;
		case Render::FACTOR_SRC_ALPHA_SATURATE:
			return GL_SRC_ALPHA_SATURATE;

		default:
			FS_TRACE_ERROR("Invalid Param to Glenum");

	}
	return 0;
}

Render::Render()
{
	m_target=NULL;
	m_material=NULL;
	m_arrayFlags=0;


	glClearColor(0,0,0,255);
	m_clearColor=Color::BLACK;

	glClearDepth(1);
	glClearStencil(0);

	/* depth */
	glEnable(GL_DEPTH);
	m_depthTest=true;

	/* face */
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	m_cullFace=SIDE_BACK;
	m_frontFace=FRONT_CCW;


	/* blend */
	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	m_blendEquation=EQUATION_ADD;
	m_blendSrc=FACTOR_SRC_ALPHA;
	m_blendDst=FACTOR_ONE_MINUS_SRC_ALPHA;

	/* texture */
	glEnable(GL_TEXTURE2D);
}

void Render::pushMatrix()
{
	glPushMatrix();
}
void Render::popMatrix()
{
	glPopMatrix();
}
void Render::translate(const Vector3& v)
{
	glTranslatef(v.x,v.y,v.z);
}
void Render::scale(const Vector3& v)
{
	glScalef(v.x,v.y,v.z);
}
void Render::rotate(const Vector3& v,FsFloat angle)
{
	glRotatef(angle,v.x,v.y,v.z);
}
void Render::setViewport(FsInt x,FsInt y,FsInt width,FsInt height)
{
	glViewport(x,y,width,height);
}

void Render::setClearColor(Color c)
{
	m_clearColor=c;
	glClearColor(c.r/255.0f,c.g/255.0f,c.b/255.0f,c.a/255.0f);
}


void Render::clear(FsBool color,FsBool depth,FsBool stencil)
{
	GLint flags=0;
	if(color) flags|=GL_COLOR_BUFFER_BIT;
	if(depth) flags|=GL_DEPTH_BUFFER_BIT;
	if(stencil) flags|=GL_STENCIL_BUFFER_BIT;
	glClear(flags);
}

void Render::setScissor(FsInt x,FsInt y,FsInt width,FsInt height)
{
	glScissor(x,y,width,height);
}
void Render::enableScissorTest(FsBool enable)
{
	if(m_scissorEnable!=enable)
	{
		if(enable)
		{
			glEnable(GL_SCISSOR_TEST);
		}
		else
		{
			glDisable(GL_SCISSOR_TEST);
		}
		m_scissorEnable=enable;
	}
}
void Render::enableDepthTest(FsBool enable)
{
	if(m_depthTest==enable)
	{
		if(enable)
		{
			glEnable(GL_DEPTH_TEST);
		}
		else
		{
			glDisable(GL_DEPTH_TEST);
		}
		m_depthTest=enable;
	}
}
void Render::setDepthMask(FsBool enable)
{
	if(m_depthMask!=enable)
	{
		glDepthMask(enable);
		m_depthMask=enable;
	}
}

void Render::setLineWidth(FsFloat width)
{
	if(m_lineWidth!=width)
	{
		glLineWidth(width);
		m_lineWidth=width;
	}
}

void Render::enableFog(FsBool enable)
{
	if(m_fogEnable!=enable)
	{
		if(enable)
		{
			glEnable(GL_FOG);
		}
		else
		{
			glDisable(GL_FOG);
		}
		m_fogEnable=enable;
	}
}

void Render::setMaterial(Material* mat,bool force)
{
	if(!force)
	{
		if(mat==m_material) { return ; }
	}

	if(mat!=NULL)
	{
		mat->addRef();
	}

	if(m_material!=NULL)
	{
		m_material->unload(this);
		m_material->decRef();
	}
	if(mat) mat->load(this);
	m_material=mat;
}

void Render::setRenderTarget(RenderTarget* target)
{
	if(target) target->addRef();
	if(m_target)
	{
	   	m_target->loseCurrent(this);
		m_target->decRef();
	}

	if(target) { target->makeCurrent(this); }
	m_target=target;
}
void Render::swapBuffers()
{
	if(m_target) m_target->swapBuffers();
}

void Render::setVVertexPointer(Vector3* v,FsUint num)
{
	glVertexPointer(3,GL_FLOAT,0,v);
}
void Render::setVNormalPointer(Vector3* v,FsUint num)
{
	glNormalPointer(GL_FLOAT,0,v);
}
void Render::setVTexCoordPointer(TexCoord2* v,FsUint num)
{
	glTexCoordPointer(2,GL_FLOAT,0,v);
}
void Render::setVColorPointer(Color* v,FsUint num)
{
	glColorPointer(4,GL_UNSIGNED_BYTE,0,v);
}
void Render::drawFace3(Face3* f,FsUint num)
{
	glDrawElements(GL_TRIANGLES,num*3,GL_UNSIGNED_INT,f);
}

void Render::enableClientArray(FsUlong flags)
{
	if(flags&VERTEX_ARRAY)
	{
		if(!(m_arrayFlags&VERTEX_ARRAY))
		{
			glEnableClientState(GL_VERTEX_ARRAY);
		}
	}

	if(flags&NORMAL_ARRAY)
	{
		if(!(m_arrayFlags&NORMAL_ARRAY))
		{
			glEnableClientState(GL_NORMAL_ARRAY);
		}
	}

	if(flags&TEXTURE_COORD_ARRAY)
	{
		if(!(m_arrayFlags&TEXTURE_COORD_ARRAY))
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		}
	}

	if(flags&COLOR_ARRAY)
	{
		if(!(m_arrayFlags&COLOR_ARRAY))
		{
			glEnableClientState(GL_COLOR_ARRAY);
		}
	}
	m_arrayFlags|=flags;
}

void Render::disableClientArray(FsUlong flags)
{
	if(flags&VERTEX_ARRAY)
	{
		if(m_arrayFlags&VERTEX_ARRAY)
		{
			glDisableClientState(GL_VERTEX_ARRAY);
		}
	}

	if(flags&NORMAL_ARRAY)
	{
		if(m_arrayFlags&NORMAL_ARRAY)
		{
			glDisableClientState(GL_NORMAL_ARRAY);
		}
	}

	if(flags&COLOR_ARRAY)
	{
		if(m_arrayFlags&COLOR_ARRAY)
		{
			glDisableClientState(COLOR_ARRAY);
		}
	}

	if(flags&TEXTURE_COORD_ARRAY)
	{
		if(m_arrayFlags&TEXTURE_COORD_ARRAY)
		{
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}
	}
	m_arrayFlags&=!flags;
}

void Render::disableAllClientArray()
{
	disableClientArray(ALL_ARRAY);
}

void Render::setBlend(FsInt blend_eq,FsInt factor_src,FsInt factor_dst)
{
	if((blend_eq==m_blendEquation) 
		&&(factor_src==m_blendSrc )
		&&(factor_dst==m_blendDst))
	{
		return ;
	}

	if(blend_eq==EQUATION_NONE) 
	{
		glDisable(GL_BLEND);
	}
	else 
	{
		if(m_blendEquation==EQUATION_NONE)
		{
			glEnable(GL_BLEND);
		}
		glBlendEquation(s_blendToGLenum(blend_eq));
		glBlendFunc(s_blendToGLenum(factor_src),
				s_blendToGLenum(factor_dst));
	}
	m_blendEquation=blend_eq;
	m_blendSrc=factor_src;
	m_blendDst=factor_dst;
}



//void Render::enablePolygonOffset(FsBool){}
//oid Render::setPolygonOffset(FsFloat factor,FsFloat units);


NS_FS_END

