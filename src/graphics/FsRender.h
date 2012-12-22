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
	enum 
	{
		VERTEX_ARRAY=0,
		COLOR_ARRAY,
		NORMAL_ARRAY,
		TEXTURE_COORD_ARRAY
	};

	public:
		static Render* instance();
	public:
		void setMaterial(Material* m,FsBool force);
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
		void setVertexPointer(Vector3* v,FsUint num);
		void setColorPointer(Color* c,FsUint num);
		void setNormalVertexPointer(Vector3* n,FsUint num);
		void setTexCoordPointer(TexCoord2* t,FsUint num);
		void drawFace3(Face3* f,FsUint num);
		void enableClientArray(FsInt array);
		void disableClientArray(FsInt array);


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

};

FAERIS_NAMESPACE_END 

#endif /*_FS_RENDER_H_*/

