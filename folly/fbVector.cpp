#include <folly/FBVector.h>
#include <iostream>
#include <utility>

void fBVector()
{
  folly::fbvector<int> v;
  folly::fbvector<int> vb;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.reserve(100);
  std::cout<<v.size()<<std::endl;
  vb = std::move(v);
  std::cout<<vb[1]<<std::endl;
}
int main()
{
  fBVector();
}