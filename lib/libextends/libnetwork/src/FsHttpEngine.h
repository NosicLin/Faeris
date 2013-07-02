#ifndef _FS_HTTP_ENGING_H_
#define _FS_HTTP_ENGING_H_ 
#include "FsMacros.h"
#include "core/FsObject.h"
#include "sys/FsThread.h"
#include "sys/FsMutex.h"
#include "sys/FsSemaphore.h"
#include "util/FsArray.h"

NS_FS_BEGIN
class HttpRequest;
class HttpReponse;

HttpReponse* FsHttp_HandlePost(HttpRequest* request,int max_connect_time,int max_read_time);
HttpReponse* FsHttp_HandleGet(HttpRequest* request,int max_connect_time,int max_read_time);



class HttpEngine:public Thread, public FsObject 
{
	public:
		static HttpEngine* create();


	public:
		void send(HttpRequest* request);
		void clear();
		void stop();

	public:
		virtual void run();

	public:
		virtual const char* className();


	protected:
		HttpEngine();
		virtual ~HttpEngine();
		bool init();
		void destroy();


	private:
		FsArray* m_requests;
		Semaphore* m_reqSem;
		Mutex* m_reqMutex;

		int m_stop;
		int m_maxConnectTime;
		int m_maxReadTime;
};

NS_FS_END 

#endif /* _FS_HTTP_ENGING_H_ */

