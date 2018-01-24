#include <folly/AtomicIntrusiveLinkedList.h>
#include <iostream>
class A {
public:
  folly::AtomicIntrusiveLinkedListHook<A> hook_;
  int data;
};
typedef folly::AtomicIntrusiveLinkedList<A, &A::hook_> AL;
void f(A* p)
{
  std::cout<<p->data<<std::endl;
}
void atomicLinkList()
{
  AL al;
  A a;
  a.data = 100;
  A b;
  b.data = 200;
  al.insertHead(&a);
  al.insertHead(&b);
  al.sweep(f);
  al.insertHead(&a);
  al.insertHead(&b);
  al.reverseSweep(f);

}

int main()
{
  atomicLinkList();
}