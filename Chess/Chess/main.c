/*
This is the property of Daniel Lewis. you can share it or build off of it, just dont pass it off as yours.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ROWS 10
#define COLS 10

void createBoard(int[COLS][ROWS]);
void printBoardWhite(int[COLS][ROWS]);
void printBoardBlack(int[COLS][ROWS]);
int verifyMove(int, int, int, int, int[COLS][ROWS]);
int testPawn(int, int, int, int, int[COLS][ROWS]);
int testKnight(int, int, int, int, int[COLS][ROWS]);
int testBishop(int, int, int, int, int[COLS][ROWS]);
int testRook(int, int, int, int, int[COLS][ROWS]);
int testQueen(int, int, int, int, int[COLS][ROWS]);
int testKing(int, int, int, int, int[COLS][ROWS]);


int currentTurn = 1;
//0 means the next turn is White's move, 1 means Black's move. This value determines who's pieces the user input for the turn can manipulate as well as the orientation the board prints as.

int main()
{
    int Board[COLS][ROWS];
	createBoard(Board);
	int end=0; //0 means game still in progress, 1 means white wins, -1 means black wins
	int error=0;
	while(end==0)
	{
        system("cls");
        int a,b,c,d;
        char e,f,g,h;
        printf("WELCOME TO CHESS! I'M SO EXCITED! %d\n\n", end);
        if(currentTurn==0)
            printBoardWhite(Board);
        else
            printBoardBlack(Board);
        printf("Please type in the coordinates of the \npiece you would like to move, followed by a\nspace, and the coordinates of destination.\nBoth uppercase and lowercase letters work.\n");
        if(error==1)
        {
            printf("\nINVALID MOVE!\n");
            error=0;
        }
        scanf(" %c%c %c%c",&e,&f,&g,&h);
        a=toupper(e)-64;
        c=toupper(g)-64;
        b=f-48;
        d=h-48;
        printf("%d %d %d %d     %c %c %c %c\n",a,b,c,d,e,f,g,h);
        if(a<1 || a>8 || b<1 || b>8 || c<1 || c>8 || d<1 || d>8)
        {
            b=toupper(e)-64;
            d=toupper(g)-64;
            a=f-48;
            c=h-48;
            if(a<1 || a>8 || b<1 || b>8 || c<1 || c>8 || d<1 || d>8)
            {
                error=1;
                continue;
            }
        }
        if(Board[c][d]<-2 || Board[c][d]>12 || Board[a][b]<-2 || Board[a][b]>12)
        {
            error=1;
            continue;
        }
        if(verifyMove(a,b,c,d,Board)==1)
        {
            error=1;
            continue;
        }
        if(Board[c][d]==12) end=1;
        else if(Board[c][d]==6) end=-1;
        Board[c][d]=Board[a][b];
        Board[a][b]=0;
//        Board[a][b]=13;
//        Board[c][d]=13;
        if(currentTurn==0)currentTurn=1;
        else if(currentTurn==1)currentTurn=0;
    }
    if(end==1)printf("\n\nWHITE WINS!\n");
    else if(end==-1)printf("\n\nBLACK WINS!\n");

//    printBoardBlack(Board);
//    putchar('\n');
//    printBoardWhite(Board);
	return 0;

}

void createBoard(int board[COLS][ROWS])
{
    int i, j;
	for(i=0; i<COLS; i++)
	{
		for(j=0; j<ROWS; j++)
		{
			if(i == 0 && j == 0)
                board[i][j] = -2; //Origin Piece
			else if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1)
				board[i][j] = -1; //Border Pieces
			else if(j==7)
                board[i][j] = 7; //Black Pawns
			else if(j==8 && (i==2 || i==7))
                board[i][j] = 8; //Black Knights
			else if(j==8 && (i==3 || i==6))
                board[i][j] = 9; //Black Bishops
			else if(j==8 && (i==1 || i==8))
                board[i][j] = 10; //Black Rooks
            else if(j==8 && i==5)
                board[i][j] = 11; //Black Queen
            else if(j==8 && i==4)
                board[i][j] = 12; //Black King
            else if(j==2)
                board[i][j] = 1; //White Pawns
            else if(j==1 && (i==2 || i==7))
                board[i][j] = 2; //White Knights
            else if(j==1 && (i==3 || i==6))
                board[i][j] = 3; //White Bishops
            else if(j==1 && (i==1 || i==8))
                board[i][j] = 4; //White Rooks
            else if(j==1 && i==5)
                board[i][j] = 5; //White Queen
            else if(j==1 && i==4)
                board[i][j] = 6; //White King
			else
                board[i][j] = 0; //Alternating Colored Blank Squares


//			printf("(%d,%d)=%d\n", i, j, board[i][j]);
		}
	}
}

void printBoardWhite(int board[COLS][ROWS])
{
    int i, j;
	for(j=ROWS-1; j>-1; j--)
	{
		for(i=0; i<COLS; i++)
		{
			switch(board[i][j])
			{
			    case -2: putchar('@'); putchar(' '); break;
			    case -1: if((i==0 || i==9) && (j!=0 && j!=9))
//                            {putchar(j+48); putchar(' '); break;}
                            {putchar(j+48); putchar(' '); break;}
                        else if((j==0 || j==9) && (i!=0 && i!=9))
                            {putchar(i+64); putchar(' '); break;}
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
//                case 13: putchar('X'); putchar(' '); break;

			}
		}
		putchar('\n');
	}
    printf("White's Move\n\n");

}

void printBoardBlack(int board[COLS][ROWS])
{
    int i, j;
	for(j=0; j<COLS; j++)
	{
		for(i=ROWS-1; i>-1; i--)
		{
			switch(board[i][j])
			{
			    case -2: putchar('@'); putchar(' '); break;
			    case -1: if((i==0 || i==9) && (j!=0 && j!=9))
                            {putchar(j+48); putchar(' '); break;}
                        else if((j==0 || j==9) && (i!=0 && i!=9))
                            {putchar(i+64); putchar(' '); break;}
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
//                case 13: putchar('X'); putchar(' '); break;

			}
		}
		putchar('\n');
	}
    printf("Black's Move\n\n");
}

int verifyMove(int a, int b, int c, int d, int board[COLS][ROWS])
{
    int x;
    switch(board[a][b])
    {
        case -2: x =  1;
        case -1: x =  1;
        case 0: x =  1;
        case 1: x = (testPawn(a, b, c, d, board));
//        case 2: x = (testKnight(a, b, c, d, board));
//        case 3: x = (testBishop(a, b, c, d, board));
//        case 4: x = (testRook(a, b, c, d, board));
//        case 5: x = (testQueen(a, b, c, d, board));
//        case 6: x = (testKing(a, b, c, d, board));
        case 7: x = (testPawn(a, b, c, d, board));
//        case 8: x = (testKnight(a, b, c, d, board));
//        case 9: x = (testBishop(a, b, c, d, board));
//        case 10: x = (testRook(a, b, c, d, board));
//        case 11: x = (testQueen(a, b, c, d, board));
//        case 12: x = (testKing(a, b, c, d, board));

    }
    return(x);
}

int testPawn(int a, int b, int c, int d, int board[COLS][ROWS])
{
    if(board[a][b]==1 && currentTurn==0)
        {
        if(c==a)
            {
            if(d==4 && b==2 && board[c][3]==0)
                return 0;
            else if(d==(b+1) && board[c][d]==0)
                return 0;
            else
                return 1;
            }
        else if((c==(a+1) || c==(a-1)) && d==(b+1) && board[c][d]>=7)
            return 0;
        else
            return 1;
        }
    else if(board[a][b]==7 && currentTurn==1)
        {
        if(c==a)
            {
            if(d==5 && b==7 && board[c][6]==0)
                return 0;
            else if(d==(b-1) && board[c][d]==0)
                return 0;
            else
                return 1;
            }
        else if((c==(a+1) || c==(a-1)) && d==(b-1) && board[c][d]<=6 && board[c][d]>=1)
            return 0;
        else
            return 1;
        }
    else
        return 1;
}









