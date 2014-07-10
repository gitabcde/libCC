#include "../libCC/CHttpReader.h"
#include <curl/curl.h>
#include <fstream>

struct USERDATA
{
  void* handle;
  double* value;
};
CHttpReader::CHttpReader()
{
  m_total=0;
  m_downloaded=0;
}

CHttpReader::~CHttpReader()
{
  
}

int CHttpReader::DownLoadToFile(std::string url,std::string filepath)
{
  CURL* pcurl=curl_easy_init();
  CURLcode ret; 
  curl_easy_setopt(pcurl,CURLOPT_URL,url.c_str());
  curl_easy_setopt(pcurl,CURLOPT_NOBODY,1);
  curl_easy_setopt(pcurl,CURLOPT_HEADER,1);
  ret=curl_easy_perform(pcurl);
  if(ret==CURLE_OK)
    curl_easy_getinfo(pcurl,CURLINFO_CONTENT_LENGTH_DOWNLOAD,&m_total);
  else
    return -1;
  std::fstream fs(filepath.c_str(),std::fstream::out|std::fstream::app|std::fstream::binary);
  USERDATA ud;
  ud.handle=&fs;
  ud.value=&m_downloaded;
  curl_easy_setopt(pcurl,CURLOPT_NOBODY,0);
  curl_easy_setopt(pcurl,CURLOPT_HEADER,0);
  curl_easy_setopt(pcurl,CURLOPT_WRITEDATA,&ud);
  curl_easy_setopt(pcurl,CURLOPT_WRITEFUNCTION,WriteToFile);
  ret=curl_easy_perform(pcurl);
  fs.close();
  curl_easy_cleanup(pcurl);
  if(ret==CURLE_OK)
    return 0;
  else
    return -1;

}
int CHttpReader::DownLoadToString(std::string url,std::string& str)
{
  CURL* pcurl=curl_easy_init();
  CURLcode ret; 
  curl_easy_setopt(pcurl,CURLOPT_URL,url.c_str());
  curl_easy_setopt(pcurl,CURLOPT_NOBODY,1);
  curl_easy_setopt(pcurl,CURLOPT_HEADER,1);
  ret=curl_easy_perform(pcurl);
  if(ret==CURLE_OK)
    curl_easy_getinfo(pcurl,CURLINFO_CONTENT_LENGTH_DOWNLOAD,&m_total);
  else
    return -1;
  USERDATA ud;
  ud.handle=&str;
  ud.value=&m_downloaded;
  curl_easy_setopt(pcurl,CURLOPT_NOBODY,0);
  curl_easy_setopt(pcurl,CURLOPT_HEADER,0);
  curl_easy_setopt(pcurl,CURLOPT_WRITEDATA,&ud);
  curl_easy_setopt(pcurl,CURLOPT_WRITEFUNCTION,WriteToString);
  ret=curl_easy_perform(pcurl);
  curl_easy_cleanup(pcurl);
  if(ret==CURLE_OK)
    return 0;
  else
    return -1;

}



double CHttpReader::GetTotal()
{
  return m_total;
}


double CHttpReader::GetDownloaded()
{
  return m_downloaded;
}


int CHttpReader::WriteToString(void* buff,int size,int count,void* userdata)
{
  USERDATA* ud=(USERDATA*)userdata;
  std::string* str=(std::string*)ud->handle;
  str->append((char*)buff,size*count);
  *ud->value+=size*count;
  return size*count;
}

int CHttpReader::WriteToFile(void* buff,int size,int count,void* userdata)
{
  USERDATA* ud=(USERDATA*)userdata;
  std::fstream* fs=(std::fstream*)ud->handle;
  fs->write((char*)buff,size*count);
  *ud->value+=size*count;
  return size*count;
}
