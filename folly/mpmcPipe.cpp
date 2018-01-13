#include <folly/MPMCPipeline.h>
#include <folly/MPMCQueue.h>
#include <folly/Conv.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <functional>
void readPipeLine(folly::MPMCPipeline<int, std::string, int>& pipeline)
{
  int result;
  int n = 0;
  for (;n!=5;)
  {
    pipeline.blockingRead(result);
    if (result == -1)
    {
      ++n;
    }
    std::cout<<result<<std::endl;;
  }
}
void writePipeLine(folly::MPMCPipeline<int, std::string, int>& pipeline)
{
  for (int i = 0; i<2000; ++i)
  {
    pipeline.blockingWrite(i);
  }
  pipeline.blockingWrite(-1);
  pipeline.blockingWrite(-1);
  pipeline.blockingWrite(-1);
  pipeline.blockingWrite(-1);
  pipeline.blockingWrite(-1);
}
void StageA(folly::MPMCPipeline<int, std::string, int>& pipeline)
{
    int  val = 0;
    while (val != -1)
    {
      auto ticket = pipeline.blockingReadStage<0>(val);
      pipeline.blockingWriteStage<0>(ticket, folly::to<std::string>(val));
    }
}
void StageB(folly::MPMCPipeline<int, std::string, int>& pipeline)
{
    std::string  val;

    while (val != std::string("-1"))
    {
      auto ticket = pipeline.blockingReadStage<1>(val);
      int res = 0;
      try {
        res = folly::to<int>(val);
      }
      catch(...)
      { }
      pipeline.blockingWriteStage<1>(ticket, res);
    }
}
void foo()
{
  using namespace folly;
  MPMCPipeline<int, std::string, int> pipeline(5, 5, 5);
  std::thread writeThr (&writePipeLine, std::ref(pipeline));
  std::thread readThr (&readPipeLine, std::ref(pipeline));

  std::vector<std::thread> vThrA;
  std::vector<std::thread> vThrB;
  for (int i = 0; i<5; ++i)
  {
    vThrA.emplace_back(&StageA, std::ref(pipeline));
  }

  for (int i = 0; i<5; ++i)
  {
    vThrB.emplace_back(&StageB, std::ref(pipeline));
  }

  for (int i = 0; i<5; ++i)
  {
    vThrA[i].join();
  }

  for (int i = 0; i<5; ++i)
  {
    vThrB[i].join();
  }
  readThr.join();
  writeThr.join();
  // result == 42
}

int main()
{
  foo();
}
