#include <folly/Unicode.h>
#include <folly/String.h>
#include <iostream>
void unicode()
{
  char32_t a = 0x77*256+0xe5;
  auto r = folly::codePointToUtf8(a);
  std::cout<<folly::hexlify(r)<<std::endl;
  for (auto &i:r)
  {
    std::cout<<(int)i<<" ";
  }
  std::cout<<std::endl;
  std::cout<<r <<std::endl;
  const unsigned char* b = (unsigned char*)r.data();

  char32_t aa = folly::utf8ToCodePoint(b, (unsigned char*)r.data()+r.size(), true);

  std::cout<<(a==aa)<<std::endl;

}
int main()
{
  unicode();
}