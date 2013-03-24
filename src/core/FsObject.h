#ifndef FAERIS_OBJECT_H_ 
#define FAERIS_OBJECT_H_

#include "FsMacros.h"

#define FS_INVALID_HASH_CODE (-1)

NS_FS_BEGIN

class FsObject 
{
	private:
		int m_refNu;
	public:
		int refCnt(){return m_refNu;}
		void addRef(){m_refNu++;}
		void decRef()
		{
			m_refNu--;
			FS_TRACE_ERROR_ON(m_refNu<0,"%s Reference Error",className());
			if(m_refNu<=0)
			{
				delete this;
			}
		}
		void forceDestroy(){delete this;}

	public:
		FsObject():m_refNu(1),m_data(-1){}
		virtual ~FsObject();
		virtual const char* className()=0;
		virtual long getHashCode();
		virtual bool equal(FsObject* ob); 

#if FS_CONFIG(FS_SCRIPT_SUPPORT)
	public:
		int m_data; /* script data */
#endif 
};
NS_FS_END

#endif 

