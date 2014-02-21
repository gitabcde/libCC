#include "../libCC/cc_debug_print.h"
#include <iostream>

int main()
{
  cc_print_error("hello");
  cc_print_error("world");
  cc_print_error_endl();
  cc_print_error("second line");
  return 0;

}
