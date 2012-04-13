#include <stdio.h>

int main()
{
	char value[6] = "abcde";
	char* n;
	int m;
	n = value;
	printf("%s %c %X\n", value, value, value);
	// printf("%i %p\n", *n, *n);
	printf("%X  %s\n", n, *n);
	// char c = (char) 1234;
	// printf("%c", c);
	return 0;
} // pointers work as passthroughs, as with int you can assign it a value, 
  // just as another int, but with the special function of * to tell the compiler to take the 
  // value of the int, for instance 25, and treat that value like a memory address, address 25 or the 25th block.
  // you use the & to call another var's address as an int, so that its not useless.