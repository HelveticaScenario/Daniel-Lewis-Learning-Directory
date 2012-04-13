#include <stdio.h>

int main()
{
	int i;
	long end = 0;
	for(i=0; i < 1000; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0)) end += i;
	}
	printf("%d\n", end);
	return 0;
}