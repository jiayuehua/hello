#include <folly/sorted_vector_types.h>
#include <iostream>
void sorted_vector_types()
{
  folly::sorted_vector_set<int> s;
  s.insert(5);
  s.insert(1);
  s.insert(7);
  s.insert(2);
  s.insert(8);
  s.insert(4);
  std::cout<<"=====1======\n";
  auto it = s.find(4);
  if (it!= s.end() )
  {
    std::cout<<*it<<std::endl;
  }
  std::cout<<"=====2======\n";
  it = s.find(3);
  if (it!= s.end() )
  {
    std::cout<<*it<<std::endl;
  }
  std::cout<<"=====3======\n";
  for (const auto& t: s)
  {
    std::cout<<t <<std::endl;
  }
}
int main()
{
  sorted_vector_types();
}