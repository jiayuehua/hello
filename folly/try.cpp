#include <folly/Try.h>
#include <exception>
#include <iostream>
#include <utility>
void
foo()
{
  throw std::out_of_range("out of range\n");
}

decltype(auto)
foo2()
{
  return std::make_pair(1,2018);
}
void tryF()
{
  auto t = folly::makeTryWith(&foo);
  if (t.hasValue())
  {
    std::cout<<"t value "<< std::endl;
  }
  if (t.hasException())
  {
    t.withException([](std::out_of_range& r){std::cout<<r.what()<<std::endl;});
  }
  {

  auto tf2 = folly::makeTryWith(&foo2);
  if (tf2.hasValue())
  {

    std::cout<<"t value "<<tf2->first<< std::endl;
  }
  //if (tf2.hasException())
  {
    std::cout<<"start\n";
    tf2.withException([](std::out_of_range& r){std::cout<<r.what()<<std::endl;});
    std::cout<<"end\n";
  }
  }

}
int main()
{
  tryF();
}