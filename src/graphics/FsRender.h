#ifndef _FS_RENDER_H_
#define _FS_RENDER_H_
#include "FsMacros.h"

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
		void setMaterial(Material* m);
		void setRenderTarget(RenderTarget* target);

		void setViewport(FsInt x,FsInt y,FsInt width,FsInt height);
		void setScissor(FsInt x,FsInt y,FsInt width,FsInt height);


		/* color */
		void setClearColor(Color c);
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

};

FAERIS_NAMESPACE_END 

#endif /*_FS_RENDER_H_*/

