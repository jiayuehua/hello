#include <folly/ThreadCachedInt.h>
#include <iostream>
#include <folly/ScopeGuard.h>
folly::ThreadCachedInt<int> n;
void fa() {
  n+=5;
  n+=5;
  sleep(2);
}
int main()
{
  {

  std::thread ta(&fa);
  std::thread tb(&fa);
  std::thread tc(&fa);
  auto g = folly::makeGuard([&]{
    ta.join();
    tb.join();
    tc.join();
                            });
  std::cout<<n.readFull()<<std::endl;
  sleep(1);
  std::cout<<n.readFull()<<std::endl;
  sleep(5);
  std::cout<<n.readFull()<<std::endl;
  }
  std::cout<<n.readFull()<<std::endl;

}

