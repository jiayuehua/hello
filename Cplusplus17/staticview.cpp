#include <boost/static_views.hpp>
#include <boost/static_views/static_map.hpp>
#include <vector>
#include <tuple>
#include <iostream>
#include <cx_algorithm.h>
#include <type_traits>
#include <utility>
namespace static_views = boost::static_views;
constexpr bool equalOneNum(int i)
{
  return i == 8;
}
void staticviews()
{
  // Ask whether T is a Sequence
  constexpr bool vector_is_a_Sequence = static_views::concepts::StaticSequence::test<std::vector<int>>();
  //constexpr bool tuple_is_a_Sequence = static_views::concepts::StaticSequence::test<std::tuple<int,int,double>>();
  std::cout<<vector_is_a_Sequence<<std::endl;
  //std::cout<<tuple_is_a_Sequence<<std::endl;

  // Assert that T is a Sequence. Will trigger a static_assert with
  // and explanation if not.
  //static_views::concepts::Sequence::check<std::vector<int>>();
  //static_views::concepts::Sequence::check<std::tuple<int,int,double>>();
  static constexpr int d[]  = {1,2,3,4,5,6,7,8,9,10};
  static constexpr auto rawView = static_views::raw_view(d);
  static constexpr auto drop2 = rawView|static_views::drop(2);// forward reference related!!!
  //constexpr auto sb = static_views::find_first_i(rawView|static_views::drop(2), &equalOneNum);
  //constexpr auto s = static_views::find_first_i(drop2, &equalOneNum);
  std::cout<<"find_first_i\n";
  //std::cout<<s<<std::endl;
  //static constexpr std::pair<int, const char*> data[] = {
  //  {1,"one",},
  //  {2,"two",},
  //  {3,"three",}
  //};
  namespace static_map = static_views::static_map;
  //static constexpr auto m = static_map::make_static_map(static_views::raw_view(data),
  //                                                      [](auto&& x) { return x.first; },
  //                                                      [](auto&& x) { return x.second; });
  //constexpr auto one = m[1];
  struct data_type {
    int code;
    int fruit;
  };

  static constexpr data_type data[] = {
  { 123, 1 },
  { 456, 2 },
  { 789, 3 }
  };

  static constexpr auto rView = boost::static_views::raw_view(data);
  static constexpr auto fruits = static_map::make_static_map(
    rView,
    &data_type::code,
    &data_type::fruit);
  constexpr auto one = fruits[123];
  static_assert(one==1,"");
  constexpr bool T_is_a_View = boost::static_views::concepts::View::test<decltype(rawView)>();
}
class A {
public:
  template<class T>
  static constexpr bool isA()
  {
    return true;
  }
};
template <class T, typename = std::enable_if_t<A::template isA<T>()> >
class B
{};

int main()
{
  B<int> i;
  staticviews();
}