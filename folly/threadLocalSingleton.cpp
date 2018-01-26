#include <iostream>
#include <thread>
#include <folly/SingletonThreadLocal.h>
typedef folly::SingletonThreadLocal<int> TL;
void ThreadLocal()
{
  ++TL::get();
  TL::get()+=100;
  sleep(3);
  std::cout<<TL::get();
}
int main()
{
  {

folly::SingletonThreadLocal<int>  t;
  }
  std::thread ta(ThreadLocal);
  std::thread tb(ThreadLocal);
  std::thread tc(ThreadLocal);
  ta.join();
  tb.join();
  tc.join();
}
