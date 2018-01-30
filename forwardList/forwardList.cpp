#include <iostream>
#include <forward_list>
//12345678 => //13578642
void foo()
{
  std::forward_list<int> f;
  std::forward_list<int> t;
  auto i =  f.before_begin();
  for (int t = 1; t < 10; ++t)
  {
    i = f.insert_after(i,t);
  }
  auto j = f.begin();
  i = j++;
  while (i != f.end()&&j != f.end())
  {
    t.splice_after(t.before_begin(),f, i);
    auto ia = i++;
    if (i == f.end())
    {
      i = ia;
      break;
    }
    j = i;
    if (j!=f.end())
    {
      ++j;
    }
    else {
      break;
    }
  }
  f.splice_after(i,t);
  for ( auto i : f)
  {
    std::cout<<i<<std::endl;
  }
}
int main()
{
  foo();
}