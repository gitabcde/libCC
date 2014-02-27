#include <iostream>
#include <fstream>
#include "../../libCC/cc_basetype.h"
#define BUFFERSIZE 4096
#define CC_COLOR_OFF "\033[0m" 
#define CC_COLOR_BLACK "\033[30m"
#define CC_COLOR_RED "\033[31m"
#define CC_COLOR_GREEN "\033[32m"
#define CC_COLOR_BROWN "\033[33m"
#define CC_COLOR_BLUE "\033[34m"
#define CC_COLOR_MANENTA "\033[35m"
#define CC_COLOR_CYAN "\033[36m"
#define CC_COLOR_WHITE "\033[37m"
#define CC_COLOR_BLACK_WHITE "\033[47;30m"
#define CC_COLOR_RED_CYAN "\033[46;31m"
#define CC_COLOR_GREEN_MANENTA "\033[45;32m"
#define CC_COLOR_BROWN_BLUE "\033[44;33m"
#define CC_COLOR_BLUE_BROWN "\033[43;34m"
#define CC_COLOR_MANENTA_GREEN "\033[42;35m"
#define CC_COLOR_CYAN_RED "\033[436m"


int main()
{
  bool diff_found=false;
  bool cc_eof=false;
  std::string file1,file2;
  std::cout<<CC_COLOR_BROWN_BLUE<<"input file1's filename:"<<CC_COLOR_OFF;
  std::cout<<CC_COLOR_WHITE;
  std::cin>>file1;
  std::cout<<CC_COLOR_BROWN_BLUE<<"input file2's filename:"<<CC_COLOR_OFF;
  std::cout<<CC_COLOR_WHITE;
  std::cin>>file2;
  std::cout<<CC_COLOR_OFF<<std::endl;;
  std::fstream fs1(file1.c_str(),std::fstream::in|std::fstream::binary);
  std::fstream fs2(file2.c_str(),std::fstream::in|std::fstream::binary);
  char buffer1[BUFFERSIZE],buffer2[BUFFERSIZE];
  int count=0;
  int pos_diff=0;
  int begin_pos1=0,begin_pos2=0;
  while(1)
    {
      if(cc_eof)
	{
	  if(!diff_found)
	    std::cout<<CC_COLOR_RED<<"the two files are exactly same"<<CC_COLOR_OFF<<std::endl;
	  else
	    std::cout<<CC_COLOR_RED<<"GOT THE FILE END"<<CC_COLOR_OFF<<std::endl;
	  return -1;
	}
      char c;
      std::cout<<CC_COLOR_RED<<"continue to compare at the previous postion for both file?(y/n)"<<CC_COLOR_OFF;
      std::cin>>c;
      if(c=='y')
	{
	  begin_pos1+=pos_diff+1;
	  begin_pos2+=pos_diff+1;
	}
      else
	{
	  std::cout<<CC_COLOR_BROWN_BLUE<<"input the begin_pos to compare,only dec number is supported"<<CC_COLOR_OFF<<std::endl;
	  std::cout<<CC_COLOR_BROWN_BLUE<<"begin_pos of "<<file1<<":"<<CC_COLOR_OFF;
	  std::cout<<CC_COLOR_GREEN;
	  std::cin>>begin_pos1;
	  std::cout<<CC_COLOR_BROWN_BLUE<<"begin_pos of "<<file2<<":"<<CC_COLOR_OFF;
	  std::cout<<CC_COLOR_WHITE;
	  std::cin>>begin_pos2;
	  std::cout<<CC_COLOR_OFF;
	}
      fs1.seekg(begin_pos1);
      fs2.seekg(begin_pos2);
      while(!(cc_eof=(fs1.eof() || fs2.eof())))
	{
	  fs1.read(buffer1,BUFFERSIZE);
	  fs2.read(buffer2,BUFFERSIZE);
	  for(int n=0;n<BUFFERSIZE/sizeof(cc_uint64);n++)
	    {
	      if(*(((cc_uint64*)buffer1)+n)!=(*(((cc_uint64*)buffer2)+n)))
		{
		  int i;
		  for(i=0;i<sizeof(cc_uint64);i++)
		    {
		      if(*(((char*)buffer1)+i+n*sizeof(cc_uint64))!=(*(((char*)buffer2)+i+n*sizeof(cc_uint64))))
			{
			  std::cout<<CC_COLOR_RED<<"<<<<"<<file1<<"<<<<"<<std::endl<<(int)*(((char*)buffer1)+i+n*sizeof(cc_uint64))<<CC_COLOR_OFF<<std::endl;
			  std::cout<<CC_COLOR_RED<<">>>>"<<file2<<">>>>"<<std::endl<<(int)*(((char*)buffer2)+i+n*sizeof(cc_uint64))<<CC_COLOR_OFF<<std::endl;
			  break;
			}
		    }
		  pos_diff=BUFFERSIZE*count+n*sizeof(cc_uint64)+i;
		  std::cout<<CC_COLOR_RED<<"diff at "<<std::hex<<CC_COLOR_GREEN<<pos_diff+begin_pos1<<CC_COLOR_RED<<" in "<<CC_COLOR_WHITE<<file1<<CC_COLOR_RED<<" , "<<CC_COLOR_GREEN<<pos_diff+begin_pos2<<CC_COLOR_RED<<" in "<<CC_COLOR_WHITE<<file2<<CC_COLOR_RED<<" in hex, "<<std::dec<<CC_COLOR_GREEN<<pos_diff+begin_pos1<<CC_COLOR_RED<<" in "<<CC_COLOR_WHITE<<file1<<CC_COLOR_RED<<" , "<<CC_COLOR_GREEN<<pos_diff+begin_pos2<<CC_COLOR_RED<<" in "<<CC_COLOR_WHITE<<file2<<CC_COLOR_RED<<" in dec."<<std::endl;
		  diff_found=true;
		  break;
		}
	    }
	  if(diff_found)
	    break;
	  count++;
	}
    }
  return -1;
}
