#include <folly/AtomicBitSet.h>
#include <iostream>
folly::AtomicBitSet<100> s;
void atomicBitSet()
{
  s.set(2);
  std::cout<<s.test(2)<<std::endl;
  s.reset(2);
  std::cout<<s.test(2)<<std::endl;
}
int main()
{
  atomicBitSet();
}