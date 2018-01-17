#include <folly/Demangle.h>
#include <folly/Random.h>
#include <vector>
#include <exception>
#include <iostream>
#include <string>
#include <typeinfo>
class B{};
class D:public B{};
void demangle()
{
  D d;
  B *b = &d;
  std::cout<<typeid(b).name()<<std::endl;

  std::cout<<folly::demangle(typeid(b))<<std::endl;
  std::cout<<folly::demangle(typeid(*b))<<std::endl;
  std::cout<<folly::demangle(typeid(std::vector<int>))<<std::endl;
  std::cout<<folly::demangle(typeid(int))<<std::endl;
  std::cout<<folly::demangle(typeid(std::vector<std::string>()))<<std::endl;
  std::cout<<folly::demangle(typeid(std::runtime_error("g")))<<std::endl;
}
int main()
{
  demangle();

}