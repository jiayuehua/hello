#include <folly/ClockGettimeWrappers.h>
#include <iostream>
#include <chrono>
void gettime()
{
  timespec t;
  int r = folly::chrono::clock_gettime(CLOCK_REALTIME, &t);
  auto ns = folly::chrono::clock_gettime_ns(CLOCK_REALTIME);
  std::cout<<ns<<std::endl;

  std::cout<<r<<std::endl;
  std::cout<<t.tv_sec<<" "<<t.tv_nsec<<std::endl;
  std::cout<<t.tv_sec*1000000000+t.tv_nsec<<std::endl;
  auto a = std::chrono::system_clock::now().time_since_epoch();
  auto  n = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());
  std::cout<< n.count()<<std::endl;
  std::cout<<a.count()<<std::endl;
  std::cout<<(a.count()-n.count()*1000000000)<<std::endl;



}
int main()
{
  gettime();
}