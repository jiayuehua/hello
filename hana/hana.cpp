#include <boost/hana.hpp>
#include <iostream>
namespace hana = boost::hana;
using namespace hana::literals;
void f()
{
  std::cout<<"call f\n";
}
template <int N>
void Func(){}

void fun()
{
  int a = 1;
  //Func<a>();

  auto i = 1_c+2_c;
  Func<decltype(i)::value>();

  std::cout<<decltype(i)::value<<std::endl;
  i.times(f);
  auto r = hana::make<hana::range_tag>(hana::int_c<3>, hana::int_c<10>);
  static_assert(r == hana::make_range(hana::int_c<3>, hana::int_c<10>), "");
}
int main()
{
  fun();
}