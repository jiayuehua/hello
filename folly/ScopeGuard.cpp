#include <folly/ScopeGuard.h>
#include <vector>
#include <iostream>
void scopeGuard(std::vector<int> &v)
{
  try{
    folly::ScopeGuard g = folly::makeGuard([&v]{v.pop_back();});
    v.push_back(5);
    g.dismiss();
    //throw 1;
  }
  catch(...){
    std::cout<<"Exception!\n";
  }
}
int main()
{
  std::vector<int> v;
  scopeGuard(v);
  std::cout<<v.size()<<std::endl;
}