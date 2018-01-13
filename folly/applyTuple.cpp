#include <folly/functional/ApplyTuple.h>
#include <tuple>
#include <iostream>
void f(int i,int j, const char *c)
{
  std::cout<<i<<std::endl;
  std::cout<<j<<std::endl;
  std::cout<<c<<std::endl;
}
int main()
{
  auto t = std::make_tuple(1,2,"hello");
  folly::applyTuple(&f,t);
}