#ifndef _FS_HTTP_ENGING_H_
#define _FS_HTTP_ENGING_H_ 
#include "FsMacros.h"
#include "sys/FsThread.h"
#include "sys/FsMutex.h"
#include "sys/FsSemaphore.h"

NS_FS_BEGIN

class HttpEngine:public Thread 
{
	public:
		static HttpEngine* create();


	public:
		void send(HttpRequest* request);
		void clear();
		void stop();
	public:
		virtual void run();


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
};

NS_FS_END 

#endif /* _FS_HTTP_ENGING_H_ */
