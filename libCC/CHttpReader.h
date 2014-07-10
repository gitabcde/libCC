#ifndef CHTTPREADER_H
#define CHTTPREADER_H

#include <string>

class CHttpReader
{
  public:
    CHttpReader();
    ~CHttpReader();

  public:
    enum DestType
    {
      DT_STRING,
      DT_FILE
    };
  public:
    int DownLoadToString(std::string url,std::string& str);
    int DownLoadToFile(std::string url,std::string filepath);
    double GetTotal();
    double GetDownloaded();


    static int WriteToString(void* buff,int size,int count,void* userdata);
    static int WriteToFile(void* buff,int size,int count,void* userdata);
    


  private:
    double m_total;
    double m_downloaded;
};
#endif
