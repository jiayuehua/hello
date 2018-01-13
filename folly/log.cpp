#include <iostream>
#include <folly/Logging.h>

void log()
{
  for (;;)
  {
    FB_LOG_EVERY_MS(INFO, 1000)<<"hello,world\n";
  }
}
int main()
{

  log();
}