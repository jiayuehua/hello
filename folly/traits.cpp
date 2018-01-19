#include <folly/FBVector.h>
#include <vector>
#include <folly/traits.h>
#include <folly/hash.h>
struct A {
  std::string s;
};

FOLLY_ASSUME_FBVECTOR_COMPATIBLE(A);


void traits()
{
  folly::fbvector<A> f;
  A v;
  f.push_back(v);

}
int main()
{
  traits();
}