#include <boost/poly_collection/base_collection.hpp>
#include <iostream>
struct B {
  virtual void print()const
  {
    std::cout<<"B print\n";
  }
};
struct D:public B {
  virtual void print()const
  {
    std::cout<<"Derived print\n";
  }
};
void polyCollection()
{
  boost::base_colction<B> b;
  b.insert(B());
  b.insert(B());
  b.insert(D());
  for (const auto& i : b)
  {
    i.print();
  }
}
int main()
{
  polyCllection();
}
