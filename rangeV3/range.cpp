#include <range/v3/all.hpp>
#include <vector>
#include <iostream>
#include <functional>
#include <regex>
#include <string>


void viewA()
{
  using namespace ranges;
  std::vector<int> v{3,2,1,5,0,4,8,9,7,3,3,3,3,35,5,5};
  auto r = v| view::remove_if([](auto i){return i %3 == 0;})|view::transform([](auto i){std::cout<<i;return i*=3; });
   v |= action::sort|action::unique;
   v = std::move(v)|action::sort|action::unique;
  for (auto i : v)
  {
    std::cout<<i<<std::endl;
  }
}
void viewB()
{
  using namespace ranges;
  std::vector<int> v{0,0,1,1,1,3,4,6,6,6,6,7};

  //{

  //auto r = v| view::adjacent_filter(std::not_equal_to<>());
  //for (auto i : r)
  //{
  //  std::cout<<i<<std::endl;
  //}
  //}
  {
    std::cout<<"\nbounded ===== \n";
    auto r = v|view::take_while([](auto i) {return i%3 == 1;})|view::bounded;


  for (auto i : r)
  {
    std::cout<<i<<std::endl;
  }
    std::cout<<"\nbounded ~~~~~ \n";
  }
  /*{
  auto r = v| view::adjacent_remove_if(std::not_equal_to<>());
  for (auto i : r)
  {
    std::cout<<i<<std::endl;
  }
  }
  {
  any_view<int> a(v);

  for (auto i = a.begin(); i!= a.end(); ++i)
  {
    std::cout<<*i<<std::endl;
  }
  }*/
}
//void sort()
//{
//  using namespace ranges;
//  std::vector<int> v{3,2,1,5,0,4,8,9,7};
//
//
//  ranges::sort(v);
//  auto i = ranges::find(v, 3);
//  std::cout<<*i<<std::endl;
//}
// helper function to print a tuple of any size
template<class Tuple, std::size_t N>
struct TuplePrinter {
  static void print(const Tuple& t)
  {
    TuplePrinter<Tuple, N - 1>::print(t);
    std::cout << ", " << std::get<N - 1>(t);
  }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(const Tuple& t)
  {
    std::cout << std::get<0>(t);
  }
};

template<class... Args>
void print(const std::tuple<Args...>& t)
{
  std::cout << "(";
  TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
  std::cout << ")\n";
}
void product()
{
  using namespace ranges;
  std::vector<int> v{3,2,1,5,0,4,8,9,7,3,3,3,3,35,5,5};
  any_view<int> a (v|view::all);
  auto r =  a|view::transform([](int i){ return i;})|view::bounded;
  for (auto i :r)
  {
    std::cout<<i<<std::endl;
  }

  any_view<int> a2 (v);

  std::vector<int> vcpa{1,2,3};
  std::vector<int> vcpb{4,5,6};
  std::vector<int> vcpc{7,8,9};
  constexpr auto N = std::tuple_size<std::tuple<int, int, int>>::value;
  //A<std::tuple<int,int,int> ,N> printF;
  auto t = view::cartesian_product(vcpa,vcpb,vcpc)|view::bounded;
  for (auto i : t)
  {
    print(i);

  }
  auto chunk = v| view::chunk(3)|view::bounded;
  for (auto s : chunk)
  {
    for (auto r: s|view::bounded)
    {
      std::cout<<r<<std::endl;
    }
  }
}
void counted()
{
  std::vector<int> vcpa{1,2,3};
  auto r = view::counted(vcpa.cbegin(), 2)|view::bounded;
  std::cout<<"counted\n";
  for (auto i :r)
  {
    std::cout<<i<<" ";
  }
  std::cout<<" ==== \n";
}
void cycle()
{
  std::vector<int> vcpa{1,2,3};
  auto r = vcpa|view::cycle|view::take(10)|view::bounded;
  std::cout<<"cycle\n";
  for (auto i :r)
  {
    std::cout<<i<<" ";
  }
  std::cout<<" ==== \n";
}
void concat()
{
  std::vector<int> vcpa{1,2,3};
  std::vector<int> vcpb{4,5,6};
  std::vector<int> vcpc{7,8,9};
  auto r = view::concat(vcpa,vcpb, vcpc)|view::bounded;
  std::cout<<"concat\n";
  for (auto i :r)
  {
    std::cout<<i<<" ";
  }
  std::cout<<" ==== concat\n";
}
int main()
{
  product();
  concat();
  counted();
  cycle();
  //viewA();
  viewB();
  //sort();
}
