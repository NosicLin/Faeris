#ifndef _FAERIS_MACROS_H_
#define _FAERIS_MACROS_H_
#include <assert.h>



#define FS_BEGIN_NAMESPACE(name) namespace name{
#define FS_END_NAMESPACE(name) }

#define NS_FS_BEGIN FS_BEGIN_NAMESPACE(Faeris)
#define NS_FS_END FS_END_NAMESPACE(Faeris)
#define NS_FS_USE using namespace Faeris;


#if defined(WIN32)
	#define FS_OS_WIN32
#elif defined(LINUX)
	#define FS_OS_LINUX
#elif defined(ANDROID)
	#define FS_OS_ANDROID
#else
	#error "UNKOWN PLATFORM OS"
#endif


#define FS_PLATFORM_OS defined


#ifndef NULL
	#define NULL 0
#endif 


#if defined(FS_OS_WIN32)
#define snprintf _snprintf
#endif 

#include<stdio.h>
#define FsStdout_Write printf
#define FsStd_Flush fflush

#define FS_CONDTION_ON(tag,cnd,fmt,...) \
	do{\
		if(cnd) \
		{ \
			FsStdout_Write("%s:",#tag); \
			FsStdout_Write("%s:%s:%d:",__FILE__,__FUNCTION__,__LINE__); \
			FsStdout_Write("%s:",#cnd); \
			FsStdout_Write(fmt,##__VA_ARGS__); \
            FsStdout_Write("\n"); \
            FsStd_Flush(stdout); \
		}\
	} while(0)

#define FS_MESSAGE(tag,fmt,...) \
	do{\
		FsStdout_Write("%s:",#tag); \
		FsStdout_Write("%s:%s:%d:",__FILE__,__FUNCTION__,__LINE__); \
		FsStdout_Write(fmt,##__VA_ARGS__); \
		FsStdout_Write("\n"); \
        FsStd_Flush(stdout); \
    } while(0)

#define FS_TRACE_WARN_ON(cnd,fmt,...) \
	FS_CONDTION_ON(WARN_ON,cnd,fmt,##__VA_ARGS__) 

#define FS_TRACE_ERROR_ON(cnd,fmt,...) \
	FS_CONDTION_ON(ERROR_ON,cnd,fmt,##__VA_ARGS__) 

#define FS_TRACE_INFO_ON(cnd,fmt,...) \
	FS_CONDTION_ON(INFO_ON,cnd,fmt,##__VA_ARGS__) 


#define FS_TRACE_WARN(fmt,...) \
	FS_MESSAGE(WARN,fmt,##__VA_ARGS__)

#define FS_TRACE_ERROR(fmt,...) \
	FS_MESSAGE(ERROR,fmt,##__VA_ARGS__)

#define FS_TRACE_INFO(fmt,...) \
	FS_MESSAGE(INFO,fmt,##__VA_ARGS__)


#define FS_ASSERT(condtion) \
	assert(condtion)



/* copy able */
#define FS_FEATURE public

#define FS_MAKE_NO_COPYABLE(class_name) \
	private: \
    class_name& operator&(class_name& /*other*/){return *this;} \
    class_name& operator=(class_name& /*other*/){return *this;}




/* for safe add and dec object refrence */

#define FS_SAFE_ADD_REF(f) \
	do{ if(f) f->addRef(); }while(0)

#define FS_SAFE_DEC_REF(f) \
	do{ if(f) f->decRef();} while(0)



/* global Macros For Faeris */

/* event part*/




#define FS_MASK_LSHIFT (0x1ul<<0)
#define FS_MASK_RSHIFT (0x1ul<<1)
#define FS_MASK_SHIFT (FS_MASK_LSHIFT|FS_MASK_RSHIFT)
#define FS_MASK_LALT (0x1ul<<2)
#define FS_MASK_RALT (0x1ul<<3)
#define FS_MASK_ALT (FS_MASK_LALT|FS_MASK_RALT)
#define FS_MASK_LCTRL (0x1ul<<4)
#define FS_MASK_RCTRL (0x1ul<<5)
#define FS_MASK_CTRL (FS_MASK_LCTRL|FS_MASK_RCTRL)
#define FS_MASK_LBUTTON (0x1ul<<6) 
#define FS_MASK_MBUTTON (0x1ul<<7)
#define FS_MASK_RBUTTON (0x1ul<<8)




#define FS_LBUTTON (0x1ul<<6)
#define FS_RBUTTON (0x1ul<<7)
#define FS_MBUTTON (0x1ul<<8)

#define FS_DOWN 0x1 
#define FS_UP 0x2 
#define FS_CLICK 0x3 
#define FS_DCLICK 0x4
#define FS_MOVE 0x5


/* Frame Buffer */
#define FS_BUFFER_LEFT
#define FS_BUFFER_RIGHT
#define FS_BUFFER_FRONT
#define FS_BUFFER_BACK
#define FS_BUFFER_SINGLE 
#define FS_BUFFER_DOUBLE 
#define FS_BUFFER_STENCIL
#define FS_BUFFER_SAMPLES 
#define FS_BUFFER_DEPTH
#define FS_BUFFER_RGB 
#define FS_BUFFER_RGBA



/* EULER  OLDER */
enum 
{
	FS_EULER_XYZ =0,
	FS_EULER_XZY ,
	FS_EULER_YXZ ,
	FS_EULER_YZX ,
	FS_EULER_ZXY ,
	FS_EULER_ZYX 
};




/* file type */
#define FS_FILE_UNKOWN (0x1)
#define FS_FILE_BINARY (0x2)
#define FS_FILE_SCRIPT (0x3)


enum 
{
	FS_FLOAT=0,
	FS_INT,

	FS_INT8,
	FS_INT16,
	FS_INT32,

	FS_UINT8,
	FS_UINT16,
	FS_UINT32,

	FS_MAX_TYPE_NU,
};


/* file type */
enum 
{
	FS_FTYPE_SCRIPT,
	FS_FTYPE_BINARY
};


/* bound type */
enum 
{
	FS_BOUND_BOX,
	FS_BOUND_SPHERE
};

/* window name */
#define FS_DEFAULT_WINDOW_NAME "FaerisEngine"


/* class name */
#define FS_IMAGE2D_CLASS_NAME "Image2D"
#define FS_SYSFILE_CLASS_NAME "SysFile"


/* entity */
#define FS_ENTITY_CLASS_NAME "Entity"
#define FS_COLOR_QUAD2D_CLASS_NAME "ColorQuad2D"
#define FS_QUAD2D_CLASS_NAME   "Quad2D"
#define FS_LABEL_TTF_CLASS_NAME "LabelTTF"
#define FS_SPRITE2D_ANIMATION_CLASS_NAME "Sprite2DAnimation"
#define FS_SPRITE2D_DATA_CLASS_NAME "Sprite2DData"
#define FS_SPRITE2D_CLASS_NAME "Sprite2D"

/* scene */
#define FS_DIRECTOR_CLASS_NAME "Director"
#define FS_SCENE_CLASS_NAME "Scene"
#define FS_LAYER_CLASS_NAME "Layer"
#define FS_COLOR_LAYER_CLASS_NAME "ColorLayer"
#define FS_LAYER_2D_CLASS_NAME "Layer2D"


/* util */
#define FS_ARRAY_CLASS_NAME "FsArray"
#define FS_SLOW_ARRAY_CLASS_NAME "FsSlowArray"

/* material */
#define FS_MATERIAL_CLASS_NAME "Material"
#define FS_QUAD_2D_MATERIAL_CLASS_NAME "Quad2DMaterial"
#define FS_POSITION_ALPHA_TEXTURE_MATERIAL_CLASS_NAME "PositionAlphaTextureMaterial"
#define FS_POSITION_TEXTURE_MATERIAL_CLASS_NAME "PositionTextureMaterial"

/* sys */
#define FS_WINDOW_CLASS_NAME "Window"

/* event */
#define FS_TOUCH_EVENT_LISTENER_CLASS_NAME "TouchEventListener"
#define FS_TOUCH_DISPATCHER_CLASS_NAME "TouchDispatcher"
#define FS_SYS_DISPATCHER_CLASS_NAME "SysDispatcher"
#define FS_SYS_EVENT_LISTENER_CLASS_NAME "SysEventListener"

/* scheduler */
#define FS_SCHEDULER_CLASS_NAME "Scheduler"
#define FS_SCHEDULER_TARGET_CLASS_NAME "SchedulerTarget"


/* graphics */
#define FS_RENDER_CLASS_NAME "Render"
#define FS_TEXTURE2D_CLASS_NAME "Texture2D"
#define FS_GLYPH_CLASS_NAME  "Glyph"
#define FS_FONT_TTF_DATA_CLASS_NAME "FontTTFData"
#define FS_FONT_TTF_CLASS_NAME "FontTTF"

/* mgr */
#define FS_TEXTURE_MGR_CLASS_NAME "TextureMgr"
#define FS_FONT_TTF_DATA_MGR_CLASS_NAME  "FontTTFDataMgr"
#define FS_SPRITE_2D_DATA_MGR_CLASS_NAME "Sprite2DDataMgr"



#include "FsTypes.h"



#endif /*_FAERIS_MACROS_H_*/



