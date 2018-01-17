#include <folly/Memory.h>
#include <vector>
#include <iostream>
#include <type_traits>
#include <memory>
void outInt(int * i)
{
  std::cout<<*i<<std::endl;
}
class TestDeconstructor {
public:
  ~TestDeconstructor() {
    std::cout<<"~ TestDeconstructor\n";
  }
};
template <class T>
using STLAllocator = folly::StlAllocator<folly::SysAlloc, T>;

void memory()
{
  auto p = folly::make_unique<std::vector<int>>(10,8);
  std::cout<<p->front()<<std::endl;
  auto p2 = folly::make_unique<int[]>(10);
  p2[2] = 3;
  std::cout<<std::extent<int []>::value<<std::endl;
  std::cout<<std::extent<int [3]>::value<<std::endl;
  int a = 100;
  std::unique_ptr<int , folly::static_function_deleter<int, &outInt> > uI(&a);
  auto sharePtr = folly::to_shared_ptr(folly::make_unique<TestDeconstructor>());
}
void VectorAlloc()
{
  folly::SysAlloc a;
  STLAllocator<int> sa(&a);
  STLAllocator<TestDeconstructor> st(&a);
  std::vector<int, STLAllocator<int>> v(sa);
  v.push_back(100);
  v.push_back(100);
  v.push_back(100);
  v.push_back(100);
  for (auto &i: v)
  {
    std::cout<<i<<std::endl;
  }
  auto up = folly::allocate_unique<TestDeconstructor>(a);
  auto sp = folly::allocate_shared<TestDeconstructor>(a);
  auto upb = folly::allocate_unique<TestDeconstructor>(st);
  auto spb = folly::allocate_shared<TestDeconstructor>(st);
}
int main()
{
  memory();
  VectorAlloc();
}