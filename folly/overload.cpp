#include <iostream>
#include <folly/Overload.h>
#include <folly/ConstexprMath.h>
#include <boost/variant.hpp>

void variant_overload()
{
  boost::variant<int,double> v;
  v = 10;
  folly::variant_match(v,
                       [](int i) { std::cout << i << std::endl; },
                       [](double d) { std::cout<< d<<std::endl;}
  );
  v = 7.8;
  folly::variant_match(v,
                       [](int i) { std::cout << i << std::endl; },
                       [](double d) { std::cout<< d<<std::endl;}
  );
}
