#include <iostream>
#include <exception>
#include <folly/ExceptionWrapper.h>
folly::exception_wrapper  globalExceptionWrapper;
class BasicException {

};
class DerivedException:public BasicException {

};
void foo2()
{
  std::out_of_range b("outofrange");
  folly::exception_wrapper e(b);

  e.handle(
    [&](std::out_of_range&)
    {
      std::cout<<"out_of_range\n"<<std::endl;
    }
  );
  e.with_exception([](std::out_of_range& o) {
    std::cout<<"out of range\n";
                   });

    if (e)
    {
      std::cout<<"A2 e has exception\n";
    }
    if (e.has_exception_ptr())
    {
      std::cout<<"A2 e has exception ptr\n";
    }
    e.to_exception_ptr();
    if (e)
    {
      std::cout<<"B2 e has exception\n";
    }
    if (e.has_exception_ptr())
    {
      std::cout<<"B2 e has exception ptr\n";
    }
}
void foo()
{
  BasicException b;
  folly::exception_wrapper e(folly::in_place,b);

    if (e)
    {
      std::cout<<"A e has exception\n";
    }
    if (e.has_exception_ptr())
    {
      std::cout<<"A e has exception ptr\n";
    }
    e.to_exception_ptr();
    if (e)
    {
      std::cout<<"B e has exception\n";
    }
    if (e.has_exception_ptr())
    {
      std::cout<<"B e has exception ptr\n";
    }
}
void F(int n)
{
  using namespace folly;
  if (n == 0)
  {
    globalExceptionWrapper = exception_wrapper();
  }
  else if (n == 1)
  {
    globalExceptionWrapper = make_exception_wrapper<BasicException>();
  }
  else if (n == 2)
  {
    globalExceptionWrapper = make_exception_wrapper<DerivedException>();
  }
}
void ProcessResult()
{
  try {
    if (!globalExceptionWrapper)
    {
      std::cout<<"No exception\n";
    }
    if (globalExceptionWrapper.has_exception_ptr())
    {
      std::cout<<"has exception ptr\n";
    }
    globalExceptionWrapper.throw_exception();
  }
  catch (DerivedException&)
  {
    std::cout<<"Devired Exception\n"<<std::endl;
  }
  catch (BasicException&)
  {
    std::cout<<"Basic Exception\n"<<std::endl;
  }
}
void ProcessResult_handle()
{
  try{

  globalExceptionWrapper.handle(
    [&](std::string &)
    {}

    //[&](DerivedException&)
    //{
    //  std::cout<<"Devired Exception\n"<<std::endl;
    //},
    //[&](BasicException&)
    //{
    //  std::cout<<"Basic Exception\n"<<std::endl;
    //},
    //  [](...) {
    //  std::cerr<<"unknown error\n";
    //}
  );
  }
  catch (...)
  {
    std::cout<<"catch exception\n";

  }
}

void f()
{
  std::cout<<"hello f\n";
  throw std::out_of_range("out of range ffff\n");
}
int main()
{
/*  F(0);
  ProcessResult();
  ProcessResult_handle()*/;
  foo();
  foo2();
  F(1);
  ProcessResult();
  ProcessResult_handle();
  F(2);
  ProcessResult();
  ProcessResult_handle();
  auto e = folly::try_and_catch<std::exception, std::out_of_range>(&f);
  if (e)
  {
    e.handle([](std::out_of_range& e){std::cout<<"main out range\n";});
  }
}