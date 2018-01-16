#include <folly/Replaceable.h>
#include <utility>
#include <iostream>
//#include <optional>
struct A {
  ~A()
  {
    std::cout<<"deconstructor\n";
  }
  const int x_ ;
  int y_;
  A(int x, int y):x_(x),y_(y){
    std::cout<<"constructor\n";
  }
};

void replaceAble()
{
  auto r = folly::make_replaceable<A>(10,100);
  std::cout<<r->x_<<std::endl ;
  r.emplace(100,4);
  std::cout<<r->x_<<std::endl ;

}
int main()
{
  replaceAble();
}