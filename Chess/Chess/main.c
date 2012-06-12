/*
This is the property of Daniel Lewis. you can share it or build off of it, just dont pass it off as yours.
*/



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ROWS 10
#define COLS 10

void createBoard(int[ROWS][COLS]);
void printBoardWhite(int[ROWS][COLS]);
void printBoardBlack(int[ROWS][COLS]);
int verifyMove(int, int, int, int, int[ROWS][COLS]);
int testPawn(int, int, int, int);
int testKnight(int, int, int, int);
int testBishop(int, int, int, int);
int testRook(int, int, int, int);
int testQueen(int, int, int, int);
int testKing(int, int, int, int);


int currentTurn = 0;
//0 means the next turn is White's move, 1 means Black's move. This value determines who's pieces the user input for the turn can manipulate as well as the orientation the board prints as.

int main()
{
    int Board[ROWS][COLS];
	createBoard(Board);
	int a,b,c,d;
	char e,f;
	int end=0; //0 means game still in progress, 1 means white wins, -1 means black wins
	while(end==0)
	{
        system("cls");
        printf("WELCOME TO CHESS! I'M SO EXCITED!\n\n");
        if(currentTurn==0)
            printBoardWhite(Board);
        else
            printBoardBlack(Board);
        printf("Please type in the coordinates of the \npiece you would like to move, followed by a\nspace, and the coordinates of the space you would like to move to.\nboth uppercase and lowercase work.\n");
        scanf("%c%d %c%d",&e,&b,&f,&d);
        a=toupper(e)-64;
        c=toupper(f)-64;
        //if(verify(a,b,c,d)==1)continue;
        if(Board[d][c]==-1||Board[d][c]==-2)continue;
        if(Board[d][c]==12) end=1;
        else if(Board[d][c]==6) end=-1;
        Board[d][c]=Board[b][a];
        Board[b][a]=0;
        if(currentTurn==0)currentTurn=1;
        else if(currentTurn==1)currentTurn=0;
    }
    if(currentTurn==1)printf("\n\nWHITE WINS!\n");
    else if(currentTurn==-1)printf("\n\nBLACK WINS!\n");

//    printBoardBlack(Board);
//    putchar('\n');
//    printBoardWhite(Board);
	return 0;

}

void createBoard(int board[ROWS][COLS])
{
    int i, j;
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLS; j++)
		{
			if(i == 0 && j == 0)
                board[i][j] = -2; //Origin Piece
			else if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1)
				board[i][j] = -1; //Border Pieces
			else if(i==7)
                board[i][j] = 7; //Black Pawns
			else if(i==8 && (j==2 || j==7))
                board[i][j] = 8; //Black Knights
			else if(i==8 && (j==3 || j==6))
                board[i][j] = 9; //Black Bishops
			else if(i==8 && (j==1 || j==8))
                board[i][j] = 10; //Black Rooks
            else if(i==8 && j==5)
                board[i][j] = 11; //Black Queen
            else if(i==8 && j==4)
                board[i][j] = 12; //Black King
            else if(i==2)
                board[i][j] = 1; //White Pawns
            else if(i==1 && (j==2 || j==7))
                board[i][j] = 2; //White Knights
            else if(i==1 && (j==3 || j==6))
                board[i][j] = 3; //White Bishops
            else if(i==1 && (j==1 || j==8))
                board[i][j] = 4; //White Rooks
            else if(i==1 && j==5)
                board[i][j] = 5; //White Queen
            else if(i==1 && j==4)
                board[i][j] = 6; //White King
			else
                board[i][j] = 0; //Alternating Colored Blank Squares


//			printf("(%d,%d)=%d\n", i, j, board[i][j]);
		}
	}
}

