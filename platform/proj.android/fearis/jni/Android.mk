LOCAL_PATH :=$(call my-dir)../../../../src 

include $(CLEAR_VARS)

LOCAL_MODULE :=faeris_static

LOCAL_C_INCLUDES:=-I../src  \
	-I./ \
	-I../src/support  \
	-I../platform/thirdparty/linux/freetype \
	-I../platform/thirdparty/linux


LOCAL_SRC_FILES :=  common/FsGlobal.cc \
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
	io/FsPackage.cc \
	io/FsZipPackage.cc \
	io/FsMemFile.cc \
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


include $(BUILD_STATIC_LIBRARY)









