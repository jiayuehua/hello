
#pragma once

#include <string>
#include <iostream>
enum class E {
  One,
  Two,
  Three
};

bool foo()
{
  return false;
  return true;
}
// #Aname
struct A{
  A(){
    m_name = "hello";
  }
  void print(int){std::cout<< "hello\n";}
  void print(E a, int)
  {
    switch(a)
    {
    case E::One:
      break;
    case E::Two:
      break;
    case E::Three:
      break;
    default:
      break;
    }
  }
//private:
  std::string m_name;
};


