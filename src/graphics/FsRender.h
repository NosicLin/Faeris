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
			SHADER_MODE_SMOOTH,
			SHADER_MODE_FLAT,

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
		static FsVoid purgeShareRender();
		static FsInt uniformTypeSize(FsInt type);
	public:
		FsVoid setMaterial(Material* m,FsBool force=false);
		FsVoid setProgram(Program* prog);
		FsVoid setRenderTarget(RenderTarget* target);
		FsVoid swapBuffers();


		/* color */
		FsVoid setClearColor(Color c);
		Color getClearColor(){return m_clearColor;}
		FsVoid clear(FsBool color=true,FsBool depth=true,FsBool stencil=false);

		/* transform */
		FsVoid pushMatrix();
		FsVoid popMatrix();
		FsVoid mulMatrix(const Matrix4& m);
		FsVoid setMatrix(const Matrix4& m);
		FsVoid translate(const Vector3& t);
		FsVoid scale(const Vector3& s);
		FsVoid rotate(const Vector3& v,FsFloat angle);



		/* vertex pointer */
		FsVoid setVVertexPointer(Vector3* v,FsUint num);
		FsVoid setVColorPointer(Color* c,FsUint num);
		FsVoid setVNormalPointer(Vector3* n,FsUint num);
		FsVoid setVTexCoordPointer(TexCoord2* t,FsUint num);

		/* enable/disable client vertex array */
		FsVoid enableClientArray(FsUlong flags);
		FsVoid disableClientArray(FsUlong flags);
		FsVoid disableAllClientArray();



		/* vertex attribute pointer */

		FsVoid setVertexAttrPointer( 
				FsString* name, FsInt size,FsInt type,
				FsInt count,FsInt stride,FsVoid* pointer);
		FsVoid setVertexAttrPointer(
				const FsChar* name,FsInt size,FsInt type,
				FsInt count,FsInt stride,FsVoid* pointer);

		FsVoid setAndEnableVertexAttrPointer( 
				FsString* name, FsInt size, FsInt type, 
				FsInt count, FsInt stride, FsVoid* pointer);

		FsVoid setAndEnableVertexAttrPointer( 
				const FsChar* name, FsInt size, FsInt type, 
				FsInt count, FsInt stride, FsVoid* pointer);


		/* disable/enable vertex attribute */
		FsVoid disableAllAttrArray();
		FsVoid enableAttrArray(const FsChar* name);
		FsVoid enableAttrArray(FsString* name);

		FsVoid disableAttrArray(const FsChar* name);
		FsVoid disableAttrArray(FsString* name);


		/* draw triangle*/
		FsVoid drawFace3(Face3* f,FsUint num);

		/* set uniform value for current program */
		FsVoid setUniform(FsString* name,FsInt type,FsInt count,FsVoid* value);
		FsVoid setUniform(const FsChar* name,FsInt type,FsInt count,FsVoid* value);
		FsVoid setUniform(FsInt loc,FsInt type,FsInt count,FsVoid* value);



		/* set opengl state */
		FsVoid setViewport(FsInt x,FsInt y,FsInt width,FsInt height);
		FsVoid setScissor(FsInt x,FsInt y,FsInt width,FsInt height);
		FsVoid enableScissorTest(FsBool enable);
		FsVoid enableDepthTest(FsBool enable);
		FsVoid setDepthMask(FsBool enable);
		FsVoid setLineWidth(FsFloat width);
		FsVoid enableFog(FsBool enable);

		/* blend */
		FsVoid setBlend(FsInt blend_eq,FsInt factor_src,FsInt factor_dst);

	private:
		Render();
		~Render();
	private:
		RenderTarget* m_target;
		Material* m_material;
		Program* m_program;

		/* cache GL State */
		Color m_clearColor;
		FsBool m_scissorEnable;

		/* depth */
		FsBool m_depthTest;
		FsBool m_depthMask;

		FsFloat m_lineWidth;
		FsBool m_fogEnable;

		/* blend */
		FsInt m_blendEquation;
		FsInt m_blendSrc;
		FsInt m_blendDst;

		/* face */
		FsInt m_frontFace;
		FsInt m_cullFace;


		/* client array */
		FsUlong m_arrayFlags;


		/* vertex attr array flags []*/
		FsBool* m_vertexAttrFlags;
		FsInt m_vertexAttrEnableNu;
		FsInt m_vertexAttrMaxNu;


};

NS_FS_END
#endif /*_FS_RENDER_H_*/



















