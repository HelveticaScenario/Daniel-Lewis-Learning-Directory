#include <stdio.h>

int getFactorial(int n)
{
  int local;
  if (n > 1)
  {
    local = n * getFactorial(n - 1);
    return local;
  }
  else
    return 1;
}

int main()
{
	printf("%d\n", getFactorial(50));
	return 0;
}
