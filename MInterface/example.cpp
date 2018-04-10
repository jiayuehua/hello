#include "pred_expr.h"
#include "pred_expr_traits.h"
#include "stl_iterator_traits.h"
#include <string>
#include <vector>
#include <iostream>
//using namespace DandS;
namespace fox = DandS;
struct PodC {

};
struct NotPodC {
  virtual void f(){}
};

//template <class T, std::enable_if_t<std::is_class_v<T>, void**> = nullptr >
//void foo(T t)
//{
//  //std::cout<<"f isPodClass\n";
//}
//template <class T, std::enable_if_t<!std::is_class_v<T>, void**> = nullptr >
//void foo(T t)
//{
//  //std::cout<<"f notPodClass\n";
//}
//template <class T,typename =  DandS::Constraint<DandS::IsPod , T>  >
//template <class T, DandS::Constraint<DandS::IsPod , T> = nullptr  >
//void foo(T t)
//{
//  std::cout<<"f isPodClass\n";
//}
//template <class T, DandS::Constraint<decltype(!DandS::isPod), T > = nullptr >
//void foo(T t)
//{
//  std::cout<<"f notPodClass\n";
//}
template <class T, fox::Constraint<fox::IsIn, T> = nullptr>
void fIter(T b, T e)
{
  for (auto i = b; i != e; ++i)
  {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
}

template <class T, bool = fox::constraint(fox::isRand)>
void fRan(T b, T e)
{
  for (auto i = b; i != e; ++i)
  {
    std::cout<<*i<<" ";
  }
  std::cout<<std::endl;
}
int main()
{
  //constexpr auto t = isPod.eval<int>();
  //constexpr auto f = isPod.eval<std::string>();
  //constexpr auto isPodClass = isPod&isClass;
  //constexpr auto tP = isPodClass.eval<PodC>();
  //constexpr auto fP = isPodClass.eval<int>();
  //constexpr auto tPP = satisfies<PodC>(isPodClass);
  //constexpr auto fPP = satisfies<PodC, int>(isPodClass);
  //PodC p;
  //foo(p);
  //NotPodC n;
  //foo(n);
  std::string s("hello,world");
  fIter(s.begin(), s.end());
  fRan(s.begin(), s.end());
  constexpr auto tRand = fox::isRand.eval<std::vector<int>::iterator >();
  constexpr auto tIn = fox::isExactlyIn.eval<std::vector<int>::iterator >();

  //foo(10);
}
