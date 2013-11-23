
#ifndef _FS_XACCESSFUNC_
#define _FS_XACCESSFUNC_



/*
*     bpid: 计费点 ， price: 计费价格.
*/

void f_BillingPointUp(const char* bpid, const char* price);

/*
*     EventID: 统计节点 ， EventLabel: 统计项 .
*/

void f_LogTalkingData(const char* eventID, const char* eventLabel);



#endif