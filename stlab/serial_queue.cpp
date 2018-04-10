#include <iostream>
#include <thread>
#include <string>
#include <stlab/concurrency/default_executor.hpp>
#include <stlab/concurrency/serial_queue.hpp>
using namespace std;
using namespace stlab;
stlab::serial_queue_t serialQ(default_executor);
serial_queue_t ioq(default_executor);
void say_hello(string to_whom) {
  ioq.executor()([_whom = move(to_whom)](){
    cout << "Hello, " << _whom << "!\n";
  });
}


void MyMethod()
{
  std::string s("world");
  serialQ.executor()([s = move(s)]{ std::cout << s << std::endl; });
}

int main(int, char**) {
  MyMethod();
  MyMethod();
  MyMethod();
  MyMethod();
  MyMethod();
  MyMethod();
  MyMethod();


  say_hello("fella");
  //say_hello("chief");
  //say_hello("pal");
  //say_hello("world");
//  auto done = ioq([] {});
  //while (!done.get_try()) {}
}