#include "I7Enum.h"
#include <tuple>
#include <iostream>
#include <string>
#include "I7Enum.h"
using namespace std::literals;

void foo()
{
  auto i = std::make_tuple(1,"hello"s, 11.1);
  auto I = static_cast<std::size_t>(Index::Zero);
  auto t = std::get<I> (i);
  std::cout << t << std::endl;
}
int main()
{
  foo();
}
