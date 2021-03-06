#include <string.h>

#if FS_PLATFORM_OS(FS_OS_ANDROID) 
	#include "gles.h"
#else 
	#include "glew.h"
#endif 

#include "material/FsMaterial.h"
#include "graphics/FsRender.h"
#include "graphics/FsProgram.h"

#include "util/FsString.h"

NS_FS_BEGIN

static GLint s_FsTypeToGLenum(int t)
{
	switch(t)
	{
		case FS_FLOAT:
			return GL_FLOAT;
		case FS_INT:
			return GL_INT;
		case FS_INT8:
			return GL_BYTE;
		case FS_INT16:
			return GL_SHORT;
		case FS_INT32:
			return GL_INT;
		case FS_UINT8:
			return GL_UNSIGNED_BYTE;
		case FS_UINT16:
			return GL_UNSIGNED_SHORT;
		case FS_UINT32:
			return GL_UNSIGNED_INT;
		default:
			FS_TRACE_ERROR("Unkown Type");
	}
	return 0;
};

static GLint s_blendToGLenum(int value)
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

		/* opengles not support 
		case Render::EQUATION_MIN:
			return GL_MIN;
		case Render::EQUATION_MAX:
			return GL_MAX;

		case Render::EQUATION_LOGIC_OP:
			return GL_LOGIC_OP; 
		*/

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
	m_program=NULL;

	/* client arrayflags */
	m_arrayFlags=0;

	/* vertex attr array flags [] */
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS,&m_vertexAttrMaxNu);
	m_vertexAttrFlags=new bool[m_vertexAttrMaxNu];
	memset(m_vertexAttrFlags,0,sizeof(bool)*m_vertexAttrMaxNu);
	m_vertexAttrEnableNu=0;


	glClearColor(0,0,0,255);
	m_clearColor=Color::BLACK;

	glClearDepth(1);
//	glClearStencil(0);

	/* depth */
	glDisable(GL_DEPTH_TEST);
	m_depthTest=false;

	m_depthMask=false;

	/* face */
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glDisable(GL_CULL_FACE);

	m_cullFace=SIDE_NONE;
	m_frontFace=FRONT_CCW;




	/* blend */
	glEnable(GL_BLEND);

	/*  opengles not support 
	glBlendEquation(GL_FUNC_ADD);
	*/

	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	m_blendEquation=EQUATION_ADD;
	m_blendSrc=FACTOR_SRC_ALPHA;
	m_blendDst=FACTOR_ONE_MINUS_SRC_ALPHA;

	/* texture */
	glEnable(GL_TEXTURE_2D);
	m_activeTexures=1;

	glMatrixMode(GL_MODELVIEW_MATRIX);
}
Render::~Render()
{
	if(m_target)
	{
		m_target->loseCurrent(this);
		m_target->decRef();
	}

	if(m_material)
	{
		m_material->decRef();
	}

	if(m_program)
	{
		m_program->decRef();
	}
	delete[] m_vertexAttrFlags;
}



void Render::setProjectionMatrix(const Matrix4& m)
{
	float matrix[16]=
	{
		m.m00,m.m10,m.m20,m.m30,
		m.m01,m.m11,m.m21,m.m31,
		m.m02,m.m12,m.m22,m.m32,
		m.m03,m.m13,m.m23,m.m33,
		
	};
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(matrix);

	glMatrixMode(GL_MODELVIEW);
}


