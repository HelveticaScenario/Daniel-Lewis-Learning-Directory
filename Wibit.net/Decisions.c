#include <stdio.h>

int main()
{
	int x = 9;
	int y = 6;
	char c = 'h';
	
	if (y == 7 || x < 10)
	{
		if (y > x)
		{
			printf("You won't see me.");
		
		}
		else
		{
			int i = 0;
			do
			{
				printf("%c\t", i + 65);
				i++;
			} while (i < y);
			printf("1\t2\t3\n");
		}
	}
	return 0;
}