#include <folly/PriorityMPMCQueue.h>
#include <iostream>
#include <thread>
#include <functional>
#include <folly/Synchronized.h>
folly::Synchronized<int> s;
void priorityMPMCQueue(folly::PriorityMPMCQueue<int>& q)
{
  int r = 0;
  while (r!=-1)
  {
    s.withWLock([&](auto & integerT) {
      if (q.read(r))
      {
        std::cout << std::this_thread::get_id() << ":";
        std::cout << r << std::endl;
      }
                });
    std::this_thread::yield();
  }
}

void foo()
{
  folly::PriorityMPMCQueue<int> q(5,40);

  auto writeWithPriority = [&q](int i, int j) {
    if (!q.writeWithPriority(std::move(i),j))
    {
      std::cout<<i<<","<<j<<" failed\n";
    }
  };
  auto writeSuccess = [&q](int i, int j) {
    while (!q.writeWithPriority(std::move(i),j))
    {
    }
  };
  writeWithPriority(1,0);
  writeWithPriority(1,0);
  writeWithPriority(3,2);
  writeWithPriority(3,2);
  writeWithPriority(5,1);
  writeWithPriority(5,1);
  writeWithPriority(5,1);
  writeWithPriority(7,3);
  writeWithPriority(7,3);
  writeWithPriority(7,3);
  writeWithPriority(8,4);
  writeWithPriority(8,4);
  writeWithPriority(8,4);
  std::thread ta(&priorityMPMCQueue,std::ref(q));
  std::thread tb(&priorityMPMCQueue,std::ref(q));
  std::thread tc(&priorityMPMCQueue,std::ref(q));
  writeWithPriority(3,2);
  writeWithPriority(3,2);
  writeWithPriority(5,1);
  writeWithPriority(5,1);
  writeWithPriority(5,1);
  writeWithPriority(7,3);
  writeWithPriority(7,3);
  writeWithPriority(7,3);
  writeWithPriority(8,4);
  writeWithPriority(3,2);
  writeWithPriority(3,2);
  writeWithPriority(5,1);
  writeWithPriority(5,1);
  writeWithPriority(5,1);
  writeWithPriority(7,3);
  writeWithPriority(7,3);
  writeWithPriority(7,3);
  writeWithPriority(8,4);
  writeWithPriority(8,4);
  writeWithPriority(8,4);
  writeSuccess(-1,4);
  writeSuccess(-1,4);
  writeSuccess(-1,4);
  ta.join();
  tb.join();
  tc.join();
}
int main()
{
  foo();
}