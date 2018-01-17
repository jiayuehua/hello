#include <folly/Expected.h>
#include <iostream>
#include <folly/FBString.h>

void Expected()
{
  folly::fbstring f;
  folly::Expected<int,int> ex(folly::in_place, 10);
  folly::Expected<int,int> cex;
  cex.emplace(100);
  if (cex)
  {
    std::cout<<*cex<<std::endl;
    std::cout<<(*cex == 100)<<std::endl;
  }
  //ex = c;
  {
    auto ex = folly::makeExpected<folly::fbstring>(48);
    auto e2 = ex.then([](int i){std::cout<< i<<std::endl; return 3.8;}).then(
      [](double d) {
        std::cout<< d<<std::endl;
        return d;
      }
    ).then([](double d ){return folly::Expected<double, folly::fbstring>(folly::unexpected,"error");});
    std::cout<<e2.error()<<std::endl;
  }
  {
    auto ex = folly::makeExpected<folly::fbstring>(48);
    auto e2 = ex.then([](int i){std::cout<< i<<std::endl; return 3.8;}).then(
      [](double d) {
        std::cout<< d<<std::endl;
        return d;
      }
    );
  }
  {
  folly::Expected<int,folly::fbstring> ex(folly::unexpected, "hello");
  std::cout<<ex.value_or(1000)<<std::endl;
  ex.thenOrThrow(
    [](int i){std::cout<< i<<std::endl;},
    [](folly::fbstring const & e){std::cout<<e<<" about to throw!\n";}
  );

  std::cout<<ex.error();
  ex.value();
  }
}
int main()
{
  try {
      Expected();
  }
  catch (folly::fbstring&)
  {
    std::cout<<"exception\n";
  }
  catch (folly::Unexpected<folly::fbstring>::BadExpectedAccess&)
  {
    std::cout<<"folly bad expect\n";
  }
}
