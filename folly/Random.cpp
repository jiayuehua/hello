#include <folly/Random.h>
#include <iostream>
#include <random>
void randomFunc()
{
  //std::mt19937 d;
  //std::cout<<d()<<std::endl;
  //std::default_random_engine dre2;
  //std::cout<<dre2()<<std::endl;
  //std::uniform_int_distribution<int> di(10,20);
  //for (int i = 0; i<5; ++i )
  //{
  //  std::cout<<di(d)<<std::endl;
  //}

  using R = folly::Random ;
  //auto d = folly::Random::create();
  R::DefaultGenerator d;
  //folly::ThreadLocalPRNG d;
  //R::seed(d);
  //std::cout<<d()<<std::endl;
  //std::cout<<d()<<std::endl;
  //std::cout<<d()<<std::endl;
  //std::cout<<d()<<std::endl;
  for (int i = 0; i < 2; ++i)
  {
    std::cout << R::rand32(d) << std::endl;
    std::cout << R::rand32(4, 9, d) << std::endl;
    std::cout << R::rand32(9, d) << std::endl;
    std::cout << R::oneIn(9, d) << std::endl;
    std::cout << " ========\n";
  }
  //R::seed(d2);
  //std::cout<<d()<<std::endl;
  //std::cout<<d()<<std::endl;
  //std::cout<<d()<<std::endl;
  //std::cout<<d()<<std::endl;
  for (int i = 0; i<2; ++i)
  {
    std::cout<<R::secureRand32()<<std::endl;
    std::cout<<R::secureRand32(4,9)<<std::endl;
    std::cout<<R::secureRand32(9)<<std::endl;
    std::cout<<R::secureOneIn(9)<<std::endl;
    std::cout<<" ========\n";
  }
}
int main()
{
  randomFunc();
  randomFunc();
}