void printBoardWhite(int board[ROWS][COLS])
{
    int i, j;
	for(i=ROWS-1; i>-1; i--)
	{
		for(j=0; j<COLS; j++)
		{
			switch(board[i][j])
			{
			    case -2: putchar('@'); putchar(' '); break;
			    case -1: if((i==0 || i==9) && (j!=0 && j!=9))
//                            {putchar(j+48); putchar(' '); break;}
                            {putchar(j+64); putchar(' '); break;}
                        else if((j==0 || j==9) && (i!=0 && i!=9))
                            {putchar(i+48); putchar(' '); break;}
                        else
                            {putchar('#'); putchar(' '); break;}
			    case 0: if((i+j)%2==0)
                            {putchar('+'); putchar(' '); break;}
                        else
                            {putchar('o'); putchar(' '); break;}

			    //white's pieces
                case 1: putchar('p'); putchar(' '); break;
			    case 2: putchar('h'); putchar(' '); break;
			    case 3: putchar('b'); putchar(' '); break;
			    case 4: putchar('r'); putchar(' '); break;
			    case 5: putchar('q'); putchar(' '); break;
			    case 6: putchar('k'); putchar(' '); break;
                //black's pieces
                case 7: putchar('P'); putchar(' '); break;
			    case 8: putchar('H'); putchar(' '); break;
			    case 9: putchar('B'); putchar(' '); break;
			    case 10: putchar('R'); putchar(' '); break;
			    case 11: putchar('Q'); putchar(' '); break;
			    case 12: putchar('K'); putchar(' '); break;


			}
		}
		putchar('\n');
	}
    printf("White's Move\n\n");

}

void printBoardBlack(int board[ROWS][COLS])
{
    int i, j;
	for(i=0; i<ROWS; i++)
	{
		for(j=COLS-1; j>-1; j--)
		{
			switch(board[i][j])
			{
			    case -2: putchar('@'); putchar(' '); break;
			    case -1: if((i==0 || i==9) && (j!=0 && j!=9))
                            {putchar(j+64); putchar(' '); break;}
                        else if((j==0 || j==9) && (i!=0 && i!=9))
                            {putchar(i+48); putchar(' '); break;}
                        else
                            {putchar('#'); putchar(' '); break;}
			    case 0: if((i+j)%2==0)
                            {putchar('+'); putchar(' '); break;}
                        else
                            {putchar('o'); putchar(' '); break;}

			    //white's pieces
                case 1: putchar('p'); putchar(' '); break;
			    case 2: putchar('h'); putchar(' '); break;
			    case 3: putchar('b'); putchar(' '); break;
			    case 4: putchar('r'); putchar(' '); break;
			    case 5: putchar('q'); putchar(' '); break;
			    case 6: putchar('k'); putchar(' '); break;
                //black's pieces
                case 7: putchar('P'); putchar(' '); break;
			    case 8: putchar('H'); putchar(' '); break;
			    case 9: putchar('B'); putchar(' '); break;
			    case 10: putchar('R'); putchar(' '); break;
			    case 11: putchar('Q'); putchar(' '); break;
			    case 12: putchar('K'); putchar(' '); break;

			}
		}
		putchar('\n');
	}
    printf("Black's Move\n\n");
}

int verifyMove(int a, int b, int c, int d, int board[ROWS][COLS])
{
    int x = switch(board[b][a])
    {
        case -2: return 1;
        case -1: return 1;
        case 0: return 1;
        case 1: return(testPawn(a, b, c, d));
        case 2: return(testKnight(a, b, c, d));
        case 3: return(testBishop(a, b, c, d));
        case 4: return(testRook(a, b, c, d));
        case 5: return(testQueen(a, b, c, d));
        case 6: return(testKing(a, b, c, d));
        case 7: return(testPawn(a, b, c, d));
        case 8: return(testKnight(a, b, c, d));
        case 9: return(testBishop(a, b, c, d));
        case 10: return(testRook(a, b, c, d));
        case 11: return(testQueen(a, b, c, d));
        case 12: return(testKing(a, b, c, d));

    }
    return(x);
}

int testPawn()