void Render::pushMatrix()
{
	glPushMatrix();
}
void Render::popMatrix()
{
	glPopMatrix();
}
void Render::loadIdentity()
{
	glLoadIdentity();
}
void Render::setMatrix(const Matrix4& m)
{
	float matrix[16]=
	{
		m.m00,m.m10,m.m20,m.m30,
		m.m01,m.m11,m.m21,m.m31,
		m.m02,m.m12,m.m22,m.m32,
		m.m03,m.m13,m.m23,m.m33,
		
	};
	glLoadMatrixf(matrix);
}
void Render::mulMatrix(const Matrix4& m)
{
	float matrix[16]=
	{
		m.m00,m.m10,m.m20,m.m30,
		m.m01,m.m11,m.m21,m.m31,
		m.m02,m.m12,m.m22,m.m32,
		m.m03,m.m13,m.m23,m.m33,
		
	};
	glMultMatrixf(matrix);
}
void Render::translate(const Vector3& v)
{
	glTranslatef(v.x,v.y,v.z);
}
void Render::scale(const Vector3& v)
{
	glScalef(v.x,v.y,v.z);
}
void Render::rotate(const Vector3& v,float angle)
{
	glRotatef(angle,v.x,v.y,v.z);
}
void Render::setViewport(int x,int y,int width,int height)
{
	glViewport(x,y,width,height);
}

void Render::setClearColor(Color c)
{
	m_clearColor=c;
	glClearColor(c.r/255.0f,c.g/255.0f,c.b/255.0f,c.a/255.0f);
}


void Render::clear(bool color,bool depth,bool stencil)
{
	GLint flags=0;
	if(color) flags|=GL_COLOR_BUFFER_BIT;
	if(depth) flags|=GL_DEPTH_BUFFER_BIT;
	if(stencil) flags|=GL_STENCIL_BUFFER_BIT;
	glClear(flags);
}

void Render::setScissor(int x,int y,int width,int height)
{
	glScissor(x,y,width,height);
}
void Render::enableScissorTest(bool enable)
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
void Render::enableDepthTest(bool enable)
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
void Render::setDepthMask(bool enable)
{
	if(m_depthMask!=enable)
	{
		glDepthMask(enable);
		m_depthMask=enable;
	}
}

void Render::setLineWidth(float width)
{
	if(m_lineWidth!=width)
	{
		glLineWidth(width);
		m_lineWidth=width;
	}
}

void Render::enableFog(bool enable)
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
	if(mat) 
	{
		mat->load(this);
	}
	m_material=mat;
}
void Render::setProgram(Program* prog)
{
	if(m_program==prog)
	{
		return;
	}

	if(prog) { prog->addRef(); }

	if(m_program)
	{
		m_program->decRef();
		disableAllAttrArray();
	}

	if(prog)
	{
		GLint plat_prog=prog->getPlatformProgram();
		glUseProgram(plat_prog);
	}
	else 
	{
		glUseProgram(0);
	}
	m_program=prog;
}

void Render::setActiveTexture(int nu)
{
	if(nu>1)
	{
		FS_TRACE_WARN("Render Now Not Support Mul Texture");
		nu=1;
	}
	if(m_activeTexures==nu)
	{
		return ;
	}
	if(nu==0)
	{
		glDisable(GL_TEXTURE_2D);
	}
	else 
	{
		glEnable(GL_TEXTURE_2D);
	}
	m_activeTexures=nu;
}
void Render::bindTexture(Texture2D* tex,int /*slot*/)
{
	if(tex)
	{
		glBindTexture(GL_TEXTURE_2D,tex->getPlatformTexture());
	}
	else 
	{
		glBindTexture(GL_TEXTURE_2D,0);
	}
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

void Render::setVVertexPointer(Vector3* v,uint num)
{
	glVertexPointer(3,GL_FLOAT,0,v);
}
void Render::setVNormalPointer(Vector3* v,uint num)
{
	glNormalPointer(GL_FLOAT,0,v);
}
void Render::setVTexCoordPointer(TexCoord2* v,uint num)
{
	glTexCoordPointer(2,GL_FLOAT,0,v);
}
void Render::setVColorPointer(Color* v,uint num)
{
	glColorPointer(4,GL_UNSIGNED_BYTE,0,v);
}
void Render::drawFace3(Face3* f,uint num)
{
	glDrawElements(GL_TRIANGLES,num*3,GL_UNSIGNED_INT,f);
}

void Render::enableClientArray(ulong flags)
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

void Render::disableClientArray(ulong flags)
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

void Render::setBlend(int blend_eq,int factor_src,int factor_dst)
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
		/* opengl es not support 
		glBlendEquation(s_blendToGLenum(blend_eq));
		*/

		glBlendFunc(s_blendToGLenum(factor_src),
				s_blendToGLenum(factor_dst));
	}
	m_blendEquation=blend_eq;
	m_blendSrc=factor_src;
	m_blendDst=factor_dst;
}


