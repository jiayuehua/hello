#include <folly/Function.h>
#include <iostream>
#include <functional>
struct FuncA {
  void operator()(int )const {
    std::cout<<"FuncA const int\n";
  }
  void operator()(int ) {
    std::cout<<"FuncA not const int\n";
  }
};
struct FuncC {
  FuncC()=default;
  FuncC(const FuncC&) = delete;
  FuncC&operator= (const FuncC&) = delete;
  FuncC(FuncC&&) = default;
  FuncC&operator= ( FuncC&&) = default;
  //~FuncC()=default;
  void operator()(int )const {
    std::cout<<"FuncC const int\n";
  }
};
struct FuncD {
  void operator()(int ) {
    std::cout<<"FuncD not const int\n";
  }
};
struct CallConstFunction{
  template<class... TA>
  void normalCall(TA&&... args)
  {
    t(std::forward<TA>(args)...);
  }

  template<class... TA>
  void constCall(TA&&... args)const
  {
    t(std::forward<TA>(args)...);
  }
  folly::Function<void(int)const> t;
};
struct CallFunction{
  template<class... TA>
  void normalCall(TA&&... args)
  {
    t(std::forward<TA>(args)...);
  }

  template<class... TA>
  void constCall(TA&&... args)const
  {
    t(std::forward<TA>(args)...);
  }
  folly::Function<void(int)> t;
};
int main()
{
  FuncA fa;
  folly::Function<void(int)> faf(fa);
  faf(3);
  FuncC fc;
  folly::Function<void(int)const> fcfc(std::move(fc));
  fcfc(3);
  folly::Function<void(int)> fcf(std::move(fc));
  fcf(3);
  FuncD fd;
  folly::Function<void(int)> fdf(fd);
  fdf(3);
  CallFunction fcCallFunction{std::move(fcf)};
  fcCallFunction.normalCall(3);
  //fcCallFunction.constCall(3);

  CallConstFunction fcConstCallFunction{std::move(fcfc)};
  fcConstCallFunction.normalCall(3);
  fcConstCallFunction.constCall(3);
}