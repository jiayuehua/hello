#include <folly/small_vector.h>
#include <iostream>
#include <cstdint>
void small_vector_test()
{
  try {
    using namespace folly::small_vector_policy;
    folly::small_vector<int, 4,  uint32_t> sv;
    folly::small_vector<int, 2, NoHeap, uint16_t> sv1;
    std::cout<<sizeof(sv)<<std::endl;
    std::cout<<sizeof(sv1)<<std::endl;
    sv.push_back(1);
    sv.push_back(2);
    sv.push_back(3);
    sv.push_back(4);
    sv.push_back(5);
  }
  catch(...)
  { std::cout<<"catch Exception\n";}
}
