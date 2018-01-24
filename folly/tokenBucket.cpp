#include <folly/TokenBucket.h>
#include <iostream>
#include <functional>
#include <utility>

void token()
{

std::move(3);
  auto t = folly::TokenBucket::defaultClockNow();
  folly::ParameterizedTokenBucket<> p(10,100, t);
  sleep(2);
  std::cout<<p.available()<<std::endl;

  std::cout<<p.consumeOrDrain(40)<<std::endl;
  std::cout<<p.available()<<std::endl;
  sleep(5);
  std::cout<<p.consumeOrDrain(40)<<std::endl;
  std::cout<<p.available()<<std::endl;
  sleep(4);
  std::cout<<p.consumeOrDrain(50)<<std::endl;
  std::cout<<p.available()<<std::endl;
}
int main()
{
  token();
}




