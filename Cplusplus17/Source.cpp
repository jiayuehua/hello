//#include <set>
//#include <iostream>
//#include <type_traits>
//void foo()
//{
//  std::set<int> s;
//  s.insert(100);
//  s.insert(77);
//  auto i =  s.extract (s.begin());
//  i.value() = 7;
//  s.insert(std::move(i));
//  for (auto i : s)
//  {
//    std::cout <<i<<std::endl;
//  }
//}
//int main()
//{
//  foo();
//}
//#include <cx_utils.h>
//
//void cx_util()
//{
//  constexpr const char* p = "hello, world";
//  constexpr const char* pl = "left";
//  constexpr const char* pr = "right";
//  auto len = cx::strlen("hello");
//  auto l = cx::strlen(p);
//  auto cmpR = cx::strcmp(pl, pr);
//}
//int main()
//{
//  cx_util();
//}
//#include <cx_algorithm.h>
#include <cx_array.h>
#include <iostream>
#include <exception>
#include <sprout/algorithm.hpp>
#include <sprout/container.hpp>
struct A {
  constexpr bool operator()(int i)const
  {
    return i % 2 == 0;
  }
};
void
cx_algo()
{
  static constexpr auto f = cx::make_array(0, 1, 2, 2, 5, 1, 3, 4, 5, 6);
  constexpr auto fb = cx::make_array(5, 3);
  static constexpr auto fs = cx::sort(f, std::less<>());
  constexpr auto lb = sprout::lower_bound(fs.cbegin(), fs.cend(), 3);

  std::cout<<"lower_bound"<<std::endl;
  std::cout<<lb-fs.cbegin()<<std::endl;

  //static constexpr auto fs_sub = cx::make_array(3, 4, 5);
  //constexpr auto cnt = cx::count(fs.begin(), fs.end(), 2);
  //constexpr A even;
  //constexpr auto even_cnt = cx::count_if(fs.begin(), fs.end(), even);
  //constexpr auto pos = cx::find(f.begin(), f.end(), 3);
  //constexpr auto findR = *pos;
  //std::cout << findR << std::endl;
  //constexpr auto pos2 = cx::find_if(f.begin(), f.end(), even);
  //constexpr auto pos3 = cx::find_if_not(f.begin(), f.end(), even);
  //constexpr auto allr = cx::all_of(f.begin(), f.end(), even);
  //constexpr auto anyr = cx::any_of(f.begin(), f.end(), even);
  //constexpr auto noner = cx::none_of(f.begin(), f.end(), even);
  //constexpr auto equalr = cx::equal(f.begin(), f.end(), fs.begin());
  //constexpr auto equalrb = cx::equal(f.begin(), f.end(), f.begin());
  //constexpr auto mismatchr = cx::mismatch(f.begin(), f.end(), fs.begin());
  //std::cout << *mismatchr.first << std::endl;
  //std::cout << mismatchr.first - f.begin() << std::endl;
  //constexpr auto first = cx::find_first_of(f.begin(), f.end(), fb.begin(), fb.end());
  //std::cout << *first << std::endl;
  //std::cout << first - f.begin() << std::endl;
  //constexpr auto pose = cx::adjacent_find(f.begin(), f.end());
  //std::cout << pose - f.begin() << std::endl;
  //constexpr auto pos_search = cx::search(fs.begin(), fs.end(), fs_sub.begin(), fs_sub.end());
  //std::cout << pos_search - fs.begin() << std::endl;
  //constexpr auto pos_search_n = cx::search_n(fs.begin(), fs.end(), 1, 6);
  //std::cout << pos_search_n - fs.begin() << std::endl;
}
constexpr int constexpr_error(int i)
{
  //return i < 0 ? i : throw std::runtime_error("world");
}
int main()
{
  cx_algo();
  try
  {
    //constexpr auto i =  constexpr_error(9);
    //constexpr auto i =  constexpr_error(-9);
  }
  catch (const std::exception&e)
  {
    std::cout << e.what() << std::endl;
  }
}