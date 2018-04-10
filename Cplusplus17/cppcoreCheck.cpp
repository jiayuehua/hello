
int main()
{
  int arr[10];           // warning C26494
  int* p = arr;          // warning C26485

  //[[gsl::suppress(bounds.1)]] // This attribute suppresses Bounds rule #1
    {
      int* q = p + 1;    // warning C26481 (suppressed)
    p = q++;           // warning C26481 (suppressed)
    }

    return 0;
}
