#include <folly/Benchmark.h>
#include <folly/container/Foreach.h>
#include <vector>
using namespace std;
using namespace folly;
BENCHMARK(backinsert, n)
{
  vector<int> v;
  for (int i = 0; i<n; ++i)
  {
    v.push_back (i);
  }
}

BENCHMARK_DRAW_LINE();
BENCHMARK_RELATIVE(frontinsert, n)
{
  vector<int> v;
  for (int i = 0; i<n; ++i)
  {
    v.insert (v.begin(),i);
  }
}
BENCHMARK_DRAW_LINE();

BENCHMARK_RELATIVE(reserve_pushback, n)
{
  BenchmarkSuspender s;


  vector<int> v;
  v.reserve(n);
  s.dismiss();
  int d = 0;
  for (int i = 0; i<n; ++i)
  {
    v.push_back(i);
    d+=100;
    d -= 100;
  }
  doNotOptimizeAway(d);
}
int main() {
  runBenchmarks();
}