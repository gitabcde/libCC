#include <math.h>
#include <iostream>
#include <sys/time.h>
#include "../../libCC/cc_basetype.h"
#include "../../libCC/cc_terminal.h"
int main()
{
  timeval tv;
  struct timezone tz;
  gettimeofday(&tv,&tz);
  cc_uint64 init_val=tv.tv_sec+tv.tv_usec;
  srand(init_val);
  std::cout<<"input the number's count:";
  int num_count;
  std::cin>>num_count;
  std::cout<<"intput the max normal number:";
  int n_num_max;
  std::cin>>n_num_max;
  int s_num_max;
  std::cout<<"input the max special number:";
  std::cin>>s_num_max;
  for(int n=0;n<num_count;n++)
    {
      int result;
      
      if(n==num_count-1)
	{
	  result=rand()%s_num_max;
	  if(result==0)
	    {
	      srand(result);
	      result=rand()%s_num_max;
	    }
	  std::cout<<CC_COLOR_BLUE<<result<<CC_COLOR_OFF<<std::endl;
	  
	}
      else
	{
	  result=rand()%n_num_max;
	  if(result==0)
	    {
	      srand(result);
	      result=rand()%n_num_max;
	    }
	  std::cout<<CC_COLOR_RED<<result<<CC_COLOR_OFF<<" ";
	}
    }
  return 0;
}
