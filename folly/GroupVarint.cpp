#include <folly/GroupVarint.h>
#include <folly/FBString.h>
#include <folly/Range.h>
#include <iostream>
#include <string>

struct Appender{
  folly::fbstring s_;
public:
  void operator()(folly::StringPiece s)
  {
    s_.append(s.begin(),s.end());
  }
  const folly::fbstring & getResult()const
  {
    return s_;
  }
};
typedef folly::GroupVarintEncoder<uint32_t, Appender> GroupVarint32Encoder;
typedef folly::GroupVarintEncoder<uint64_t, Appender> GroupVarint64Encoder;
void GroupVarint()
{
  Appender a;
  GroupVarint32Encoder e(a);
  for (uint32_t i = 0; i<100; ++i)
  {
    e.add(i);
  }
  e.finish();
  std::cout<<e.output().getResult()<<std::endl;
  folly::GroupVarint32Decoder d(e.output().getResult());
  uint32_t u;
  while (d.next(&u))
  {
    std::cout<<u<<std::endl;
  }
}
int main()
{
  GroupVarint();
}
