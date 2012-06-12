#include <stdio.h>
#include <math.h>

int main()
{
	
	
	
	int i, sum=0, digit;
	for(i=0; i<10; i++)
	{
	digit = (int)(12345/(pow(10,(double) i)))%10;
	sum += digit;
	}
	printf("%d\n", sum);
	return 0;
}