/* vertex attribute  */
void Render::setVertexAttrPointer( 
		FsString* name, int size,int type,
		int count,int stride,void* pointer)
{
	if(m_program)
	{
		FS_TRACE_WARN("No Shader Program Used Now");
		return;
	}
	int loc=m_program->getAttributeLocation(name);
	if(loc==-1)
	{
		FS_TRACE_WARN("Attribute Not Used In Program");
		return;
	}
	FS_ASSERT(loc<m_vertexAttrMaxNu);
	GLint type_gl=s_FsTypeToGLenum(type);
	glVertexAttribPointer(loc,size,type_gl,0,stride,pointer);

}
void Render::setVertexAttrPointer(
		const char* name,int size,int type,
		int count,int stride,void* pointer)
{
	FsString* fs_name=new FsString(name);
	setVertexAttrPointer(fs_name,size,type,count,stride,pointer);
	fs_name->decRef();
}

void Render::setAndEnableVertexAttrPointer( 
		FsString* name, int size, int type, 
		int count, int stride, void* pointer)
{
	if(!m_program)
	{
		FS_TRACE_WARN("No Shader Program Used Now");
		return;
	}
	int loc=m_program->getAttributeLocation(name);
	if(loc==-1)
	{
		FS_TRACE_WARN("Attribute(%s) Not Used In Program",name->cstr());
		return;
	}
	FS_ASSERT(loc<m_vertexAttrMaxNu);

	if(!m_vertexAttrFlags[loc])
	{
		glEnableVertexAttribArray(loc);
		m_vertexAttrFlags[loc]=true;
		m_vertexAttrEnableNu++;
	}

	GLint type_gl=s_FsTypeToGLenum(type);
	glVertexAttribPointer(loc,size,type_gl,0,stride,pointer);
}

void Render::setAndEnableVertexAttrPointer( 
		const char* name, int size, int type, 
		int count, int stride, void* pointer)
{
	FsString* fs_name=new FsString(name);
	setAndEnableVertexAttrPointer(fs_name,size,type,count,stride,pointer);
	fs_name->decRef();
}


/* disable/enable vertex attribute */
void Render::disableAllAttrArray()
{
	for(int i=0;i<m_vertexAttrMaxNu;i++)
	{
		if(m_vertexAttrFlags[i])
		{
			glDisableVertexAttribArray(i);
			m_vertexAttrEnableNu--;
			m_vertexAttrFlags[i]=false;
			if(m_vertexAttrEnableNu==0)
			{
				break;
			}
		}

	}
}

void Render::enableAttrArray(const char* name)
{
	FsString* fs_name=new FsString(name);
	enableAttrArray(fs_name);
	fs_name->decRef();
}
void Render::enableAttrArray(FsString* name)
{
	if(m_program)
	{
		FS_TRACE_WARN("No Shader Program Used Now");
		return;
	}
	int loc=m_program->getAttributeLocation(name);
	if(loc==-1)
	{
		FS_TRACE_WARN("Attribute Not Used In Program");
		return;
	}
	FS_ASSERT(loc<m_vertexAttrMaxNu);

	if(!m_vertexAttrFlags[loc])
	{
		m_vertexAttrFlags[loc]=true;
		glEnableVertexAttribArray(loc);
		m_vertexAttrEnableNu++;
	}
}

