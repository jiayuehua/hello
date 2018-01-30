#include <tuple>
#include <iostream>
template< class T, int N >
struct A {
  static void print(const T& a)
  {
    A<T, N - 1>::print(a);
    std::cout << std::get<N>(a) << " ";
  }
};

template<class T>
struct A <T, 0> {
  static void print(const T& a)
  {
    std::cout << std::get<0>(a) << " ";
  }
};

int main()
{
  std::tuple<int, int, int> t(1,2,3);

  A<std::tuple<int,int,int>,2>::print(t) ;
}