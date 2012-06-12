#include <stdio.h>


//void createBoard(int, int, int[][]);

void createBoard(int rows, int cols, int board[rows][cols])
{
    int i, j;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			if(i == 0 || j == 0 || i == rows-1 || j == cols-1)
				board[i][j] = -1;
			printf("(%d,%d)=%d\n", i, j, board[i][j]);
		}
	}
}


int main()
{
	int Board[10][10];
	createBoard(10, 10, Board);
	return 0;
}

