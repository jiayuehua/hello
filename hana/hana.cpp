#include <boost/hana.hpp>
#include <boost/hana/traits.hpp>
#include <iostream>
#include <string>
#include <assert.h>
#include <type_traits>
namespace hana = boost::hana;
namespace traits = hana::traits;

using namespace hana::literals;
struct Fish {
  std::string name;
};
struct Dog {
  std::string name;
};
struct Cat {
  std::string name;
};
void transformF()
{
  auto t = hana::make_tuple(Cat{"cat"}, Dog{"dog"}, Fish{"fish"});
  auto r = hana::transform(t, [](auto a){std::cout<<a.name<<std::endl;return a.name;});
  hana::for_each(t, [](auto a){std::cout<<a.name<<std::endl;});
  auto ts = hana::make_tuple(std::string{"cat"}, std::string("dog"), std::string("fish"));
  auto reverseT = hana::reverse(ts);

  assert(r==ts);
}
void f()
{
  auto t = hana::make_tuple(hana::type_c<int*>, hana::type_c<double>, hana::type_c<float>);
  auto tb = hana::make_tuple(hana::type_c<double>, hana::type_c<float>);
  auto r = hana::filter(t, [](auto a){ return !traits::is_pointer(a);});

  static_assert(r == tb,"");
  std::cout<<"call f\n";
}
void
hana_find()
{
  auto t = hana::make_tuple(1_c,2_c,4_c);
  auto no = hana::find(t, 5_c);
  auto y = hana::find(t, 2_c);

  static_assert(no == hana::nothing,"");
  static_assert(y == hana::just(2_c),"");
}
constexpr decltype(0_c) fadd()
{
  return 0_c;
}
template<class TL, class... T>
constexpr decltype(auto) fadd(TL t,T... arg)
{
  return t + fadd(arg...);
}
void hana_algo()
{
  auto t = hana::make_tuple(1, 1, 2, 2, 3, 3, 2.5, -5);
  std::cout<<"line: "<<__LINE__<<std::endl;
  auto df = hana::drop_front(t,2_c);
  hana::for_each(df, [](auto a){std::cout<<a<<std::endl;});
  std::cout<<"line: "<<__LINE__<<std::endl;
  auto dfe = hana::drop_front_exactly(t,3_c);
  hana::for_each(dfe, [](auto a){std::cout<<a<<std::endl;});
  std::cout<<"line: "<<__LINE__<<std::endl;
  auto db = hana::drop_back(t,3_c);
  hana::for_each(db, [](auto a){std::cout<<a<<std::endl;});

  std::cout<<"line: "<<__LINE__<<std::endl;
  auto dw = hana::drop_while(t, [](auto a){ return 1_c<1_c; } );
  hana::for_each(dw, [](auto a){std::cout<<a<<std::endl;});

  std::cout<<"line: "<<__LINE__<<std::endl;
  auto hfill = hana::fill(t, 4);
  hana::for_each(hfill, [](auto a){std::cout<<a<<std::endl;});

  std::cout<<"line: "<<__LINE__<<std::endl;
  //hana::find(t, 3);
  //static_assert (hfind == hana::just(3), "find fail");

  //std::cout<<"line: "<<__LINE__<<std::endl;
  //auto hfind = hana::find_if(t, [](auto a)
  //                           {return a == 3;}
  //);
  //static_assert (hfind == hana::just(3), "find fail");

  std::cout<<"line: "<<__LINE__<<std::endl;
  auto tA = hana::make_tuple(1,3,5);
  auto tB = hana::make_tuple(2,4,6);
  auto tC = hana::make_tuple(tA,tB);
  auto hflattern = hana::flatten(tC);
  hana::for_each(hflattern, [](auto a){std::cout<<a<<std::endl;});

  std::cout<<"line: "<<__LINE__<<std::endl;

  std::cout<<hana::fold_left(tA, 5, [](auto x, auto y){return x*y;});
  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<hana::fold_right(tA, 5, [](auto x, auto y){return x*y;});
  std::cout<<"line: "<<__LINE__<<std::endl;
  auto tf = hana::front(t);
  std::cout<<tf<<std::endl;
  auto tg = hana::make_tuple(1_c,1_c,2_c,2_c,3_c,3_c);
  auto tgb = hana::make_tuple(1_c,1_c,2_c,2_c,3_c,4_c);
  auto pa = hana::partition(tg, [](auto a){return a%2_c == 0_c;});
  static_assert(hana::first(pa) == hana::make_tuple(2_c,2_c ),"");

  auto max = hana::maximum(tgb);

  std::cout<<decltype(max)::value<<std::endl;
  auto min_ = hana::minimum(tgb);
  std::cout<<decltype(min_)::value<<std::endl;
  auto l = hana::length(tg);
  std::cout<<decltype(l)::value<<std::endl;
  auto e = hana::is_empty(tg);
  std::cout<<decltype(e)::value<<std::endl;
  static_assert(!e,"");
  static_assert((e == hana::false_c), "");

  auto g = hana::group(tg);
  static_assert(g[0_c]==hana::make_tuple(1_c,1_c), "");

  auto td = hana::insert(t, 0_c, 32 );
  auto tgInsert = hana::insert(tg, 0_c, 32_c );
  assert(td ==  hana::make_tuple(32, 1, 1, 2, 2, 3, 3, 2.5, -5));
  static_assert(tgInsert ==  hana::make_tuple(32_c, 1_c, 1_c, 2_c, 2_c, 3_c, 3_c));
  auto tda = hana::insert_range(t, 0_c, hana::make_tuple(32,3) );
  assert(tda ==  hana::make_tuple(32, 3,1, 1, 2, 2, 3, 3, 2.5, -5));
  hana::index_if(tg, traits::is_pointer);
  auto i_if = hana::index_if(t, hana::is_a<int>);
  static_assert(i_if== hana::just(hana::size_c<0>),"");
  std::cout<<decltype(7_c)::value<<std::endl;
  auto r = hana::lexicographical_compare(t,td);
  auto rg = hana::lexicographical_compare(tg,tgb);
  static_assert(rg,"");
  assert(r);
  auto rpre = hana::prepend(tg, 18_c);
  static_assert(rpre == hana::make_tuple(18_c,1_c,1_c,2_c,2_c,3_c,3_c),"");
  auto rrem = hana::remove(tg,1_c);
  static_assert(rrem == hana::make_tuple(2_c,2_c,3_c,3_c),"");
  auto rrem_at = hana::remove_at(tg,1_c);
  static_assert(rrem_at == hana::make_tuple(1_c,2_c,2_c,3_c,3_c),"");
  auto rrem_if = hana::remove_if(tg, [](auto x ){return x%2_c == 0_c;});
  static_assert(rrem_if == hana::make_tuple(1_c,1_c,3_c,3_c ),"");
  auto rrem_range = hana::remove_range(tg, 0_c,2_c);
  static_assert(rrem_range == hana::make_tuple(2_c,2_c,3_c,3_c ),"");
  auto rrep = hana::replace(tg,1_c,4_c);
  static_assert(rrep == hana::make_tuple(4_c, 4_c, 2_c,2_c,3_c,3_c), "");
  auto rrep_if = hana::replace_if(tg, [](auto x ){return x%2_c == 0_c;}, 4_c);
  static_assert(rrep_if == hana::make_tuple(1_c,1_c,4_c,4_c,3_c,3_c),"");
  auto rrev =hana::reverse(tg);
  static_assert(rrev == hana::make_tuple(3_c,3_c,2_c,2_c,1_c,1_c),"");
  auto rsli_c = hana::slice_c<0,2>(tg);
  auto rsli = hana::slice(tg, hana::tuple_c<int,0,1>);
  static_assert(rsli_c ==hana::make_tuple(1_c,1_c),"");
  static_assert(rsli ==hana::make_tuple(1_c,1_c),"");
  auto rsort = hana::sort(rrev);
  static_assert(rsort==tg, "");
  auto rtak = hana::take_back(tg,2_c);
  static_assert(rtak == hana::make_tuple(3_c,3_c),"");
  auto rtran = hana::transform(tg, [](auto a){return a+1_c;});
  static_assert(rtran == hana::make_tuple(2_c,2_c,3_c,3_c,4_c,4_c),"");

  auto runpack = hana::unpack(tg, [](auto... a ){return fadd(a...);});
  static_assert(runpack == 12_c,"");
  auto rzip = hana::zip(tg,tg,tg);
  static_assert(rzip[0_c] == hana::make_tuple(1_c,1_c,1_c),"");
  auto rzip_with = hana::zip_with([](auto... a ){return fadd(a...);},tg,tg,tg);
  static_assert(rzip_with[0_c] == 3_c,"");
  //static_assert(r==hana::true_c,"");
  //std::cout<<i()<<std::endl;
  /*auto adjustR = hana::adjust(t, 1, [](auto a){ return -a;});
  hana::for_each(adjustR, [](auto a){std::cout<<a<<std::endl;});
  std::cout<<"line: "<<__LINE__<<std::endl;
  auto adjustIFR = hana::adjust_if(t, [](auto a){ return a >0;}, [](auto a){ return -a;});
  hana::for_each(adjustIFR, [](auto a){std::cout<<a<<std::endl;});
  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<hana::all(t)<<std::endl;
  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<hana::all_of(t, [](auto a){return a>0;})<<std::endl;
  std::cout<<"line: "<<__LINE__<<std::endl;
  auto tappend = hana::append(t, 3.5);
  hana::for_each(tappend, [](auto a){std::cout<<a<<std::endl;});
  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<hana::at(t, 2_c)<<std::endl;
  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<hana::back(t)<<std::endl;
  std::cout<<"line: "<<__LINE__<<std::endl;
  auto tc = hana::concat(t, t);
  hana::for_each(tc, [](auto a){std::cout<<a<<std::endl;});
  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<hana::contains(tc, 3)<<std::endl;
  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<hana::count(tc, 3)<<std::endl;
  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<hana::count_if(tc,  [](auto a) { return a == 3; } )<<std::endl;*/
}
template <int N>
void Func(){}
void fun()
{
  //int a = 1;
  //Func<a>();
  auto t = hana::make_tuple(1,5.5, "hello");
  hana::for_each(t, [&](auto member){std::cout<<member<<std::endl;});

  auto i = 1_c+2_c;
  Func<decltype(i)::value>();

  std::cout<<decltype(i)::value<<std::endl;
  i.times(f);
  auto r = hana::make<hana::range_tag>(hana::int_c<3>, hana::int_c<10>);
  static_assert(r == hana::make_range(hana::int_c<3>, hana::int_c<10>), "");
}
template <int F, int T>
constexpr hana::range<int, F,T>  irange_c {};

