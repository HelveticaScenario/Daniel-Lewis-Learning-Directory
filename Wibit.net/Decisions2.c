#include <stdio.h>

int main()
{
	int u = 65;
	int l = 97;
	
	for(int i = l; i < (l + 26); i++)
	{	
		printf("%c -> ", i);
		for (int j = u; j < (u + 26); j++)
		{
			if (j == (u + 25))
			{
				printf("%c", j);
			}
			else
			{
				printf("%c,", j);
			}
		}
		printf("\n");
	}
	return 0;
}