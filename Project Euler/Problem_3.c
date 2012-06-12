/*
"The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?"
http://projecteuler.net/problem=3
*/

#include <stdio.h>

int main()
{
	
	
	long long num;
	printf("Enter an integer and I'll spit out it's prime factors: ");
	scanf("%255lld", &num);
//	int primes[255];
	long long i = 2;
//	int j;
	long long newNum = num;
/*	for(j = 0; j <= sizeof(primes); j++)
	{
		primes[j] = 0;
	}
	j = 0;
*/
	while(newNum != 1)
	{
		if(newNum % i == 0)
		{
//			primes[j] = i;
			printf("%lld\n",i);
			newNum = newNum / i;
//			j++;
		}
		else
		{
			i++;
		}
	}
//	for(j=0; primes[j] != 0; j++)
//		printf("d%\n",primes[j]);
	char c;
	printf("Press enter to exit\n");
	scanf("%*2c", &c);

	return 0;
}