

#ifndef _FS_UPDATE_APK_
#define _FS_UPDATE_APK_

#include "FsMacros.h"
#include "FsObject.h"

#include "FsxAccessModule.h"



NS_FS_BEGIN



class UpdateApk:public FsObject
{

	public:
		static UpdateApk* create(void);

		virtual const char* className()
		{
			return FS_ACCESS_UPDATEAPK_CLASS_NAME;
		}

	public:
		virtual void onResult(int code);	

	public:
		void checkUpdate();

	protected:
		UpdateApk();
		~UpdateApk();

};

NS_FS_END





















#endif