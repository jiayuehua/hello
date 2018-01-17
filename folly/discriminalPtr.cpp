#include <folly/DiscriminatedPtr.h>
#include <folly/Overload.h>
#include <iostream>
struct Visitor
{

    void operator()(const char*p )
                       {
                         std::cout<<*p<<std::endl;
                       }
    void operator()(const int*p )
                       {
                         std::cout<<*p<<std::endl;
                       }
    void operator()(const double*p )
                       {
                         std::cout<<*p<<std::endl;
                       }
};
void discriminatedptr()
{
  int a = 1;
  double d = 2.0;
  char c = '3';
  folly::DiscriminatedPtr<int,double,char> p;
  p = &a;
  auto o =
    folly::overload(
    [](const char*p )
                       {
                         std::cout<<*p<<std::endl;
                       },
    [](const int*p )
                       {
                         std::cout<<*p<<std::endl;
                       },
    [](const double*p )
                       {
                         std::cout<<*p<<std::endl;
                       }
  );
  Visitor v;
  folly::apply_visitor(v ,p);
  p = &c;
  folly::apply_visitor(v ,p);
  p = &d;
  folly::apply_visitor(o ,p);
}
int main(int argc, char* argv[])
{
  discriminatedptr();
}