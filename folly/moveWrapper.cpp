#include <iostream>
#include <folly/MoveWrapper.h>
#include <memory>
#include <functional>
#include <utility>

void moveWrapper()
{
  auto p = std::make_unique<int>(1000);
  auto pa = std::make_unique<int>(999);
  auto lcap = [unip = std::move(pa)]{
    if (unip)
    {
      std::cout<<*unip<<std::endl;
    }
  };
  lcap();
  auto up = folly::makeMoveWrapper(p);
  auto l = [up]{
    if (*up)
    {
      std::cout<<**up<<std::endl;
    }
  };
  l();
  if (*up)
  {
    std::cout<<**up<<std::endl;
  }
}
int main()
{
  moveWrapper();
}