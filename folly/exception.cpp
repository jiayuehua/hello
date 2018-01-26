#include <folly/Exception.h>
#include <exception>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <fcntl.h>
void except()
{
  int fd = open("/usr/local/bin/h.txt", O_RDWR);


  try
  {
    folly::checkUnixError(fd, "open " ,2018 );

  }
  catch (const std::exception& e)
  {
    std::cout <<e.what()<<std::endl;
  }
  FILE* fp = fopen("","r");
  try
  {
    folly::checkFopenError(fp, "fopen" ,2018 );

  }
  catch (const std::exception& e)
  {
    std::cout <<e.what()<<std::endl;
  }


}
int main()
{
  except();
}