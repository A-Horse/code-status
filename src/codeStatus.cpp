// #include "rapidjson/include/rapidjson/document.h"
// #include "rapidjson/include/rapidjson/writer.h"
// #include "rapidjson/include/rapidjson/stringbuffer.h"
#include <cstdlib>
#include <iostream>
#include <sys/stat.h>
#include <string>
#include <map>


using namespace std;



std::map<std::string, std::string> lanuage;



const string ignoreSuffix[]  = {"javac", "out", "pyc"};

string whichLanguage(string suffix) {
  cout << lanuage[suffix];
  return "other";
};

// using namespace rapidjson;

void statisticsFile(char* path)
{
  std::string pathstr = path;
  std::cout << pathstr << std::endl;
  int dotPosition = pathstr.find_last_of('.');
  
  std::string suffix = pathstr.substr(dotPosition + 1);
  
  std::cout << suffix << std::endl;

  string lanuage = whichLanguage(suffix);
}

int main(int argc, char* argv[])
{
  // Check the number of parameters
  lanuage["java"] = "java";
  //lanuage["cpp"] = "c++";
  
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " PATH" << std::endl;
    return 1;
  }
  
  
  struct stat st;
  stat(argv[1], &st);     //返回33206  文件
  std::cout << S_ISDIR(st.st_mode) << std::endl;

  // TODO not exist
  if (S_ISDIR(st.st_mode)) {
    
  } else {
    statisticsFile(argv[1]);
  }
  
  
  std::cout << "says hello, " << argv[1] << "!" << std::endl;
  
  return 0;
  
}


