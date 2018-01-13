#include <folly/Bits.h>
#include <iostream>
void Bits()
{
  int x=0x0102u;
  std::cout<<folly::findFirstSet(x)<<std::endl;
  std::cout<<folly::findLastSet(x)<<std::endl;
  std::cout<<folly::isPowTwo(0x11u)<<std::endl;
  std::cout<<folly::isPowTwo(0x10u)<<std::endl;
  std::cout<<folly::nextPowTwo(0x13u)<<std::endl;
  std::cout<<folly::popcount(0x13u)<<std::endl;
  std::cout<<folly::popcount(0x1E3u)<<std::endl;
  std::cout<<folly::Endian::big(x)<<std::endl;
  std::cout<<folly::Endian::little(x)<<std::endl;
  std::cout<<folly::Endian::swap(x)<<std::endl;

}
int main()
{
  Bits();
}