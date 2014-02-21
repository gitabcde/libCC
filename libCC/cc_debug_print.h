#ifndef CC_H_DEBUG_PRINT_
#define CC_H_DEBUG_PRINT_

#ifndef _cplusplus

#include <stdio.h>
#ifdef CC_PRINT_WARNING
#define cc_print_warning(x) printf((x))
#else
#define cc_print_warning(x)
#endif
#ifdef CC_PRINT_ERROR
#define cc_print_error(x) printf((x))
#else
#define cc_print_error(x) printf((x))
#endif
#ifdef CC_PRINT_TEST
#define cc_print_test(x) printf((x))
#else
#define cc_print_test(x) printf((x))
#endif

#else

#include <iostream>
#ifdef CC_PRINT_WARNING
#define cc_print_warning(x) std::cout<<(x)
#else
#define cc_print_warning(x) 
#endif 

#ifdef CC_PRINT_ERROR
#define cc_print_error(x) std::cout<<(x)
#else
#define cc_print_error(x) 
#endif 


#ifdef CC_PRINT_TEST
#define cc_print_test(x) std::cout<<(x)
#else
#define cc_print_test(x) 
#endif
 
#endif


#endif
