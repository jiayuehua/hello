#include <iostream>
#include <folly/ThreadLocal.h>
#include <thread>
struct Tag{};
folly::ThreadLocal<int,Tag> tl ;
void threadLocal()
{
  *tl = 5;
  sleep(5);
  std::cout<<"threadLocal\n";
  std::cout<<*tl<<std::endl;
}
void threadLocal2()
{

  *tl = 8;
  sleep(5);
  std::cout<<"threadLocal2\n";
  std::cout<<*tl<<std::endl;
}
int main()
{
  std::thread t(&threadLocal);
  std::thread ta(&threadLocal2);
  sleep(2);
  {
    auto a = tl.accessAllThreads();
    for (auto i : a)
    {
      std::cout<<i;
    }
  }

  t.join();
  ta.join();
}