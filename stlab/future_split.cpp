#include <stlab/concurrency/future.hpp>
#include <stlab/concurrency/default_executor.hpp>
#include <iostream>
decltype(auto) f()
{
  std::cout<<"f 7\n";
  return 43;
}
int main()
{
  {
    auto i = stlab::async(stlab::default_executor, f);
    auto j  = i.then([](auto v ){std::cout<<v<<std::endl;});
    auto k  = i.then([](auto v ){std::cout<<(v+v)<<std::endl;});

    while (!j.get_try()||!k.get_try())
    {
      sleep(1);
    }
  }
  std::cout<<"main\n";
}