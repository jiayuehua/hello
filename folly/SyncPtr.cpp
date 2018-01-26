#include <folly/PackedSyncPtr.h>
#include <vector>
#include <iostream>
#include <thread>
folly::PackedSyncPtr<int> p;
void
syncPtr()
{
  p.lock();
  for (int i = 0 ; i<5000;++i)
  {
    ++p[0];
  }
  p.unlock();
}
int main()
{
  std::vector<int > v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(5);
  p.init(v.data(), 300);
  std::thread t1(syncPtr);
  std::thread t2(syncPtr);
  t1.join();
  t2.join();
  std::cout<<p.extra()<<std::endl;
  std::cout<<v[0]<<std::endl;
}