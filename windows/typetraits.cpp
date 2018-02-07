#include <type_traits>
#include <iostream>
struct A {
  typedef int type;
};
void typeTraits()
{
  std::cout<<std::is_same_v<int , int&><<std::endl;
  int a  = 10;
  int &i = a;
  A aA;
  A & refa = aA;
  std::cout<<std::is_same_v<int , decltype(i)><<std::endl;
  std::cout<<std::is_same_v<int& , decltype(i)><<std::endl;
  std::cout<<std::is_same_v<int , decltype(refa)><<std::endl;
}
int main()
{
  typeTraits();
}