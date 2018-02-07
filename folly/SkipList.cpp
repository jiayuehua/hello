#include <folly/ConcurrentSkipList.h>
#include <iostream>
#include <memory>
#include <thread>
  using namespace folly;
  using namespace std;
  auto init_head_height=5;
  typedef ConcurrentSkipList<int> SkipListT;
shared_ptr<SkipListT> sl(SkipListT::createInstance(init_head_height) );
void readSkipList()
{
  sleep(1);
    SkipListT::Accessor accessor(sl);
    for (auto &elem : accessor) {
      std::cout<<elem<<std::endl;
    }
}
void skipList(int n)
{
  {
    // It's usually good practice to hold an accessor only during
    // its necessary life cycle (but not in a tight loop as
    // Accessor creation incurs ref-counting overhead).
    //
    // Holding it longer delays garbage-collecting the deleted
    // nodes in the list.

    SkipListT::Accessor accessor(sl);
    for (int i = n; i < n+10000; ++i)
    {
      accessor.insert(i);
      if (i % 10 == 0)
      {
        accessor.erase(i);
      }
    }

    //for (auto &elem : accessor) {
    //  std::cout<<elem<<std::endl;
    //  // use elem to access data
    //}
  }
  /* {
     SkipListT::Accessor accessor(sl);
     SkipListT::Skipper s(accessor);
     s.to(23);
     while (s.good())
     {
     std::cout<<*s<<std::endl;
     ++s;
     }
   }*/
}
int main()
{
  std::thread ta(skipList,0);
  std::thread tb(skipList,22000);
  std::thread tc(readSkipList );
  ta.join();
  tb.join();
  tc.join();
  readSkipList();


}