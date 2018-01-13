#include <folly/AtomicLinkedList.h>
#include <iostream>

void atomicLinkList()
{
  //l 321
  folly::AtomicLinkedList<int> l;

  l.insertHead(1);
  l.insertHead(2);
  l.insertHead(3);
  l.sweep([](auto &&h ){
    std::cout <<h<<std::endl;
          }
  );//1 2 3
//321
  l.insertHead(1);
  l.insertHead(2);
  l.insertHead(3);
  l.reverseSweep([](auto &&h ){
    std::cout <<h<<std::endl;
          }
  );


}
//int main(int argc, char* argv[])
//{
//  atomicLinkList();
//}