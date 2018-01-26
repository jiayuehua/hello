#include <folly/Hash.h>
#include <cstdint>
#include <iostream>
#include <vector>
#include <tuple>
#include <folly/functional/ApplyTuple.h>
class StdHasher {
public:
  template <typename T>
  static size_t hash(const T& t) {
    return std::hash<T>()(t);
  }
};
void hashf()
{
  namespace hash = folly::hash;
  uint64_t a = 1923482342;
  uint64_t b = 1123432342;
  char c = '1';
  double d = 3.2132342;
  uint64_t r = hash::hash_128_to_64(a,b);
  std::cout<<"hash128to64: "<<r<<std::endl;
  std::vector<double> vd(100,a);
  std::cout<<hash::hash_range(vd.begin(),vd.end());
  std::cout<<"hash_combine: "<<hash::hash_combine(a,b,c , d );
  folly::Hash h;
  std::cout<<h(a)<<std::endl;
  std::cout<<h(a,b,c,d)<<std::endl;
  auto tu = std::make_tuple(a,b,c,d);
  std::cout<<h(tu)<<std::endl;
}
int main()
{
  hashf();
}