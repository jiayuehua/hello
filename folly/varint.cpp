#include <folly/Varint.h>
#include <iostream>
#include <array>
#include <cstdint>
void varint()
{
  std::array<uint8_t, 100> a;
  size_t n = folly::encodeVarint(2938298392929, &a[0]);
  std::cout<<n<<std::endl;
  folly::Range<uint8_t*> r(&a[0], &a[n]);
  uint64_t v = folly::decodeVarint(r);
  std::cout<<v<<std::endl;
}
int main()
{
  varint();
}