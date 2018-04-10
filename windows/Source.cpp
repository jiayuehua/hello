#include <type_traits>
#include <iostream>
#include <string>
#include "typetraits.h"
namespace Test {

struct A {
  typedef int type;
};
void print(const std::string& r)
{
  std::cout << r << std::endl;
}
void typeTraits()
{
  std::cout << std::is_same_v<int, int&> << std::endl;
  int a  = 10;
  int &i = a;
  A aA;
  A & refa = aA;
  std::cout << std::is_same_v<int, decltype(i)> << std::endl;
  std::cout << std::is_same_v<int&, decltype(i)> << std::endl;
  std::cout << std::is_same_v<int, decltype(refa)> << std::endl;
}

void testfunc()
{
  DD d;


    BB b;
  BB* pb  = &d;
  A*pa    = new A;
  A*paa   = new A;
  DD* pd  = &d;
  std::cout << pb << " " << &d << std::endl;
  typeTraits();
  std::string s("world");
  print(s);
}


}
