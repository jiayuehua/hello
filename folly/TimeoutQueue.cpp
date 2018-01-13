#include <folly/TimeoutQueue.h>
#include <chrono>
#include <thread>
#include <iostream>

void callback(int64_t x, int64_t y) {
  std::cout << x << "," << y << "\n";
}
void timeoutQueue()
{
  using namespace std::chrono_literals;
  std::chrono::steady_clock c;
  folly::TimeoutQueue tq;
  auto d = c.now().time_since_epoch().count();
  std::cout<<d<<std::endl;
  tq.add(d,1000, &callback);
  tq.add(d,1000, &callback);
  tq.add(d,1000, &callback);
  tq.addRepeating(d,1'000'000'000,&callback);
  std::this_thread::sleep_for(1s);
  d = c.now().time_since_epoch().count();
  std::cout<<d<<std::endl;
  int n = 0;
  while (n<5)
  {
    std::this_thread::sleep_for(2s);
    tq.runLoop(c.now().time_since_epoch().count());
    ++n;
  }
}
int  main()
{
  timeoutQueue();
}