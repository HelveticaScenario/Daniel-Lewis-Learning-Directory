/*
This program generates as many [POINT]...[/POINT] as you desire.
The important part is on line 30.
*/
#include <stdio.h>
#include <math.h>



int main()
{
	int choice = 0;
	printf("Which type of function would you like to make?\nEnter the number corresponding to your choice\n\n1 - Linear\n2 - Exponential\n3 - Logarithmic\n");
	scanf("%d", &choice);
	if (choice == 1)
	{ //Linear function equation
		//Variables
		float start, end, inc, m, b;
		//Program asks for values for some variables
		printf("Start value for X:");
		scanf("%f", &start);
		printf("\nEnd value for X:");
		scanf("%f", &end);
		printf("\nIncrement value for X:");
		scanf("%f", &inc);
		printf("\n\n Y = mX + b\n\nValue for m: ");
		scanf("%f", &m);
		printf("\nValue for b: ");
		scanf("%f", &b);
  
		FILE* f = fopen("LINCURVEPOINTS.txt", "w");
  
		float x, y;
  
		//Write to file loop
		for(x = start; x < end; x += inc)
		{
		y = m*x + b; //THIS DETERMINES THE CURVE YOU GET
    
		fprintf(f, "[POINT]\n<FLOAT>X:%.f\n<FLOAT>Y:%.1f\n[/POINT]\n", x, y); //This prints to the file. See http://www.cplusplus.com/reference/clibrary/cstdio/fprintf/ for allowed formats.
		
		}
		return 0;
	}

	else if (choice == 2)
	{  	//Exponential function equation
		//Variables
		float start, end, inc, m, n, p, b;
		//Program asks for values for some variables
		printf("Start value for X:");
		scanf("%f", &start);
		printf("\nEnd value for X:");
		scanf("%f", &end);
		printf("\nIncrement value for X:");
		scanf("%f", &inc);
		printf("\n\n Y = mX^p + nX + b\n\nValue for m: ");
		scanf("%f", &m);
		printf("\nValue for p: ");
		scanf("%f", &p);
		printf("\nValue for n: ");
		scanf("%f", &n);
		printf("\nValue for b: ");
		scanf("%f", &b);
  
		FILE* f = fopen("EXPCURVEPOINTS.txt", "w");
  
		float x, y, z;
  
		//Write to file loop
		for(x = start; x < end; x += inc)
		{
		z = pow( x, p);
		y = (m*z) + (n*x) + b; //THIS DETERMINES THE CURVE YOU GET
    
		fprintf(f, "[POINT]\n<FLOAT>X:%.f\n<FLOAT>Y:%.1f\n[/POINT]\n", x, y); //This prints to the file. See http://www.cplusplus.com/reference/clibrary/cstdio/fprintf/ for allowed formats.
		
		}
		return 0;
	}
	
	else if (choice == 3)
	{	//Natural Logarithmic Function Equation
		// Variables
		float start, end, inc, a, b, c, d;
		// Program asks for values for some variables
		printf("Start value for X:");
		scanf("%f", &start);
		printf("\nEnd value for X:");
		scanf("%f", &end);
		printf("\nIncrement value for X:");
		scanf("%f", &inc);
		printf("\n\n Y = a*(log(b(x+c))+d\nTo see what the graph looks like with what\nvalues, go to http://www.analyzemath.com/logfunction/logfunction.html\nbe sure to check the 'B = e' box\n\nValue for a: ");
		scanf("%f", &a);
		printf("\nValue for b: ");
		scanf("%f", &b);
		printf("\nValue for c: ");
		scanf("%f", &c);
		printf("\nValue for d: ");
		scanf("%f", &d);
  
		FILE* f = fopen("LOGCURVEPOINTS.txt", "w");
  
		float x, y;
  
		// Write to file loop
		for(x = start; x < end; x += inc)
		{
	
		y = a*(log(b*(x+c)))+d; //THIS DETERMINES THE CURVE YOU GET
    
		fprintf(f, "[POINT]\n<FLOAT>X:%.f\n<FLOAT>Y:%.1f\n[/POINT]\n", x, y); //This prints to the file. See http://www.cplusplus.com/reference/clibrary/cstdio/fprintf/ for allowed formats.
		
		}
		return 0;
	}
    
	else
	{
	printf("... No. Try again.");
	return 0;
	}
}