#include <stdio.h>

int main()
{
	int stayAlive = 1;
	char* userPrompt = "Do you want to exit this program (Y/N)? ";
	char c;
	printf("%s", userPrompt);
	while(stayAlive == 1)
	{
		c = getchar();
		if(c == '\n')
			continue;
		else if(c == 'Y' || c == 'y')
			stayAlive = 0;
		else
			printf("%s", userPrompt);
	}
	puts("\n\nHave a nice day, Buddy!");
	return 0;
}