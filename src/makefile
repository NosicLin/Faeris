# Normal Information 
CC=g++
FLAGS= -g -Wall  -Werror -DLINUX
FILE_EXT= cc 

#Project infor 
PROJECT_PATH=../build/linux
PROJECT=faeris

# User Config Information 
LIB_DIR=$(PROJECT_PATH)/prebuild/debug
OBJ_DIR=$(PROJECT_PATH)/obj
SRC_DIR=.
INCLUDE_DIR=-I../src  \
			-I./ \
			-I../src/support  \
			-I../platform/thirdparty/linux/freetype \
			-I../platform/thirdparty/linux

#Source File 
SRC=  common/FsGlobal.cc \
	  common/FsScriptEngine.cc \
	  core/FsObject.cc \
	  entity/FsColorQuad2D.cc \
	  entity/FsEntity.cc \
	  entity/FsLabelTTF.cc \
	  entity/FsQuad2D.cc \
	  entity/FsSprite2DData.cc \
	  entity/FsSprite2D.cc \
	  event/FsSysDispatcher.cc \
	  event/FsSysEventListener.cc \
	  event/FsTouchDispatcher.cc \
	  event/FsTouchEventListener.cc \
	  graphics/FsColor.cc \
	  graphics/FsFontTTF.cc \
	  graphics/FsImage2D.cc \
	  graphics/FsProgram.cc \
	  graphics/FsRender.cc \
	  graphics/FsTexture2D.cc \
	  io/FsFile.cc \
	  io/FsSysFile.cc \
	  io/FsVFS.cc \
	  material/FsColorQuad2DMaterial.cc \
	  material/FsMaterial.cc \
	  material/FsPositionTextureMaterial.cc \
	  material/FsShaderMaterial.cc \
	  material/FsPositionAlphaTextureMaterial.cc \
	  math/FsMathUtil.cc \
	  math/FsMatrix4.cc \
	  math/FsRect2D.cc \
	  mgr/FsFontTTFDataMgr.cc \
	  mgr/FsResource.cc \
	  mgr/FsResourceMgr.cc \
	  mgr/FsTextureMgr.cc \
	  mgr/FsSprite2DDataMgr.cc \
	  scene/FsColorLayer.cc \
	  scene/FsDirector.cc \
	  scene/FsLayer.cc \
	  scene/FsLayer2D.cc \
	  scene/FsScene.cc \
	  scheduler/FsScheduler.cc \
	  scheduler/FsSchedulerTarget.cc \
	  support/data/FsBase64.cc \
	  support/data/FsDeflate.cc \
	  support/data/FsHash.cc \
	  support/data/FsIconv.cc \
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
	  support/image/FsImageFaw.cc  \
	  support/image/FsImageJpeg.cc \
	  support/image/FsImagePng.cc \
	  sys/FsSys.cc \
	  sys/FsTimer.cc \
	  sys/FsWindow.cc \
	  util/FsArray.cc \
	  util/FsDict.cc \
	  util/FsLog.cc \
	  util/FsPathUtil.cc \
	  util/FsScriptUtil.cc \
	  util/FsSlowArray.cc \
	  util/FsString.cc \


#full src name 
SRC_NAME_WITH_PATH=$(addprefix $(SRC_DIR)/,$(SRC))

#obj name 
OBJ_NAME=$(SRC:%.cc=%.o) 
#OBJ_NAME_WITH_PATH=$(addprefix $(OBJ_DIR)/,$(notdir $(OBJ_NAME)))
OBJ_NAME_WITH_PATH=$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

ALL_OBJ_DIR=$(sort $(dir $(OBJ_NAME_WITH_PATH)))



main:$(LIB_DIR)/lib$(PROJECT).a

$(LIB_DIR)/lib$(PROJECT).a: $(ALL_OBJ_DIR) $(OBJ_NAME_WITH_PATH) 
	echo $(ALL_OBJ_DIR)
	ar cr $@ $(OBJ_NAME_WITH_PATH)

$(ALL_OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(FILE_EXT)
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDE_DIR) 


clean:
	rm -rf $(OBJ_DIR)/*













