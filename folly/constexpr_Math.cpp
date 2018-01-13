#include <folly/ConstexprMath.h>
#include <iostream>
void constExprMath()
{
  constexpr int imax = folly::constexpr_max(1,2,5,8,9,90,100,2,34,11,3,11,12,2388292,1111);
  std::cout<<imax<<std::endl;

  constexpr int imin = folly::constexpr_min(1,2,5,8,9,90,100,2,34,11,3,11,12,2388292,1111);
  std::cout<<imin<<std::endl;

  constexpr int low =1, high = 7, v1 = 0, v2=3,v3 = 100;
  std::cout<<folly::constexpr_clamp(v1,low,high)<<std::endl;
  std::cout<<folly::constexpr_clamp(v2,low,high)<<std::endl;
  std::cout<<folly::constexpr_clamp(v3,low,high)<<std::endl;
  std::cout<<folly::constexpr_abs(-33)<<std::endl;
  std::cout<<folly::constexpr_pow(3,3)<<std::endl;
  std::cout<<folly::constexpr_ceil(1,8)<<std::endl;
  std::cout<<folly::constexpr_ceil(7,8)<<std::endl;
  std::cout<<folly::constexpr_ceil(8,8)<<std::endl;
  std::cout<<folly::constexpr_ceil(0,8)<<std::endl;
  std::cout<<folly::constexpr_log2(1024)<<std::endl;
  std::cout<<folly::constexpr_log2_ceil(511)<<std::endl;
  std::cout<<folly::constexpr_log2_ceil(7)<<std::endl;
  std::cout<<folly::constexpr_log2_ceil(8)<<std::endl;
}
int main(int argc, char* argv[])
{
  constExprMath();
}