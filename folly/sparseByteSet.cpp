#include <folly/container/SparseByteSet.h>
#include <iostream>
void sparseByteSet()
{
  folly::SparseByteSet s;
  s.add('a');
  s.add('b');
  s.add('z');
  std::cout<<s.contains('a')<<std::endl;
  std::cout<<s.contains('c')<<std::endl;
}
int main()
{
  sparseByteSet();
}