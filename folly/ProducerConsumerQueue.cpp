#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <functional>
#include <folly/ProducerConsumerQueue.h>
void foo(folly::ProducerConsumerQueue<int>& q)
{
  int v=0;
  for (;v!=-1;)
  {
    auto ptr = q.frontPtr();
    if (ptr)
    {
      std::cout<<*ptr<<std::endl;
    }
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
  folly::ProducerConsumerQueue<int> q(1000);
  std::thread r(&foo, std::ref(q));
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
  r.join();
}