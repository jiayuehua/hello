#include <folly/Fingerprint.h>
#include <iostream>
#include <folly/FBString.h>
#include <cstdint>
#include <array>
void fingerprint()
{
  folly::Fingerprint<96> fp;
  std::array<uint64_t, 2> a;
  fp.update("hello,world");
  fp.update(std::string("sadfhsadsalkdjfksajdflsakdhglkdsht93q4yuiewqyftrncxv,mcxng"));
  fp.update(folly::fbstring("sadfhsadsalkdjfksajdflsakdhglkdsht93q4yuiewqyftrncxv,mcxng"));
  folly::fbstring fb;
  fb.reserve(50000);
  for (int i = 0; i <50000; ++i)
  {
    fb.push_back(static_cast<char>(i%256));
    fp.update8(uint8_t (i));
  }
  fp.update(fb);
  fp.write(a.data());
  std::cout<<a[0]<<" " <<a[1]<<std::endl;
  std::cout<<folly::Fingerprint<96>::size()<<std::endl;



}

int main(int argc, char* argv[])
{
  fingerprint();
}