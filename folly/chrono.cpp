#include <folly/Chrono.h>
#include <chrono>
#include <iostream>
void chrono()
{
  using namespace std::chrono_literals;
  auto n = folly::chrono::ceil<std::chrono::minutes>(30s);
  std::cout <<n.count()<<std::endl;
  n = folly::chrono::floor<std::chrono::minutes>(30s);
  std::cout <<n.count()<<std::endl;
  n = folly::chrono::round<std::chrono::minutes>(31s);
  std::cout <<n.count()<<std::endl;
  n = folly::chrono::round<std::chrono::minutes>(10s);
  std::cout <<n.count()<<std::endl;
  n = folly::chrono::round<std::chrono::minutes>(50s);
  std::cout <<n.count()<<std::endl;

}
int main()
{
  chrono();
}