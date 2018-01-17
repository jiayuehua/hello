#include <exception>
#include <folly/ExceptionString.h>
#include <iostream>
#include <folly/FBString.h>
int exceptionStr()
{
  try
  {
    throw std::runtime_error("runtime error!");
  }
  catch (const std::exception&e)
  {
    std::cout<<folly::exceptionStr(e);
    auto ptr = std::current_exception();
    std::cout<<folly::exceptionStr(ptr);
  }
  return 0;
}
int main()
{
  exceptionStr();
}