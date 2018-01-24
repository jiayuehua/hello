#include "singleton.h"
#include <folly/Singleton.h>
int main()
{
  auto & v = *folly::SingletonVault::singleton();
  v.registrationComplete();
  Singleton();
}