void hana_container()
{
  static_assert(irange_c<10,100>[0_c] == 10_c, "");
  static_assert(hana::front(irange_c<0,10>) == 0_c,"");
  static_assert(hana::find(irange_c<0,10>, 1_c) == hana::just(1_c),"");
  static_assert(irange_c<1,10> == irange_c<1,10>,"" );
  static_assert(irange_c<3,10> != irange_c<1,10>,"" );
}
template<class T>
std::enable_if_t<
  decltype( traits::is_class(hana::type_c<T>))::value> f()
{
  std::cout<<"class"<<std::endl;
}
template<class T>
std::enable_if_t<
  decltype( traits::is_fundamental(hana::type_c<T>))::value> f() {
  std::cout<<"fundamental"<<std::endl;
}
void hana_type()
{
  auto StdUnsignedInts = hana::tuple_t<unsigned char, unsigned short int,unsigned int, unsigned long int> ;
  auto is = traits::is_unsigned(hana::type_c<unsigned int>)&&traits::is_fundamental(hana::type_c<unsigned int>);
  static_assert(is, "unsigned ");
  auto r = hana::contains(StdUnsignedInts, hana::type_c<unsigned int>);
  static_assert(r, "contains ");
}

class A{};
struct Bar {
};
struct Foo {
  int mem[4];
};
void hana_valid()
{
  auto has_mem = hana::is_valid([](auto a)->hana::type<decltype(traits::declval(a).mem)>{} );
  auto bar_has = has_mem(hana::type_c<Bar>);
  auto Foo_has = has_mem(hana::type_c<Foo>);
  static_assert(Foo_has, "");

}
int main()
{
  //hana_algo();
  f<int>();
  f<A>();
  //transformF();
  //f();
  //fun();
}