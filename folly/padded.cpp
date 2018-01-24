#include <folly/Padded.h>
#include <vector>
#include <iostream>

struct Point {
  int x_;
  int y_;
  int z_;
};
void padded()
{
  typedef std::vector<folly::padded::Node<Point, 64> > V;
  folly::padded::Adaptor<V> v;
  v.push_back(Point{1,2,3});
  v.push_back(Point{1,2,3});
  v.push_back(Point{1,2,3});
  v.push_back(Point{1,2,3});
  std::cout<<folly::padded::Adaptor<V>::Node::kPaddingBytes<<std::endl;
  for (auto i :v)
  {
    std::cout<<i.x_<<i.y_<<i.z_<<std::endl;
  }
}
int main(int argc, char* argv[])
{
  padded();
}