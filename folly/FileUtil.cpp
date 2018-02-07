#include <iostream>
#include <string>
#include <folly/FileUtil.h>
void fileUtil()
{
  using namespace folly;
  auto fdn = openNoInt("hello.txt",O_RDWR);
  if (fdn!= -1)
  {
    int fd = 10;
    auto r = dup2NoInt(fdn, fd);
    if (r != -1)
    {
      closeNoInt(fdn);
      char a[32];
      auto r = readNoInt(fd, a, sizeof a);
      if (r!= -1)
      {
        for (int i = 0 ; i< sizeof a; ++i)
        {
          std::cout<<a[i];
        }
        std::cout<<std::endl;
      }
      char bufA[32], bufB[32], bufC[32];
      iovec iov[3];
      iov[0].iov_len = sizeof(bufA);
      iov[1].iov_len = sizeof(bufB);
      iov[2].iov_len = sizeof(bufC);
      iov[0].iov_base = bufA;
      iov[1].iov_base = bufB;
      iov[2].iov_base = bufC;
      readvNoInt(fd, iov, 3);
      for (int i = 0 ; i<3; ++i)
      {
        char * p = (char*) iov[i].iov_base;
        for (int j =0; j<iov[i].iov_len; ++j)
        {
          std::cout<<p[j];
        }
      }
      char bufF[24];
      std::cout<<"\n";
      ssize_t rF =  readFull(fd, bufF, sizeof bufF);
      std::cout<<"rF"<<rF<<std::endl;
      auto fd_n = openNoInt("hello_n.txt",O_RDWR);
      rF = writeFull(STDOUT_FILENO,bufF, rF);
      rF = pwriteFull(fd_n,bufF, rF, 10);
      std::cout<<"rF"<<rF<<std::endl;
      closeNoInt(fd_n);

      std::string fileContent;
      auto readR = readFile("world.txt", fileContent);
      auto writeR = writeFile(fileContent, "worldsecond.txt");
      std::string s;
      for (int i = 0; i<128; ++i)
      {
        s+= "hello, world ";
      }
      writeFileAtomic("atomic.txt", s);
    }
  }
}
int main()
{
  fileUtil();
}