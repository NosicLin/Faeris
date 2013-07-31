# Normal Information 
CC=gcc
FILE_EXT=cc

FLAGS_DEBUG= -g -Wall  -Werror -DLINUX
FLAGS_RELEASE= -O3 -Wall -Werror -DLINUX

#Project infor 
PROJECT_PATH= ../../library/linux/
PROJECT=faeris

SRC_DIR=../src
INCLUDE_DIR=-I../src \
			-I../src/support  \
		   	-I../../lib3rdparty/freetype/include \
		   	-I../../lib3rdparty/libpng/include \
		   	-I../../lib3rdparty/lua/include \
		   	-I../../lib3rdparty/minizip/include \
		   	-I../../lib3rdparty/tolua++/include \
		   	-I../../lib3rdparty/lua/include \
		   	-I../../lib3rdparty/zlib/include \

#Source File 
SRC= common/FsGlobal.cc \
	 common/FsScriptEngine.cc \
	 core/FsObject.cc \
	 entity/FsColorQuad2D.cc \
	 entity/FsEntity.cc \
	 entity/FsLabelBitmap.cc \
	 entity/FsLabelTTF.cc \
	 entity/FsQuad2D.cc \
	 entity/FsSprite2D.cc \
	 entity/FsSprite2DData.cc \
	 event/FsKeypadDispatcher.cc \
	 event/FsSysDispatcher.cc \
	 event/FsTouchDispatcher.cc \
	 graphics/FsColor.cc \
	 graphics/FsFontBitmap.cc \
	 graphics/FsFontTTF.cc \
	 graphics/FsImage2D.cc \
	 graphics/FsProgram.cc \
	 graphics/FsRender.cc \
	 graphics/FsTexture2D.cc \
	 io/FsFile.cc \
	 io/FsSysFile.cc \
	 io/FsSegFile.cc \
	 io/FsMemFile.cc \
	 io/FsPackage.cc \
	 io/FsFgzPackage.cc \
	 io/FsVFS.cc \
	 io/FsZipPackage.cc \
	 material/FsMat_V4F_C4F.cc \
	 material/FsMat_V4F_T2F.cc \
	 material/FsMat_V4F_T2F_A1F.cc \
	 material/FsMaterial.cc \
	 math/FsMathUtil.cc \
	 math/FsMatrix4.cc \
	 math/FsQuaternion.cc \
	 math/FsRect2D.cc \
	 mgr/FsFontTTFDataMgr.cc \
	 mgr/FsResource.cc \
	 mgr/FsResourceMgr.cc \
	 mgr/FsSprite2DDataMgr.cc \
	 mgr/FsTextureMgr.cc \
	 scene/FsColorLayer.cc \
	 scene/FsDirector.cc \
	 scene/FsLayer.cc \
	 scene/FsLayer2D.cc \
	 scene/FsScene.cc \
	 scheduler/FsScheduler.cc \
	 scheduler/FsSchedulerTarget.cc \
	 scheduler/FsTask.cc \
	 support/data/FsBase64.cc \
	 support/data/FsDeflate.cc \
	 support/data/FsEncrypt.cc \
	 support/data/FsHash.cc \
	 support/data/FsIconv.cc \
	 support/data/FsUnicode.cc \
	 support/data/FsFgzReader.cc \
	 support/data/FsZipReader.cc \
	 support/felis/sl_comment.cc \
	 support/felis/sl_double_quote_str.cc \
	 support/felis/sl_simple_str.cc \
	 support/felis/sl_single_quote_str.cc \
	 support/felis/sl_specific_symbol.cc \
	 support/felis/sl_top.cc \
	 support/felis/sl_white_space.cc \
	 support/felis/xir_file.cc \
	 support/felis/xir_grammer.cc \
	 support/felis/xir_parser.cc \
	 support/felis/xir_scanner.cc \
	 support/felis/xir_token.cc \
	 support/image/FsImageDecoder.cc \
	 support/image/FsImagePng.cc \
	 sys/FsSys.cc \
	 sys/FsTimer.cc \
	 sys/FsWindow.cc \
	 sys/FsMutex.cc \
	 sys/FsSemaphore.cc \
	 sys/FsThread.cc \
	 util/FsArray.cc \
	 util/FsDict.cc \
	 util/FsInteger.cc \
	 util/FsLog.cc \
	 util/FsPathUtil.cc \
	 util/FsScriptUtil.cc \
	 util/FsSlowArray.cc \
	 util/FsString.cc \
	 FsFaerisModule.cc 


include ../../MK_BUILD_STATIC_LIB