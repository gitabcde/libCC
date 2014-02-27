#include <iostream>
#include <fstream>
#include "../../libCC/cc_terminal.h"
#define BUFFER_SIZE 4096
void showhelp()
{
  std::cout<<CC_COLOR_GREEN<<"AppFile help"<<std::endl;
  std::cout<<"AppFile in_fil1,in_fil2.... out_file"<<CC_COLOR_OFF<<std::endl;
  
}


int main(int argc,char** argv)
{
  std::string *param=new std::string[argc];
  for(int n=0;n<argc;n++)
    {
      param[n]=argv[n];
    }
  switch(argc)
    {
    case 1:
      showhelp();
      return 0;
    case 2:
      if(param[1]=="--help")
	showhelp();
      else
	std::cout<<CC_COLOR_RED<<"incorrect parameter count"<<CC_COLOR_OFF<<std::endl;
      return 0;
    default:
      {
	std::fstream in_file;
	std::fstream out_file;
	std::size_t length;
	char buffer[BUFFER_SIZE];
	out_file.open(param[argc-1].c_str(),std::fstream::app|std::fstream::out|std::fstream::binary);
	for(int n=1;n<argc-1;n++)
	  {
	    in_file.open(param[n].c_str(),std::fstream::in|std::fstream::binary);
	    if(in_file.fail())
	      {
		std::cout<<CC_COLOR_RED<<"the "<<n<<"'st file:"<<param[n]<< "doesn't exise"<<CC_COLOR_OFF<<std::endl;
		in_file.close();
		continue;
	      }
	    in_file.seekg(0,std::fstream::end);
	    length=in_file.tellg();
	    std::cout<<"length is "<<length<<std::endl;
	    in_file.seekg(0,std::fstream::beg);
	    for(int n=0;n<length/BUFFER_SIZE;n++)
	      {
		in_file.read(buffer,BUFFER_SIZE);
		out_file.write(buffer,BUFFER_SIZE);
	      }
	    in_file.read(buffer,length % BUFFER_SIZE);
	    out_file.write(buffer,length % BUFFER_SIZE);
	    std::cout<<CC_COLOR_BLUE<<param[n]<<" writed to "<<param[argc-1]<<CC_COLOR_OFF<<std::endl;
	    in_file.close();
	  }
	out_file.close();
      }
    }
  return 0;
}
