#include <iostream>
#include <utility>
class A{
public:
  A(){ std::cout<<"Construct\n";};
  A(const A & ){ std::cout<<"Copy Construct\n";};
  A(A&& ){ std::cout<<"Move Construct\n";};
  A& operator = (const A&){ std::cout<<"copy assign\n"; return *this;};
  A& operator= (A&&){ std::cout<<"move Assign\n"; return *this;};
  ~A(){ std::cout<<"deconstructor \n";};
};
A foo()
{
  A a;
  return a;
}
int main()
{
  foo();
  {
    std::cout<<"move\n";
    A a;
    A&& rm = std::move(a);
    A&rf = std::forward<A&>(a);
  }
}
