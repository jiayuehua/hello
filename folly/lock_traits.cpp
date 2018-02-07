#include <folly/LockTraits.h>
#include <folly/LockTraitsBoost.h>
#include <boost/thread.hpp>
#include <boost/thread/null_mutex.hpp>
#include <iostream>
#include <thread>
#include <functional>
template <class Policy>
struct F {
  template<class Mutex>
  void operator()(Mutex&m, int &n)
  {

    Policy::lock(m);
    for (int i = 0; i < 60000; ++i)
    {
      ++n;
    }
    Policy::unlock(m);
  }
};
template< class Policy, class Mutex>
void foo(Mutex&m, int& n)
{
  Policy::lock(m);
  for (int i =0; i<60000; ++i)
  {
    ++n;
  }
  Policy::unlock(m);
}

void lockTraits()
{
  folly::LockTraits<boost::mutex> m;
  std::cout<<"mutex"<<std::endl;
  std::cout<<folly::LockTraits<boost::mutex>::is_shared<<std::endl;
  std::cout<<folly::LockTraits<boost::mutex>::is_timed<<std::endl;
  std::cout<<folly::LockTraits<boost::mutex>::is_upgrade<<std::endl;
  std::cout<<"recursive_mutex"<<std::endl;
  std::cout<<folly::LockTraits<boost::recursive_mutex>::is_shared<<std::endl;
  std::cout<<folly::LockTraits<boost::recursive_mutex>::is_timed<<std::endl;
  std::cout<<folly::LockTraits<boost::recursive_mutex>::is_upgrade<<std::endl;
  std::cout<<"recursive_timed_mutex"<<std::endl;
  std::cout<<folly::LockTraits<boost::recursive_timed_mutex>::is_shared<<std::endl;
  std::cout<<folly::LockTraits<boost::recursive_timed_mutex>::is_timed<<std::endl;
  std::cout<<folly::LockTraits<boost::recursive_timed_mutex>::is_upgrade<<std::endl;
  std::cout<<"timed_mutex"<<std::endl;
  std::cout<<folly::LockTraits<boost::timed_mutex>::is_shared<<std::endl;
  std::cout<<folly::LockTraits<boost::timed_mutex>::is_timed<<std::endl;
  std::cout<<folly::LockTraits<boost::timed_mutex>::is_upgrade<<std::endl;
  std::cout<<"shared_mutex"<<std::endl;
  std::cout<<folly::LockTraits<boost::shared_mutex>::is_shared<<std::endl;
  std::cout<<folly::LockTraits<boost::shared_mutex>::is_timed<<std::endl;
  std::cout<<folly::LockTraits<boost::shared_mutex>::is_upgrade<<std::endl;
  std::cout<<"upgrade_mutex"<<std::endl;
  std::cout<<folly::LockTraits<boost::upgrade_mutex>::is_shared<<std::endl;
  std::cout<<folly::LockTraits<boost::upgrade_mutex>::is_timed<<std::endl;
  std::cout<<folly::LockTraits<boost::upgrade_mutex>::is_upgrade<<std::endl;
  std::cout<<"null_mutex"<<std::endl;
  std::cout<<folly::LockTraits<boost::null_mutex>::is_shared<<std::endl;
  std::cout<<folly::LockTraits<boost::null_mutex>::is_timed<<std::endl;
  std::cout<<folly::LockTraits<boost::null_mutex>::is_upgrade<<std::endl;
}
int main()
{
  {
    boost::mutex m;
    int n = 0;
    F<folly::LockPolicyExclusive> f;
    std::thread ta(f, std::ref(m), std::ref(n));
    std::thread tb(f, std::ref(m), std::ref(n));
    ta.join();
    tb.join();
    std::cout << n << std::endl;
  }

  {
    boost::null_mutex m;
    int n = 0;
    F<folly::LockPolicyExclusive> f;
    std::thread ta(f, std::ref(m), std::ref(n));
    std::thread tb(f, std::ref(m), std::ref(n));
    ta.join();
    tb.join();
    std::cout << n << std::endl;
  }
  {
    boost::shared_mutex m;
    int n = 0;
    F<folly::LockPolicyShared> f;
    std::thread ta(f, std::ref(m), std::ref(n));
    std::thread tb(f, std::ref(m), std::ref(n));
    ta.join();
    tb.join();
    std::cout << n << std::endl;
  }
  //lockTraits();
}