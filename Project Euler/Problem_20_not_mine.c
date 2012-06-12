#include <stdio.h>
#define N 100
\\http://www.dreamincode.net/forums/topic/130630-calculating-a-large-factorial/
int main() {
  int num[1000] = {0};
  int size = 1, sum = 0;
  int i, j, tmp;
  
  num[0] = 1;
  for (i = 2; i <= N; i++) {
	for (j = 0; j < size; j++)
	  num[j] *= i;
	for (j = 0; j < size; j++) {
	  if (num[j] > 9) {
	num[j+1] += num[j] / 10;
	num[j] %= 10;
	if (j == size-1)
	  size++;
	  }
	}
  }
  for (i = 0; i < size; i++)
	sum += num[i];
  printf("%d\n", sum);
  return 0;
}

