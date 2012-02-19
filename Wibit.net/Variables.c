#include <stdio.h>

int main()
{
	char listOfCharacters[50];
	int num = 8675309;

	sprintf(listOfCharacters, "%d", num);
	printf("Our list of characters are: %s", listOfCharacters);
	return 0;
}