#ifndef CC_H_DEBUG_PRINT_
#define CC_H_DEBUG_PRINT_

#ifndef _cplusplus

#include <stdio.h>
#ifdef CC_PRINT_WARNING
#define cc_print_warning(x) printf((x))
#define cc_print_warning_endl() printf("\n")
#else
#define cc_print_warning(x)
#define cc_print_warning_endl()
#endif
#ifdef CC_PRINT_ERROR
#define cc_print_error(x) printf((x))
#define cc_print_error_endl() printf("\n")
#else
#define cc_print_error(x) printf((x))
#define cc_print_error_endl()
#endif
#ifdef CC_PRINT_TEST
#define cc_print_test(x) printf((x))
#define cc_print_test_endl() printf("\n")
#else
#define cc_print_test(x) printf((x))
#define cc_print_test_endl()
#endif


#else

#include <iostream>
#ifdef CC_PRINT_WARNING
#define cc_print_warning(x) std::cout<<(x)
#define cc_print_warning_endl() std::cout<<std::endl
#else
#define cc_print_warning(x) 
#define cc_print_warning_endl() 
#endif 

#ifdef CC_PRINT_ERROR
#define cc_print_error(x) std::cout<<(x)
#define cc_print_error_endl() std::cout<<std::endl
#else
#define cc_print_error(x) 
#define cc_print_error_endl()
#endif 


#ifdef CC_PRINT_TEST
#define cc_print_test(x) std::cout<<(x)
#define cc_print_test_endl() std::cout<<std::endl;
#else
#define cc_print_test(x) 
#define cc_print_test_endl()
#endif
 
#endif


#endif
