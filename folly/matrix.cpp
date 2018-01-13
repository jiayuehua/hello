#include <iostream>
void matrix()
{
  constexpr int M=5,N=3;
  int a[M][N];
  int k = -1;
  for (int i = 0;i<M; ++i)
  {
    for (int j = 0; j<N;++j)
    {
      a[i][j]=++k;
    }
  }
  for (int i = 0;i<M; ++i)
  {
    for (int j = 0; j<N;++j)
    {
      std::cout<<a[i][j]<<" ";
    }
    std::cout<<"\n";
  }
  for (int l = 0; l<M+N-1; ++l)
  {
    if (l % 2 == 0)
    {
      for (int i = 0; i <= l; ++i)
      {
        if (i >= 0 &&
            i < M &&
            (l - i) >= 0 &&
            (l - i) < N
            )
        {
          {
            std::cout << i << "," << l - i << ":" << a[i][l - i] << std::endl;
          }
        }
      }
    }
    else
    {
      for (int i = l; i >= 0; --i)
      {
        if (i >= 0 &&
            i < M &&
            (l - i) >= 0 &&
            (l - i) < N
            )
        {
          {
            std::cout << i << "," << l - i << ":" << a[i][l - i] << std::endl;
          }
        }
      }
    }
  }
}
int main(int argc, char* argv[])
{
  matrix();
}