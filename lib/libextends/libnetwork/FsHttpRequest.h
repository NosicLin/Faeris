#ifndef _FS_HTTP_REQUEST_H_
#define _FS_HTTP_REQUEST_H_
#include "FsMacros.h"
#include "core/FsObject.h"

NS_FS_BEGIN
class  HttpRequest:public FsObject  
{
	public:
		static HttpRequest* create(HttpRequestData* data);

	public:
		virtual void onReponse(HttpReponse* data);

	protected:
		HttpRequestData* m_data;
};

NS_FS_END

#endif /*_FS_HTTP_REQUEST_H_*/

