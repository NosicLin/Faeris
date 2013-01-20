#ifndef _FS_LIST_H_
#define _FS_LIST_H_

NS_FS_BEGIN

class FsListHead
{
	public:
		FsListHead* m_prev;
		FsListHead* m_next;
	public:
		FsListHead()
		{
			prev=this;
			next=this;
		}

	public:
		FsBool empty()
		{
			return prev==next;
		}

		void insert(FsListHead* h)
		{
			insert(m_prev,this,h);
		}

		void insertFront(FsListHead* h)
		{
			insert(this,m_next,h);
		}

		void remove(FsListHead* h)
		{
			h->m_prev->m_next=h->m_next;
			h->m_next->m_prev=h->m_prev;
		}


	protected:
		void insert(FsListHead* p,FsListHead* n,FsListHead* h)
		{
			p->m_next=h;
			n->m_prev=h;
			h->m_prev=p;
			h->m_next=n;
		}

};

#define FS_LIST_FOR_EACH(head,p) \
	for(p=head.m_next;p!=head.m_prev;p=p->next)

NS_FS_END
#endif /*_FS_LIST_H_*/

