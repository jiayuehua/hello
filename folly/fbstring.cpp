#include <folly/FBString.h>
#include <iostream>
#include <string>
#include <chrono>
#include <folly/stop_watch.h>
void fbString()
{
  folly::fbstring f("hello,world!");
  folly::fbstring fa;
  auto r = f.find_first_of("good", 6);
  std::cout<<r<<std::endl;
  std::cout<<folly::IsSomeString<folly::fbstring>::value<<std::endl;
  folly::fbstring fc(100000,'b');
  fc+= f;
  folly::stop_watch<std::chrono::nanoseconds> w;
  auto n = fc.find('d');
  auto c1 = w.lap().count();
  std::string fs(100000,'b');
  fs += f.toStdString();
  w.reset();
  auto n2 = fs.find('d');
  auto c2 = w.lap().count();
  std::cout<<"c1: "<<c1<<std::endl;
  std::cout<<"n: "<<n<<std::endl;
  std::cout<<"c2: "<<c2<<std::endl;
  std::cout<<"n2: "<<n2<<std::endl;

}
int main()
{
  fbString();
}