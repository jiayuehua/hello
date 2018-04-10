#pragma once

#include <stlab/concurrency/future.hpp>
#include <stlab/concurrency/default_executor.hpp>

namespace stlab {
  struct AsyncS {
    template<class... A>
    auto operator()(A&&... a)const ->decltype(auto)
    {
      return stlab::async(stlab::default_executor,std::forward<A>(a)...);
    }
  };
  static constexpr AsyncS Async;
  struct WhenAny {
    template<class... A>
    auto operator()(A&&... a)const ->decltype(auto)
    {
      return stlab::when_any(stlab::default_executor,std::forward<A>(a)...);
    }
  };
  static constexpr WhenAny whenAny;
  struct WhenAll {
    template<class... A>
    auto operator()(A&&... a)const ->decltype(auto)
    {
      return stlab::when_all(stlab::default_executor,std::forward<A>(a)...);
    }
  };
  static constexpr WhenAll whenAll;
}
