#include <folly/MPMCQueue.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <functional>
template <typename T>
using MPMCQueueDynamic = folly::MPMCQueue<T,std::atomic,true> ;
void foo(MPMCQueueDynamic<int>& q)
{
  int v=0;
  for (;v!=-1;)
  {
    int r = q.read(v);
    if (r)
    {
      std::cout<<v<<std::endl;
    }
    else
    {
      //std::cout<<"failed"<<std::endl;
    }
  }
}

int main()
{
  MPMCQueueDynamic<int> q(1000);
  auto write = [&q](int i) {
    if (!q.write(i))
    {
      std::cout<<"write "<<i<<" failed"<<std::endl;
   }

  };
  write(1);
  write(3);
  write(5);
  write(2);
  write(4);
  write(6);
  write(8);
  write(9);
  write(0);
  write(11);
  write(12);
  write(13);
  std::thread r(&foo, std::ref(q));
  std::thread r1(&foo, std::ref(q));
  std::thread r2(&foo, std::ref(q));
  q.blockingWrite(-1);
  q.blockingWrite(-1);
  q.blockingWrite(-1);
  r.join();
  r1.join();
  r2.join();
}
void foo(folly::MPMCQueue<int>& q)
{
  int v=0;
  for (;v!=-1;)
  {
    int r =  q.read(v);
    if (r)
    {
      std::cout<<v<<std::endl;
    }
    else
    {
      //std::cout<<"failed"<<std::endl;
    }
  }
}

int main()
{
  folly::MPMCQueue<int> q(1000);
  std::thread r(&foo, std::ref(q));
  std::thread r1(&foo, std::ref(q));
  std::thread r2(&foo, std::ref(q));
  q.write(1);
  q.write(3);
  q.write(5);
  q.write(2);
  q.write(4);
  q.write(6);

  sleep(5);
  q.write(8);
  q.write(0);
  q.write(11);
  q.write(12);
  q.write(13);
  q.write(1);
  q.write(-1);
  q.write(-1);
  q.write(-1);
  r.join();
  r1.join();
  r2.join();
}