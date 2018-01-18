#include <folly/Math.h>
#include <iostream>
void RoundAway()
{
  std::cout<< folly::divRoundAway(5,3)<<std::endl; //2
  std::cout<< folly::divRoundAway(5,-3)<<std::endl;//
  std::cout<< folly::divRoundAway(-5,3)<<std::endl;
  std::cout<< folly::divRoundAway(-5,-3)<<std::endl;
}
void Trunc()
{
  std::cout<< folly::divTrunc(5,3)<<std::endl;
  std::cout<< folly::divTrunc(5,-3)<<std::endl;
  std::cout<< folly::divTrunc(-5,3)<<std::endl;
  std::cout<< folly::divTrunc(-5,-3)<<std::endl;
}
void Floor()
{
  std::cout<< folly::divFloor(5,3)<<std::endl;
  std::cout<< folly::divFloor(5,-3)<<std::endl;
  std::cout<< folly::divFloor(-5,3)<<std::endl;
  std::cout<< folly::divFloor(-5,-3)<<std::endl;
}
void Ceil()
{
  std::cout<< folly::divCeil(5,3)<<std::endl;
  std::cout<< folly::divCeil(5,-3)<<std::endl;
  std::cout<< folly::divCeil(-5,3)<<std::endl;
  std::cout<< folly::divCeil(-5,-3)<<std::endl;
}
int main()
{
  Ceil();
  Floor();
  RoundAway();
  Trunc();
}