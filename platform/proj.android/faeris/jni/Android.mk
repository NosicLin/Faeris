LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=faeris_static

LOCAL_SRC_FILES :=  src/org_faeris_lib_FsEngine.cc \
					src/org_faeris_lib_FsAndroidInfo.cc \
					../../../../src/common/FsGlobal.cc \
					../../../../src/common/FsScriptEngine.cc \
					../../../../src/core/FsObject.cc \
					../../../../src/entity/FsColorQuad2D.cc \
					../../../../src/entity/FsEntity.cc \
					../../../../src/entity/FsLabelTTF.cc \
					../../../../src/entity/FsQuad2D.cc \
					../../../../src/entity/FsSprite2DData.cc \
					../../../../src/entity/FsSprite2D.cc \
					../../../../src/event/FsSysDispatcher.cc \
					../../../../src/event/FsSysEventListener.cc \
					../../../../src/event/FsTouchDispatcher.cc \
					../../../../src/event/FsTouchEventListener.cc \
					../../../../src/graphics/FsColor.cc \
					../../../../src/graphics/FsFontTTF.cc \
					../../../../src/graphics/FsImage2D.cc \
					../../../../src/graphics/FsProgram.cc \
					../../../../src/graphics/FsRender.cc \
					../../../../src/graphics/FsTexture2D.cc \
					../../../../src/io/FsFile.cc \
					../../../../src/io/FsSysFile.cc \
					../../../../src/io/FsVFS.cc \
					../../../../src/io/FsPackage.cc \
					../../../../src/io/FsZipPackage.cc \
					../../../../src/io/FsMemFile.cc \
					../../../../src/material/FsColorQuad2DMaterial.cc \
					../../../../src/material/FsMaterial.cc \
					../../../../src/material/FsPositionTextureMaterial.cc \
					../../../../src/material/FsShaderMaterial.cc \
					../../../../src/material/FsPositionAlphaTextureMaterial.cc \
					../../../../src/math/FsMathUtil.cc \
					../../../../src/math/FsMatrix4.cc \
					../../../../src/math/FsRect2D.cc \
					../../../../src/mgr/FsFontTTFDataMgr.cc \
					../../../../src/mgr/FsResource.cc \
					../../../../src/mgr/FsResourceMgr.cc \
					../../../../src/mgr/FsTextureMgr.cc \
					../../../../src/mgr/FsSprite2DDataMgr.cc \
					../../../../src/scene/FsColorLayer.cc \
					../../../../src/scene/FsDirector.cc \
					../../../../src/scene/FsLayer.cc \
					../../../../src/scene/FsLayer2D.cc \
					../../../../src/scene/FsScene.cc \
					../../../../src/scheduler/FsScheduler.cc \
					../../../../src/scheduler/FsSchedulerTarget.cc \
					../../../../src/support/data/FsBase64.cc \
					../../../../src/support/data/FsDeflate.cc \
					../../../../src/support/data/FsHash.cc \
					../../../../src/support/data/FsIconv.cc \
					../../../../src/support/felis/sl_comment.cc \
					../../../../src/support/felis/sl_double_quote_str.cc \
					../../../../src/support/felis/sl_simple_str.cc \
					../../../../src/support/felis/sl_single_quote_str.cc \
					../../../../src/support/felis/sl_specific_symbol.cc \
					../../../../src/support/felis/sl_top.cc \
					../../../../src/support/felis/sl_white_space.cc \
					../../../../src/support/felis/xir_file.cc \
					../../../../src/support/felis/xir_grammer.cc \
					../../../../src/support/felis/xir_parser.cc \
					../../../../src/support/felis/xir_scanner.cc \
					../../../../src/support/felis/xir_token.cc \
					../../../../src/support/image/FsImageDecoder.cc \
					../../../../src/support/image/FsImageFaw.cc  \
					../../../../src/support/image/FsImageJpeg.cc \
					../../../../src/support/image/FsImagePng.cc \
					../../../../src/sys/FsSys.cc \
					../../../../src/sys/FsTimer.cc \
					../../../../src/sys/FsWindow.cc \
					../../../../src/sys/platform/FsAndroidInfo.cc \
					../../../../src/util/FsArray.cc \
					../../../../src/util/FsDict.cc \
					../../../../src/util/FsLog.cc \
					../../../../src/util/FsPathUtil.cc \
					../../../../src/util/FsScriptUtil.cc \
					../../../../src/util/FsSlowArray.cc \
					../../../../src/util/FsString.cc \

LOCAL_C_INCLUDES := ../src  \
					../../../src/ \
					../../../src/support \
					../../../platform/thirdparty/android/freetype \
					../../../platform/thirdparty/android \



include $(BUILD_STATIC_LIBRARY)



