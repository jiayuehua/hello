#include <folly/Conv.h>
#include <iostream>
#include <folly/Likely.h>
#include <folly/FBString.h>
void conv()
{
  try
  {
    auto r = folly::to<folly::fbstring>("hello", 1, 2.444, "boy");
    std::cout<<r<<std::endl;
    folly::StringPiece s("233 is 22");
    int i = folly::to<int>(&s);
    std::cout<<s<<std::endl;
    std::cout<<i<<std::endl;
    uint8_t can = folly::to<uint8_t> (123);
    std::cout<<"can "<<(int)can<<std::endl;
    {
      auto n = folly::tryTo<uint8_t> (323);
      n.then([](int i){std::cout<<i<<std::endl;});
      if (LIKELY(!n))
      {
        std::cout<<"conv failed\n";
      }
    }
  }
  catch (...)
  {
    std::cout<<"Exception\n";
  }
  try
  {
    int i = folly::to<double>("32.2.222");
    std::cout<<i<<std::endl;
  }
  catch (...)
  {
    std::cout<<"Exception\n";
  }
}
int main()
{
  conv();
}