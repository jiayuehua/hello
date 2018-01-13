#include <folly/Optional.h>
#include <iostream>
struct A {
  A() = default;
  A(int i1):i_(i1){}
  int i_ = 100;
};
void optional_fun()
{
  folly::Optional<A> o;
  folly::Optional<A> ob;
  std::cout<<"=======A\n";
  if (o)
  {
    std::cout <<o->i_<<std::endl;
  }
  o.emplace(2018);
  std::cout<<"=======B1\n";
  if (o)
  {
    std::cout <<o->i_<<std::endl;
  }
  std::cout<<"=======B\n";
  if (ob)
  {
    std::cout <<ob->i_<<std::endl;
  }
  std::cout<<"=======C\n";
  ob=std::move(o);
  if (ob)
  {
    std::cout<<ob->i_<<std::endl;
  }
  int t = 2017;
  {

  folly::Optional<int> o;
  auto oc = folly::make_optional((t));
  auto ocr = folly::make_optional((2018));
  auto ocl = folly::make_optional((-2018));
  std::cout<<(o<oc)<<std::endl;
  std::cout<<(oc<o)<<std::endl;
  std::cout<<(oc<ocr)<<std::endl;
  std::cout<<(o<ocl)<<std::endl;
  std::cout<<(ocl<ocr)<<std::endl;
  }
  auto od = folly::make_optional(t);
  if (od)
  {
    std::cout<<*od<<std::endl;
  }
}
int main()
{
  optional_fun();
}