#ifndef CC_BASETYPE_H
#define CC_BASETYPE_H




#if (defined(__unix__) || defined(__APPLE__))
#include <sys/types.h>
typedef __int8_t cc_int8;
typedef __uint8_t cc_uint8;
typedef __int32_t cc_int32;
typedef __uint32_t cc_uint32;
typedef __int64_t cc_int64;
typedef __uint64_t cc_uint64;
#elif defined(_WIN32_)
#include <BaseTsd.h>
typedef INT8 cc_int8
typedef UINT8 cc_uint8
typedef INT32 cc_int32
typedef UINT32 cc_uint32
typedef INT64 cc_int64
typedef UINT64 cc_uint64
#endif




#endif
















