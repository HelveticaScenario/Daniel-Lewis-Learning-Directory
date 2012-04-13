#include <stdio.h>
#define LENGTH_OF_WEEK 7
main()
{
	int daysOfWeek[LENGTH_OF_WEEK] = {0,1,2,3,4,5,6};
	int offset = 3;
	char* dayName = NULL;
	
	int i;
	for (i = 0; i < LENGTH_OF_WEEK; i++)
	{
		switch (daysOfWeek[(i + offset) % 7])
		{
			case 0: dayName = "Sunday"; break;
			case 1: dayName = "Monday"; break;
			case 2: dayName = "Tuesday"; break;
			case 3: dayName = "Wednesday"; break;
			case 4: dayName = "Thursday"; break;
			case 5: dayName = "Friday"; break;
			case 6: dayName = "Saturday"; break;
			
		}
		
		printf("Today is the greatest, day I ever known... it's %s\n", dayName);
	}
	
	return 0;
}