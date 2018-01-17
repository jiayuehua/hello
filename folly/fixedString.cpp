#include <folly/FixedString.h>
#include <iostream>
#include <tuple>
#include <utility>
#include "fixedString.h"
using FixedString = folly::FixedString<64>;
using namespace folly::string_literals;
constexpr folly::FixedString<1024> fixedString(folly::FixedString<1024> s)
{
  s.push_back('c');
  return s;
}
constexpr FixedString add(FixedString l, FixedString r)
{
  return l + r;
}

constexpr FixedString add2(FixedString l, FixedString r)
{
  return l + r+"hello"_fs;
}
constexpr FixedString replace(FixedString s)
{
  s.replace(1,3,"ooo");
  return s;
}
constexpr FixedString encryptStr(FixedString s)
{
  for (auto& i :s)
  {
    i+=1;
  }
  return  s;
}
constexpr std::size_t find(FixedString s)
{
  return  s.find("so");
}
constexpr FixedString erase(FixedString s)
{
  return  s.erase(0,3);
}
constexpr FixedString copy(FixedString s)
{
  char a[1000]={};
  s.copy(a,s.size(), 0);
  FixedString s2(a, s.size());
  return s2;
}

constexpr std::tuple<FixedString,FixedString> swapTuple(FixedString l, FixedString r)
{
  l.swap(r);
  return  std::make_tuple(l,r);
}
constexpr std::pair<FixedString,FixedString> swap(FixedString l, FixedString r)
{
  l.swap(r);
  return  std::make_pair(l,r);
}
int main()
{
  constexpr folly::FixedString<1024> s;
  constexpr auto s1 = fixedString(s);
  static_assert(s1.size() == 1, "fail");
  constexpr auto addr = add(s1,s1);
  constexpr auto add2r = add2(s1,s1);
  static_assert(addr.size()==2, "fail");
  static_assert(add2r.size()==7, "fail");
  {
  constexpr FixedString fs("worldsoccer");
  constexpr FixedString repRexp("wooodsoccer");
  constexpr auto repR = replace(fs);
  static_assert(repR==repRexp,"fail");
  }
  {
  constexpr FixedString fs("worldsoccer");
  constexpr auto repR = find(fs);
  static_assert(repR==5,"fail");
  }
  {
  constexpr FixedString fs("worldsoccer");
  constexpr auto  subS = fs.substr(5,6);
  static_assert(subS=="soccer","fail");
  }
  {
    outString();
    std::cout<<email<<std::endl;
  }
  {
  constexpr FixedString fs("aaaaa");
  constexpr auto  subS = erase(fs);
  static_assert(subS=="aa","fail");
  }
  {
  constexpr FixedString fs("aaaaa");
  constexpr auto  subS = encryptStr(fs);
  static_assert(subS=="bbbbb","fail");
  }
  {
  constexpr FixedString fs("aaaaa");
  constexpr auto  subS = copy(fs);
  static_assert(subS=="aaaaa","fail");
  }
  {
  constexpr FixedString s("aaaaa");
  constexpr FixedString c("cc");
  constexpr auto d = s.creplace(1,2,"bb");
  constexpr auto d2 = s.creplace(1,2,c);
  static_assert(d =="abbaa","fail");
  static_assert(d2 =="accaa","fail");
  }
  {
  constexpr FixedString s("aaaaa");
  constexpr FixedString d("cc");
  constexpr auto t =  swap(s,d);
  //constexpr auto r = std::get<0>(t) ;

  static_assert(t.first =="cc","fail");
  }
  {
  constexpr FixedString s("aaaaa");
  constexpr FixedString d("cc");
  constexpr auto t =  swapTuple(s,d);
  constexpr auto r = std::get<0>(t) ;

  static_assert(r =="cc","fail");
  }

}