#include <iostream>
#include <folly/Singleton.h>
#include "singleton.h"
namespace {
  struct PrivateTag{};
}
static folly::Singleton<A, PrivateTag> the_singleton;
std::shared_ptr<A>
A::getInstance()
{
  return the_singleton.try_get();
}


void Singleton()
{
  auto a = A::getInstance();
  a->foo();


}