void Render::disableAttrArray(const char* name)
{
	FsString* fs_name=new FsString(name);
	disableAttrArray(fs_name);
	fs_name->decRef();
}

void Render::disableAttrArray(FsString* name)
{
	if(m_program)
	{
		FS_TRACE_WARN("No Shader Program Used Now");
		return;
	}
	int loc=m_program->getAttributeLocation(name);
	if(loc==-1)
	{
		FS_TRACE_WARN("Attribute Not Used In Program");
		return;
	}
	FS_ASSERT(loc<m_vertexAttrMaxNu);

	if(m_vertexAttrFlags[loc])
	{
		m_vertexAttrFlags[loc]=false;
		glDisableVertexAttribArray(loc);
		m_vertexAttrEnableNu--;
	}
}

void Render::setUniform(FsString* name,int type,int count,void* value)
{
	if(!m_program)
	{
		FS_TRACE_WARN("No Shader Program Used Now");
		return;
	}
	int loc=m_program->getUniformLocation(name);
	if(loc==-1)
	{
		FS_TRACE_WARN("Uniform %s Not Used Int Program",name->cstr());
		return ;
	}
	setUniform(loc,type,count,value);
}

void Render::setUniform(const char* name,int type,int count,void* value)
{
	FsString* fs_name=new FsString(name);
	setUniform(fs_name,type,count,value);
	fs_name->decRef();
}

void Render::setUniform(int loc,int type,int count,void* value)
{                                                                          
	switch(type)
	{
		/* float vec */
		case U_F_1:
			glUniform1fv(loc,count,(GLfloat*) value);
			break;
		case U_F_2:
			glUniform2fv(loc,count,(GLfloat*) value);
			break;
		case U_F_3:
			glUniform3fv(loc,count,(GLfloat*) value);
			break;
		case U_F_4:
			glUniform4fv(loc,count,(GLfloat*) value);
			break;

		/* int vec */                                                      
		case U_I_1:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_I_2:
			glUniform2iv(loc,count,(GLint*) value);
			break;
		case U_I_3:
			glUniform3iv(loc,count,(GLint*) value);
			break;
		case U_I_4:
			glUniform4iv(loc,count,(GLint*) value);
			break;

		/* unsigned int vec */
			/*  opengles not support 
		case U_UI_1:
			glUniform1uiv(loc,count,(GLuint*) value);
			break;
		case U_UI_2:
			glUniform2uiv(loc,count,(GLuint*) value);
			break;
		case U_UI_3:
			glUniform3uiv(loc,count,(GLuint*) value);
			break;
		case U_UI_4:
			glUniform4uiv(loc,count,(GLuint*) value);
			break;
			*/


		/* matrix vec */
		case U_M_2:
			glUniformMatrix2fv(loc,count,true,(GLfloat*) value);
			break;
		case U_M_3:
			glUniformMatrix3fv(loc,count,true,(GLfloat*) value);      
			break;
		case U_M_4:
			glUniformMatrix4fv(loc,count,true,(GLfloat*) value);
			break;

		/* sampler */
		case U_S_1D:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_2D:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_3D:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_CUBE:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_1D_SHADOW:      
			glUniform1iv(loc,count,(GLint*) value);
			break;
		case U_S_2D_SHADOW:
			glUniform1iv(loc,count,(GLint*) value);
			break;
		default:
			FS_TRACE_WARN("Unkown Uniform Type");
	}
}

//void Render::enablePolygonOffset(bool){}
//oid Render::setPolygonOffset(float factor,float units);




/* aux func for quick draw */
void Render::drawLine(const Vector3 start,const Vector3 end,float width,Color c)
{
	setActiveTexture(0);
	setMaterial(NULL);
	setProgram(NULL);

	/*
	glColor3ub(c.r,c.g,c.b);
	glLineWidth(width);
	glBegin(GL_LINES);
	glVertex3fv(start.v);
	glVertex3fv(end.v);
	glEnd();
	*/
}
NS_FS_END


