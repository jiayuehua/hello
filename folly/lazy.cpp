#include <folly/Lazy.h>
#include <unistd.h>
#include <iostream>
struct A {
  A() noexcept{
  }
  void print()const noexcept
  {
    std::cout<<"print\n";
  }
};
void lazy()
{
  auto v = folly::lazy([]{sleep(5);return A();});
  std::cout<<"first"<<std::endl;
  v().print();
  v().print();
  v().print();
}

int main()
{
  lazy();
}