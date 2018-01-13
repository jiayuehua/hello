#include <folly/MapUtil.h>
#include <map>
#include <string>
#include <iostream>
using namespace std::literals;
std::string  f(){return "girl"s;};
int main()
{
  std::map<int, std::string> m;
  m.insert({1,"hello"});
  m.insert({2,"world"});
  m.insert({3,"boy"});
  std::cout<<folly::get_default(m,3)<<std::endl;
  std::cout<<folly::get_default(m,4)<<std::endl;
  std::cout<<folly::get_default(m,5,&f)<<std::endl;
  auto option = folly::get_optional(m,5);
  if (option)
  {
    std::cout<<*option<<std::endl;
  }

  option = folly::get_optional(m,1);
  if (option)
  {
    std::cout<<*option<<std::endl;
  }
  std::string s("boy");
  auto r = folly::get_ptr(m,1);
  if (r)
  {
    *r = "master"s;
  }
  std::cout<<m[1]<<std::endl;
}