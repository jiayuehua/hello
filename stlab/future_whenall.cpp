#include <stlab/concurrency/future.hpp>
#include <stlab/concurrency/default_executor.hpp>
#include <iostream>
#include "future_whenall.h"
namespace stlab {
 /* auto asyncF = [](auto&&... a)
  {
    return stlab::async(stlab::default_executor, std::forward<decltype(a)>...);
  };*/
  /*auto whenAll = [](auto&&... a)
  {
    return stlab::when_all(stlab::default_executor, std::forward<decltype(a)>...);
  };*/
  /*auto whenAny = [](auto&&... a)
  {
    return stlab::when_any(stlab::default_executor, std::forward<decltype(a)>...);
  };*/
}
decltype(auto) f()
{
  std::cout<<"f 7\n";
  return 43;
}
int main()
{
  {
    auto i = stlab::async(stlab::default_executor, f);
    auto j  = i.then([](auto v ){std::cout<<v<<std::endl;return v;});
    auto k  = i.then([](auto v ){std::cout<<(v+v)<<std::endl;return v+v;});
    auto r = stlab::whenAll( [](auto l, auto r)
                             {
                               std::cout<<"when_all: "<<l <<" "<<r<<std::endl;
                             },j,k

    );

    while (!r.get_try())
    {
      sleep(1);
    }
    auto ra = stlab::whenAny( [](auto l, auto index)
                             {
                               std::cout<<"when_any: "<<l <<std::endl;
                               std::cout<<"index: "<<index <<std::endl;
                             },j,k

    );
    while (!ra.get_try())
    {
      sleep(1);
    }
  }
  std::cout<<"main\n";
}