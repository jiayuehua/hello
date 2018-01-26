#include <folly/Range.h>
#include <folly/FBString.h>
#include <iostream>
#include <string>
#include <set>
#include <functional>
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>
void isSomeString()
{
  std::cout<<"isSomeString"<<std::endl;
  std::cout<<folly::IsSomeString<int>::value<<std::endl;
  std::cout<<folly::IsSomeString<std::string>::value<<std::endl;
}
void qfind()
{
  std::cout<<"qfind"<<std::endl;
  folly::StringPiece spl("hello,world");
  std::cout<<spl.walk_size()<<std::endl;
  folly::StringPiece spr("ll");
  std::cout<<spr.walk_size()<<std::endl;
  char a[] = "hello,world";
  std::vector<char> v(a,a+11);
  auto l = folly::range(v);
  auto r = folly::range(l.begin()+2, l.begin()+4);
  std::cout<<l.walk_size()<<std::endl;
  std::cout<<r.walk_size()<<std::endl;
  std::cout<<folly::qfind(l,r)<<std::endl;
  std::cout<<folly::qfind(spl,spr)<<std::endl;
}

void qfind2()
{
  std::cout<<"qfind2"<<std::endl;
  auto l = folly::range("hello,world");
  std::cout<<folly::qfind(l,'l')<<std::endl;
}

void rfind()
{
  std::cout<<"rfind"<<std::endl;
  auto l = folly::range("hello,world");
  std::cout<<folly::rfind(l,'l')<<std::endl;
}
void qfind_first_of()
{
  std::cout<<"rfind"<<std::endl;
  auto l = folly::range("hello,world");
  auto boy = folly::range("boy");
  auto cat = folly::range("cat");
  std::cout<<folly::qfind_first_of(l,boy)<<std::endl;
  std::cout<<folly::qfind_first_of(l, cat)<<std::endl;
}

void construct()
{
  std::vector<int> result{1,2,3,4};
  char pc[] = "hello, world\n";
  folly::Range<char*> cr(pc);
  folly::Range<const char*> ccr("hello");
  //folly::Range<char*> strR(std::string("hello"));
  folly::Range<const char*> strR(std::string("hello"));
  std::string h("hello");
  folly::StringPiece sp(h, 2, 3);
  folly::MutableByteRange mbra(cr);
  folly::ByteRange bra(cr);
  folly::ByteRange brb(mbra);

  folly::Range<std::vector<int>::const_iterator>  rV(result.cbegin(), result.cend());
  std::array<char, 4> ac;
  folly::MutableStringPiece msp(ac);
}
void basicFuncRange()
{
  char a[] = "20001999";
  folly::MutableStringPiece s(a);
  s.clear();
  std::cout<<s.size()<<std::endl;
  s.reset(a, folly::constexpr_strlen(a));
  std::cout<<s.size()<<std::endl;
  std::cout<<s.walk_size()<<std::endl;;
  std::cout<<s.empty()<<std::endl;
  for (auto i = s.cbegin(); i!= s.cend(); ++i)
  {
    std::cout<<i<<std::endl;
  }
  std::cout<<s.front()<<std::endl;
  s.front() = 'b';
  std::cout<<s.front()<<std::endl;
  std::cout<<s.back()<<std::endl;
  std::cout<<s.to<folly::fbstring>()<<std::endl;
}
void utilityRange()
{
  char a[] = "hello, world once upon a ti";
  folly::MutableStringPiece m(a);
  folly::MutableStringPiece n(m.begin(),m.begin()+5);
  folly::StringPiece sp(m.subpiece(5,5));
  auto ca = m.castToConst();
  std::cout<<std::endl;
  std::cout<<m.compare(sp)<<std::endl;
  std::cout<<m.compare(sp)<<std::endl;
  return;
  std::cout<<"line: " <<__LINE__<<std::endl;
  m[4]='b';
  std::cout<<m[4]<<std::endl;
  m.advance(2);
  m.subtract(2);
  std::cout<<m.subpiece(2,4)<<std::endl;
  m.pop_front();
  m.pop_front();
  m.pop_back();
  m.pop_back();
  std::cout<<m<<std::endl;
  std::cout<<m.find(sp)<<std::endl;
  std::cout<<m.find("one man")<<std::endl;
  std::cout<<m.find('r')<<std::endl;
  std::cout<<m.find("once",8  )<<std::endl;
  std::cout<<m.find('o',8  )<<std::endl;
  std::cout<<m.find("once",16,2  )<<std::endl;
  std::cout<<m.rfind('r')<<std::endl;
  std::cout<<"line: " <<__LINE__<<std::endl;

  std::cout<<m.find_first_of(sp)<<std::endl;
  std::cout<<m.find_first_of(sp,2)<<std::endl;
  std::cout<<m.find_first_of("one man")<<std::endl;
  std::cout<<m.find_first_of("once",8  )<<std::endl;
  std::cout<<m.find_first_of("once",16,2  )<<std::endl;
  std::cout<<m.find_first_of('r')<<std::endl;
  std::cout<<m.find_first_of('o',8  )<<std::endl;
  std::cout<<m.contains(n)<<std::endl;
  m.swap(n);
  std::cout<<m<<std::endl;
  m.swap(n);
  m.startsWith(n);
  std::cout<<"line: " <<__LINE__<<std::endl;
  std::cout<<m.equals(n, std::equal_to<>())<<std::endl;
  std::cout<<m.endsWith(n)<<std::endl;
  m.replaceAt(7, "earth");
  std::cout<<m<<std::endl;
  while (!m.empty())
  {
    std::cout<<m.split_step(' ')<<std::endl;
  }
  auto f = [](folly::MutableStringPiece l, std::string const & r)
  {
    std::cout<<l<<" "<<r<<std::endl;
  };
  std::cout<<"line: " <<__LINE__<<std::endl;
  m .reset(a, folly::constexpr_strlen(a));
  m.erase(m.begin(),m.begin()+5);

  while (!m.empty())
  {
    m.split_step(' ',f, "hello");
  }
  std::cout<<"line: " <<__LINE__<<std::endl;
  //ca.front()='b';
}

void RandomRange()
{
  std::vector<int> v{0,1,2,3,4,5};
  std::set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  folly::Range<std::vector<int>::iterator > r(v.begin(), v.end());
  folly::Range<std::set<int>::iterator > sr(s.begin(), s.end());
  std::vector<int> result(3);
  boost::range::copy(sr, result.begin());
  //folly::Range<std::vector<int>::const_iterator>  rV2(result);
}
int main()
{
  //isSomeString();
  //qfind();
  //qfind2();
  //rfind();
  //basicFuncRange();
  //construct();
  utilityRange();

}