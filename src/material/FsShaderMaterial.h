#ifndef _FS_SHADER_MATERIAL_H_
#define _FS_SHADER_MATERIAL_H_

#include "FsMacros.h"
#include "material/FsMaterial.h"
#include "core/FsObject.h"


NS_FS_BEGIN
class Render;
class Program;
class FsDict;
class ShaderMaterial:public Material
{
	public:
		class Uniform:public FsObject
		{
			public:
				FsString* m_name;
				FsInt m_type;
				FsInt m_count;
				FsInt m_location;
				FsVoid* m_value;
			public:
				Uniform(FsString* name,FsInt type,FsInt count);
				virtual ~Uniform();

				void setValue(void* value);
				virtual const FsChar* getName();
		};
	public:
		void setShadeMode(FsInt mode){m_shadeMode=mode;}
		void enableWireFrame(FsBool enable){m_wireFrame=enable;}
		void setWireFrameWidth(FsInt width){m_wireFrameWidth=width;}
		void setProgram(Program* prog);

		void setUniform(const FsChar* name,FsVoid* value);
		void addUniform(ShaderMaterial::Uniform* u);
	public:
		ShaderMaterial();
		virtual ~ShaderMaterial();
		virtual const FsChar* getName();
		virtual void load(Render* r);
		virtual void unload(Render* r);
	protected:
		void refreshUniform();
		void configRender(Render* r);

	private:
		FsBool m_wireFrame;
		FsInt m_wireFrameWidth;
		Program* m_program;
		FsDict* m_uniforms;
};
NS_FS_END
#endif /*_FS_SHADER_MATERIAL_H_*/

