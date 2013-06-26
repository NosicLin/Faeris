# Normal Information 
CC=gcc
FLAGS= -g -Wall  -Werror -DLINUX
FILE_EXT=cc

#Project infor 
PROJECT_PATH=../../build/linux/prebuild/
PROJECT=libfaeris

# User Config Information 
LIB_DIR=$(PROJECT_PATH)debug
OBJ_DIR=$(PROJECT_PATH)obj
SRC_DIR=../src
INCLUDE_DIR=-I../src  -I./

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
	 io/FsMemFile.cc \
	 io/FsPackage.cc \
	 io/FsRenderTarget.cc \
	 io/FsSysFile.cc \
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
	 math/FsTexCoord2.cc \
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
	 support/data/FsBase64.cc \
	 support/data/FsDeflate.cc \
	 support/data/FsEncrypt.cc \
	 support/data/FsHash.cc \
	 support/data/FsIconv.cc \
	 support/data/FsUnicode.cc \
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
	 sys/FsThread.cc \
	 sys/FsTimer.cc \
	 sys/FsWindow.cc \
	 util/FsArray.cc \
	 util/FsDirector.cc \
	 util/FsInteger.cc \
	 util/FsLog.cc \
	 util/FsPathUtil.cc \
	 util/FsScriptUtil.cc \
	 util/FsSlowArray.cc \
	 util/FsString.cc \
	 FsFaerisModule.cc 










	

#full src name 
SRC_NAME_WITH_PATH=$(addprefix $(SRC_DIR)/,$(SRC))

#obj name 
OBJ_NAME=$(SRC:%.$(FILE_EXT)=%.o) 
OBJ_NAME_WITH_PATH=$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))


main:$(LIB_DIR)/lib$(PROJECT).a

$(LIB_DIR)/lib$(PROJECT).a: $(OBJ_NAME_WITH_PATH) 
	ar cr $@ $(OBJ_NAME_WITH_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(FILE_EXT)
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDE_DIR) 


