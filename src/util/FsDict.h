#ifndef _FS_UTIL_DICT_H_
#define _FS_UTIL_DICT_H_

#include "FsMacros.h"
#include "core/FsObject.h"

FAERIS_NAMESPACE_BEGIN
class  FsDict:public FsObject
{
	public:
		class Iterator
		{
			FS_FEATURE:
				FS_MAKE_NO_COPYABLE(Iterator);
			public:
				Iterator(FsDict* dict)
				{
					m_dict=dict;
					dict->addRef();
					m_curPos=-1;
					findNext();
				}
				~Iterator()
				{
					m_dict->decRef();
				}
			public:
				FsObject* getKey()
				{
					FsObject* ret= m_dict->m_table[m_curPos].m_key;
					ret->addRef();
					return ret;
				}
				FsObject* getValue()
				{
					FsObject* ret=m_dict->m_table[m_curPos].m_value;
					ret->addRef();
					return ret;
				}
				bool done()
				{
					return m_curPos>(FsLong)m_dict->m_mask;
				}
				bool next()
				{
					if(m_curPos>(FsLong)m_dict->m_mask)
					{
						return false;
					}
					return findNext();
				}
			protected:
				bool findNext()
				{
					if(m_curPos>(FsLong)m_dict->m_mask)
					{
						return false;
					}
					while(++m_curPos<(FsLong)((m_dict->m_mask+1)))
					{
						if(m_dict->validEntry(m_dict->m_table+m_curPos))
						{
							return true;
						}
					}
					return false ;
				}
			private:
				FsDict* m_dict;
				FsLong m_curPos;
				FsLong m_iterNu;
		};
		class DictEntry
		{
			public:
				FsLong m_code;
				FsObject* m_key;
				FsObject* m_value;
			public:
		};

	public:
		FsDict();
		~FsDict();
		virtual const FsChar* getName();
		static bool checkType(FsObject* ob);
	public:
		FsObject* lookup(FsObject* key);
		FsObject* lookup(const FsChar* key);
		bool insert(FsObject* key,FsObject* value);
		bool insertWithNewKey(FsObject* key,FsObject* value);
		bool remove(FsObject* key);
		Iterator* getIterator();
		FsUlong size(){return m_used;}
	protected:
		DictEntry* getEntry(FsObject* key);
		DictEntry* lookupEntry(FsObject* key,FsLong code);
		void resize(FsLong minisize);
		void simpleInsert(FsObject* key,FsLong hcode,FsObject* value);
		bool validEntry(DictEntry* entry);
	private:
		FsLong m_fill;  /* slot already filled include dummy */
		FsLong m_used;  /* real key num */
		FsUlong m_mask;
		DictEntry* m_table;
};
FAERIS_NAMESPACE_END 

#endif /*_FS_UTIL_DICT_H_*/

