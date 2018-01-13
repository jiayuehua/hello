#include <folly/small_vector.h>
#include <folly/io/async/EventBase.h>
#include <iostream>
#include <cstdint>
#include <fox/thread.hpp>

void event_base_test()
{
  folly::EventBase base;
  fox::Thread t([&base] {
    base.loopForever();
              });
  base.runInEventBaseThread([]{std::cout<<"hello, world!:";
                   std::cout<<std::this_thread::get_id()<<std::endl;
                 });
  std::cout<<std::this_thread::get_id()<<std::endl;
  base.terminateLoopSoon();
}

int main()
{
  event_base_test();
  //small_vector_test();
}