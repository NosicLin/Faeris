
#include "com_rwhz_minder_Fs_r3rdPartyJni.h"
#include "FsGlobal.h"
#include "FsLuaEngine.h"
#include "FsMacros.h"
#include "FsxAccessModule.h"
#include "FsUpdateApk.h"

NS_FS_USE;

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_rpay_lib_Fs_rPayJni
 * Method:    onForeground
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_rwhz_minder_Fs_1r3rdPartyJni_onForeground
  (JNIEnv *, jclass){
  	

  }


/*
 * Class:     com_rpay_lib_Fs_rPayJni
 * Method:    BillingPointCB
 * Signature: (Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_com_rwhz_minder_Fs_1r3rdPartyJni_NativeBillingPointCB
  (JNIEnv * env, jclass, jstring bpid, jint ret)
  {

		const char* t_bpid=env->GetStringUTFChars(bpid,NULL);

		LuaEngine* se=(LuaEngine*)Global::scriptEngine();
		if(!se->callFunctionInName("f_BillingPointCB", "ci", t_bpid, ret))
		{
			FS_TRACE_WARN("error not find f_BillingPointCB func for lua ");
		}

		env->ReleaseStringUTFChars(bpid,t_bpid);

  }
  
  
  /*
 * Class:     com_rwhz_minder_Fs_r3rdPartyJni
 * Method:    NativeCheckUpdateCB
 * Signature: (Ljava/lang/Long;I)V
 */
 
JNIEXPORT void JNICALL Java_com_rwhz_minder_Fs_1r3rdPartyJni_NativeCheckUpdateCB
  (JNIEnv * env, jclass, jlong objADD , jint ret)
  {
  		UpdateApk* update = (UpdateApk*)objADD;
		update->onResult(ret);
  }


#ifdef __cplusplus
}
#endif