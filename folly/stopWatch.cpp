#include <iostream>
#include <folly/stop_watch.h>
#include <memory>
#include <functional>
#include <utility>
#include <chrono>
#include <thread>

void stopWatch()
{
  using namespace std::chrono_literals;
  folly::stop_watch<std::chrono::seconds> s;

  for (int n = 0;n<5;)
  {
    if (s.lap(1s))
    {
      ++n;
      std::cout<<"1 second pass by!\n";
    }
  }
  std::this_thread::sleep_for(5s);
  std::cout<<s.elapsed().count()<<std::endl;
}
int main()
{
  stopWatch();
}