#include <folly/Synchronized.h>
#include <utility>
#include <functional>
#include <vector>
#include <thread>
#include <iostream>

void foo(folly::Synchronized<std::vector<int>> &s, int b)
{
  auto l = s.wlock();
  for (int i = b; i < b + 10; ++i)
  {
    std::cout << i << std::endl;
    sleep(1);
    l->push_back(i);
  }
}

void f(folly::Synchronized<std::vector<int>>& s, int b)
{
  s.withWLock([&b](auto & v){

    for (int i = b; i<b+10; ++i)
    {
      std::cout<<i<<std::endl;
      sleep(1);
      v.push_back(i);
    }
              });

}

void synchronize()
{
  folly::Synchronized<std::vector<int>> s;
  using namespace std;
  vector<int> v;
  {
    std::thread t1(f, std::ref(s), 0);
    std::thread t2(f, std::ref(s), 100);
    t1.join();
    t2.join();
  }
  for (const auto & i : *s.rlock())
  {
    std::cout<<i<<std::endl;
  }

}
int main()
{
  synchronize();
}
