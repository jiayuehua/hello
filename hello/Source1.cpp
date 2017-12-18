#include <iostream>
int bad()
{
  std::cout << "hi, world!";
  for (int i = 100, j = 1999; (i = 10, (j = 1)); ++i);
  return 0;
}
