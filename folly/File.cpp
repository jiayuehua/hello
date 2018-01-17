#include <folly/File.h>
#include <iostream>
#include <folly/ScopeGuard.h>
void filefunc()
{
  folly::File test("hello.txt", O_RDWR|O_CREAT|O_APPEND);
  if (test)
  {
    std::cout<<"open success !\n";
  }
  std::cout<<test.fd()<<std::endl;
  auto f2 = test.dup();
  std::cout<<f2.fd()<<std::endl;
  std::cout<<f2.closeNoThrow()<<std::endl;
  std::cout<<test.fd()<<std::endl;
  {
    auto l = folly::makeGuard([&test]{test.unlock();});
    test.lock();
    std::cout<<"sleep\n";
    sleep(15);
  }
  test.swap(f2);
  std::cout<<f2.fd()<<std::endl;
}
int main()
{
  filefunc();
}