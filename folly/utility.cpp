#include <folly/Utility.h>
#include <utility>
#include <iostream>
#include <type_traits>
#include <memory>
template <typename T>
typename std::decay<T>::type copy(T&& value) noexcept(
    noexcept(typename std::decay<T>::type(std::forward<T>(value)))) {
  return std::forward<T>(value);
}
class A{
public:
  A(){ std::cout<<"Construct\n";};
  A(const A & ){ std::cout<<"Copy Construct\n";};
  A(const A&& ){ std::cout<<"Move Construct\n";};
  A& operator = (const A&){ std::cout<<"copy assign\n"; return *this;};
  A& operator= (A&&){ std::cout<<"move Assign\n"; return *this;};
  ~A(){ std::cout<<"deconstructor \n";};
};
A foo(A&a)
{
  return a;
}

void utility()
{
  {
    std::cout<<"first\n";
  A a;
  folly::copy(std::move(a));//move construct
  }
  {
    std::cout<<"second\n";
  A a;
  folly::copy(a);//move construct
  }
  {
    std::cout<<"third\n";
  A a;
  foo(a);//move construct
  }
  {

    std::cout<<"fourth\n";
  A a;
  A b(folly::copy(a));

  }
  {

    std::cout<<"fifth\n";
    //std::move(a);
  A a;
  A b(folly::copy(a));

  }
}

int main()
{

  //utility();


  //auto&& y = folly::Identity()(std::make_unique<int>(42));
  std::unique_ptr<int> p(new int(42));

  auto&& y = std::move(p);
  std::cout << *y << std::endl;
}
