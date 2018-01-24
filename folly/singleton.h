#pragma once

#include <iostream>
#include <memory>
class A {
public:
  static std::shared_ptr<A> getInstance();
  A() {
    std::cout<<"construct\n";
  }
  void foo()
  {
    std::cout<<"foo\n";
  }
};
void Singleton();