#include <forward_list>
#include <iostream>
int getLastNthElem(const std::forward_list<int> &f, int n)
{
  auto i = f.cbegin();
  ++n;
  for (; i != f.cend() &&n; --n,++i)
  {
  }
  auto j = f.cbegin();
  for (;i!=f.cend(); ++i, ++j)
  {
  }
  if (j!= f.cend())
  {
    return *j;
  }
  else
  {
    return -1;
  }
}
int main(int argc, char* argv[])
{
  std::forward_list<int> f;
  std::cout<<(f.before_begin()==f.begin())<<std::endl;
  f.push_front(6);
  f.push_front(5);
  f.push_front(4);
  f.push_front(3);
  f.push_front(2);
  f.push_front(1);
  std::cout<<getLastNthElem(f,0)<<std::endl;
}