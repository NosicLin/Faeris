#ifndef _FS_RENDER_H_
#define _FS_RENDER_H_
#include "FsMacros.h"
#include "graphics/FsColor.h"
#include "graphics/FsMaterial.h"
#include "graphics/FsRenderTarget.h"
#include "math/FsMatrix4.h"
#include "math/FsVector3.h"
#include "math/FsTexCoord2.h"
#include "math/FsFace3.h"

FAERIS_NAMESPACE_BEGIN 
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

	public:
		static Render* instance();
	public:
		void setMaterial(Material* m,FsBool force=false);
		void setRenderTarget(RenderTarget* target);
		void swapBuffers();


		/* color */
		void setClearColor(Color c);
		Color getClearColor(){return m_clearColor;}
		void clear(FsBool color=true,FsBool depth=true,FsBool stencil=false);

		/* transform */
		void pushMatrix();
		void popMatrix();
		void mulMatrix(const Matrix4& m);
		void setMatrix(const Matrix4& m);
		void translate(const Vector3& t);
		void scale(const Vector3& s);
		void rotate(const Vector3& v,FsFloat angle);



		/* vertex pointer */
		void setVVertexPointer(Vector3* v,FsUint num);
		void setVColorPointer(Color* c,FsUint num);
		void setVNormalPointer(Vector3* n,FsUint num);
		void setVTexCoordPointer(TexCoord2* t,FsUint num);
		void drawFace3(Face3* f,FsUint num);

		/* client vertex array */
		void enableClientArray(FsUlong flags);
		void disableClientArray(FsUlong flags);
		void disableAllClientArray();


		void setViewport(FsInt x,FsInt y,FsInt width,FsInt height);
		void setScissor(FsInt x,FsInt y,FsInt width,FsInt height);
		void enableScissorTest(FsBool enable);
		void enableDepthTest(FsBool enable);
		void setDepthMask(FsBool enable);
		void setLineWidth(FsFloat width);
		void enableFog(FsBool enable);
	private:
		Render();
	private:
		RenderTarget* m_target;
		Material* m_material;

		/* cache GL State */
		Color m_clearColor;
		FsBool m_scissorEnable;
		FsBool m_depthTest;
		FsBool m_depthMask;
		FsBool m_lineWidth;
		FsBool m_fogEnable;

		/* client array */
		FsUlong m_arrayFlags;
};

FAERIS_NAMESPACE_END 

#endif /*_FS_RENDER_H_*/

