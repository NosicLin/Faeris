#ifndef _FS_RENDER_H_
#define _FS_RENDER_H_
#include "FsMacros.h"
#include "graphics/FsColor.h"
#include "graphics/FsRenderTarget.h"
#include "math/FsMatrix4.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#include "math/FsFace3.h"

NS_FS_BEGIN
class Material;
class FsString;
class Program;

class Render 
{
	public:
		enum 
		{
			VERTEX_ARRAY=(0x1ul<<0),
			COLOR_ARRAY=(0x1ul<<1),
			NORMAL_ARRAY=(0x1ul<<2),
			TEXTURE_COORD_ARRAY=(0x1ul<<3),
			ALL_ARRAY=VERTEX_ARRAY|COLOR_ARRAY|NORMAL_ARRAY|TEXTURE_COORD_ARRAY,
		};
		enum 
		{
			/* float vec2 vec3 vec4 */
			U_F_1=0,
			U_F_2,
			U_F_3,
			U_F_4,

			/* int ivec2 ivec3 ivec4 */
			U_I_1,
			U_I_2,
			U_I_3,
			U_I_4,

			/* unsigned int uvec2 uvec3 uvec4 */
			U_UI_1,
			U_UI_2,
			U_UI_3,
			U_UI_4,

			/* mat2 mat3 mat4 */
			U_M_2,
			U_M_3,
			U_M_4,

			/* sampler */
			U_S_1D,         /* sampler1D,sampler2D,sampler3D */
			U_S_2D,
			U_S_3D,
			U_S_CUBE,       /* samplerCube */
			U_S_1D_SHADOW,  /* sampler1DShadow, sampler2DShadow */
			U_S_2D_SHADOW,

			U_MAX_NU,
		};
		enum 
		{
			/* front side */
			FRONT_CCW,
			FRONT_CW,

			/* shader mode */
			SHADE_MODE_SMOOTH,
			SHADE_MODE_FLAT,

			/* front and back */
			SIDE_FRONT,
			SIDE_BACK,
			SIDE_FRONT_AND_BACK,
			SIDE_NONE,

			/* blend equation */
			EQUATION_NONE,
			EQUATION_ADD,
			EQUATION_SUBTRACT,
			EQUATION_REVERSE_SUBTRACT,
			EQUATION_MIN,
			EQUATION_MAX,
			EQUATION_LOGIC_OP,

			/* blend factor */
			FACTOR_ZERO,
			FACTOR_ONE,
			FACTOR_SRC_COLOR,
			FACTOR_ONE_MINUS_SRC_COLOR,
			FACTOR_DST_COLOR,
			FACTOR_ONE_MINUS_DST_COLOR,
			FACTOR_SRC_ALPHA,
			FACTOR_ONE_MINUS_SRC_ALPHA,
			FACTOR_DST_ALPHA,
			FACTOR_ONE_MINUS_DST_ALPHA,
			FACTOR_SRC_ALPHA_SATURATE,

		};

	public:
		static Render* shareRender();
		static void purgeShareRender();
		static int sizeofUniformType(int type);
		static int uniformTypeComponent(int type);
	public:
		void setMaterial(Material* m,bool force=false);
		void setProgram(Program* prog);
		void setRenderTarget(RenderTarget* target);
		void swapBuffers();


		/* color */
		void setClearColor(Color c);
		Color getClearColor(){return m_clearColor;}
		void clear(bool color=true,bool depth=true,bool stencil=false);

		/* transform */
		void setProjectionMatrix(const Matrix4& mat);
		void pushMatrix();
		void popMatrix();
		void loadIdentity();
		void mulMatrix(const Matrix4& m);
		void setMatrix(const Matrix4& m);
		void translate(const Vector3& t);
		void scale(const Vector3& s);
		void rotate(const Vector3& v,float angle);



		/* vertex pointer */
		void setVVertexPointer(Vector3* v,uint num);
		void setVColorPointer(Color* c,uint num);
		void setVNormalPointer(Vector3* n,uint num);
		void setVTexCoordPointer(TexCoord2* t,uint num);

		/* enable/disable client vertex array */
		void enableClientArray(ulong flags);
		void disableClientArray(ulong flags);
		void disableAllClientArray();



		/* vertex attribute pointer */

		void setVertexAttrPointer( 
				FsString* name, int size,int type,
				int count,int stride,void* pointer);
		void setVertexAttrPointer(
				const char* name,int size,int type,
				int count,int stride,void* pointer);

		void setAndEnableVertexAttrPointer( 
				FsString* name, int size, int type, 
				int count, int stride, void* pointer);

		void setAndEnableVertexAttrPointer( 
				const char* name, int size, int type, 
				int count, int stride, void* pointer);


		/* disable/enable vertex attribute */
		void disableAllAttrArray();
		void enableAttrArray(const char* name);
		void enableAttrArray(FsString* name);

		void disableAttrArray(const char* name);
		void disableAttrArray(FsString* name);


		/* draw triangle*/
		void drawFace3(Face3* f,uint num);

		/* set uniform value for current program */
		void setUniform(FsString* name,int type,int count,void* value);
		void setUniform(const char* name,int type,int count,void* value);
		void setUniform(int loc,int type,int count,void* value);



		/* set opengl state */
		void setViewport(int x,int y,int width,int height);
		void setScissor(int x,int y,int width,int height);
		void enableScissorTest(bool enable);
		void enableDepthTest(bool enable);
		void setDepthMask(bool enable);
		void setLineWidth(float width);
		void enableFog(bool enable);

		void setShadeMode(int mode);
		void setOpacity(float value);

		/* blend */
		void setBlend(int blend_eq,int factor_src,int factor_dst);


		/* aux draw quick function*/
		void drawLine(const Vector3 start,const Vector3 end,float width,Color c);

	private:
		Render();
		~Render();
	private:
		RenderTarget* m_target;
		Material* m_material;
		Program* m_program;

		/* cache GL State */
		Color m_clearColor;
		bool m_scissorEnable;

		/* depth */
		bool m_depthTest;
		bool m_depthMask;

		float m_lineWidth;
		bool m_fogEnable;

		/* blend */
		int m_blendEquation;
		int m_blendSrc;
		int m_blendDst;

		/* face */
		int m_frontFace;
		int m_cullFace;


		/* client array */
		ulong m_arrayFlags;


		/* vertex attr array flags []*/
		bool* m_vertexAttrFlags;
		int m_vertexAttrEnableNu;
		int m_vertexAttrMaxNu;


};

NS_FS_END
#endif /*_FS_RENDER_H_*/



















