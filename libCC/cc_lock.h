#ifndef CC_LOCK_H_
#define CC_LOCK_H_

#ifdef _WIN32_
typedef CRITICAL_SECTION cc_critical
#include <windows.h>
#include <process.h>
#define CC_CreateCritical(a) InitializeCriticalSection(a)
#define CC_EnterCritical(a) EnterCriticalSection(a)
#define CC_LeaveCritical(a) LeaveCriticalSection(a)
#define CC_DeleteCritical(a) DeleteCriticalSection(a) 
#elif (defined(__unix__) || defined(__APPLE__))
typedef pthread_mutex_t cc_critical
#include <pthread.h>
#define CC_CreateCritical(a) pthread_mutex_init(a,NULL)
#define CC_EnterCritical(a) pthread_mutex_lock(a)
#define CC_LeaveCritical(a) pthread_mutex_unlock(a)
#define CC_DeleteCritical(a) pthread_mutex_destroy(a)
#endif


#endif
