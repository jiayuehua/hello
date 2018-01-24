#include <folly/MicroLock.h>
#include <thread>
#include <iostream>
#include <cmath>
  folly::MicroLock l;
void foo(int & k)
{

  l.lock();
  for (int i = 1; i<5000; ++i)
  {
    //std::cout<<i<<" "<<sqrt(i)<<std::endl;
    ++k;
    //sleep(i);

  }
  l.unlock();
}

int main()
{
  int i = 0;
  l.init();
  std::thread t(foo, std::ref(i));
  std::thread t2(foo, std::ref(i));
  t.join();
  t2.join();
  std::cout<<i<<std::endl;

}