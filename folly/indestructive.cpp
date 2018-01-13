#include <folly/Indestructible.h>
#include <map>
#include <vector>
#include <iostream>
void indestructive()
{
  static folly::Indestructible<std::vector<int>> singleTon({1,2,3,4});

  for (auto i :*singleTon)
  {
    std::cout<<i<<std::endl;
  }
}
int main()
{
  indestructive();
}