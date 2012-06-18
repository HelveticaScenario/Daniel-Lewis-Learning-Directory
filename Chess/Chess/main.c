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

int promote=0;
int currentTurn = 0;
//0 means the next turn is White's move, 1 means Black's move. This value determines who's pieces the user input for the turn can manipulate as well as the orientation the board prints as.

int main()
{
    int Board[COLS][ROWS];
	createBoard(Board);
	int end=0; //0 means game still in progress, 1 means white wins, -1 means black wins
	int error=0;
	int result=0;
	int a,b,c,d;
    char e,f,g,h;
	while(end==0)
	{
        if(promote==0)
        {
        system("cls");
        printf("WELCOME TO CHESS! I'M SO EXCITED!\n\n");
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
        fflush(stdin);
        scanf("%c%c %c%c",&e,&f,&g,&h);
        a=toupper(e)-64;
        c=toupper(g)-64;
        b=f-48;
        d=h-48;
        //printf("%d %d %d %d     %c %c %c %c\n",a,b,c,d,e,f,g,h);
        if(a<1 || a>8)
        {
            a=f-48;
            if(a<1 || a>8)
            {
                error=1;
                continue;
            }
        }
        if(b<1 || b>8)
        {
            b=toupper(e)-64;
            if(b<1 || b>8)
            {
                error=1;
                continue;
            }
        }
        if(c<1 || c>8)
        {
            c=h-48;
            if(c<1 || c>8)
            {
                error=1;
                continue;
            }
        }
        if(d<1 || d>8)
        {
            d=toupper(g)-64;
            if(d<1 || d>8)
            {
                error=1;
                continue;
            }
        }
        if(a==c && b==d)
        {
            error=1;
            continue;
        }
        if(Board[c][d]<-2 || Board[c][d]>12 || Board[a][b]<-2 || Board[a][b]>12)
        {
            error=1;
            continue;
        }
        result = verifyMove(a,b,c,d,Board);
        if(result == 1)
        {
            error=1;
            continue;
        }
        if(result == 0)
        {
            if(Board[c][d]==12) end=1;
            else if(Board[c][d]==6) end=-1;
        }
        Board[c][d]=Board[a][b];
        Board[a][b]=0;
        }
        if(promote==1)
        {
            printf("Congratulations! Which piece type do you want your\npawn to now become?\n1. A ROOK\n2. A BISHOP\n3. A KNIGHT\n4. A QUEEN\n> ");
            int choice;
            fflush(stdin);
            scanf("%d", &choice);
            if(choice<=0 || choice>=5)
                continue;
            switch(choice)
            {
                case 1: if(currentTurn==0)Board[c][d]=4;
                        else Board[c][d]=10;
                        break;
                case 2: if(currentTurn==0)Board[c][d]=3;
                        else Board[c][d]=9;
                        break;
                case 3: if(currentTurn==0)Board[c][d]=2;
                        else Board[c][d]=8;
                        break;
                case 4: if(currentTurn==0)Board[c][d]=5;
                        else Board[c][d]=11;
                        break;
            }
            promote=0;
        }
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
            else if(j==8 && i==4)
                board[i][j] = 11; //Black Queen
            else if(j==8 && i==5)
                board[i][j] = 12; //Black King
            else if(j==2)
                board[i][j] = 1; //White Pawns
            else if(j==1 && (i==2 || i==7))
                board[i][j] = 2; //White Knights
            else if(j==1 && (i==3 || i==6))
                board[i][j] = 3; //White Bishops
            else if(j==1 && (i==1 || i==8))
                board[i][j] = 4; //White Rooks
            else if(j==1 && i==4)
                board[i][j] = 5; //White Queen
            else if(j==1 && i==5)
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
    x = board[a][b];
    switch(x)
    {
        case -2: x =  1; break;
        case -1: x =  1; break;
        case 0: x =  1; break;
        case 1: x = (testPawn(a, b, c, d, board)); break;
        case 2: x = 0; break; //(testKnight(a, b, c, d, board)); break;
        case 3: x = (testBishop(a, b, c, d, board)); break;
        case 4: x = (testRook(a, b, c, d, board)); break;
        case 5: x = 0; break; //(testQueen(a, b, c, d, board)); break;
        case 6: x = 0; break; //(testKing(a, b, c, d, board)); break;
        case 7: x = (testPawn(a, b, c, d, board)); break;
        case 8: x = 0; break; //(testKnight(a, b, c, d, board)); break;
        case 9: x = (testBishop(a, b, c, d, board)); break;
        case 10: x = (testRook(a, b, c, d, board)); break;
        case 11: x = 0; break; //(testQueen(a, b, c, d, board)); break;
        case 12: x = 0; break; //(testKing(a, b, c, d, board)); break;

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
                {
                if(d==8)
                    promote = 1;
                return 0;
                }
            else if(d==(b+1) && board[c][d]==0)
                {
                if(d==8)
                    promote = 1;
                return 0;
                }
            else
                return 1;
        }
        else if((c==(a+1) || c==(a-1)) && d==(b+1) && board[c][d]>=7)
            {
                if(d==8)
                    promote = 1;
                return 0;
            }
        else
            return 1;
    }
    else if(board[a][b]==7 && currentTurn==1)
    {
        if(c==a)
        {
            if(d==5 && b==7 && board[c][6]==0)
                {
                    if(d==1)
                    promote = 1;
                return 0;
                }
            else if(d==(b-1) && board[c][d]==0)
                {
                    if(d==1)
                    promote = 1;
                return 0;
                }
            else
                return 1;
        }
        else if((c==(a+1) || c==(a-1)) && d==(b-1) && board[c][d]<=6 && board[c][d]>=1)
            {
                if(d==1)
                    promote = 1;
                return 0;
            }
        else
            return 1;
    }
    else
        return 1;
}

int testRook(int a, int b, int c, int d, int board[COLS][ROWS])
{
    if(board[a][b]==4 && currentTurn==0)
    {
        if(board[c][d]==6 && c==5 && d==1 && b==1)
        {
            if(a==1 && board[2][1]==0 && board[3][1]==0 && board[4][1]==0)
            {
                board[4][1]=6;
                return 2;
            }
            else if(a==8 && board[7][1]==0 && board[6][1]==0)
            {
                board[6][1]=6;
                return 2;
            }
            else
                return 1;
        }
        else if(board[c][d]==0 || board[c][d]>=7)
        {
            if(c==a && d!=b)
            {
                if(d>b)
                {
                    if(d==(b+1))
                        return 0;
                    int i=(d-1);
                    do {
                        if(board[a][i]>0)
                            return 1;
                        i=(i-1);
                    }   while(i>b);
                    return 0;
                }
                else if(d<b)
                {
                    if(d==(b-1))
                        return 0;
                    int i=(d+1);
                    do {
                        if(board[a][i]>0)
                            return 1;
                        i=(i+1);
                    }   while(i<b);
                    return 0;
                }
                else
                    return 1;
            }
            else if(d==b && c!=a)
            {
                if(c>a)
                {
                    if(c==(a+1))
                        return 0;
                    int i=(c-1);
                    do {
                        if(board[i][b]>0)
                            return 1;
                        i=(i-1);
                    }   while(i>a);
                    return 0;
                }
                else if(c<a)
                {
                    if(c==(a-1))
                        return 0;
                    int i=(c+1);
                    do {
                        if(board[i][b]>0)
                            return 1;
                        i=(i+1);
                    }   while(i<a);
                    return 0;
                }
                else
                    return 1;
            }
            else
                return 1;
        }
        else
            return 1;
    }
    else if(board[a][b]==10 && currentTurn==1)
    {
        if(board[c][d]==12 && c==5 && d==8 && b==8)
        {
            if(a==1 && board[2][8]==0 && board[3][8]==0 && board[4][8]==0)
            {
                board[4][8]=12;
                return 2;
            }
            else if(a==8 && board[7][8]==0 && board[6][8]==0)
            {
                board[6][8]=12;
                return 2;
            }
            else
                return 1;
        }
        else if(board[c][d]>=0 && board[c][d]<=6)
        {
            if(c==a && d!=b)
            {
                if(d>b)
                {
                    if(d==(b+1))
                        return 0;
                    int i=(d-1);
                    do {
                        if(board[a][i]>0)
                            return 1;
                        i=(i-1);
                    }   while(i>b);
                    return 0;
                }
                else if(d<b)
                {
                    if(d==(b-1))
                        return 0;
                    int i=(d+1);
                    do {
                        if(board[a][i]>0)
                            return 1;
                        i=(i+1);
                    }   while(i<b);
                    return 0;
                }
                else
                    return 1;
            }
            else if(d==b && c!=a)
            {
                if(c>a)
                {
                    if(c==(a+1))
                        return 0;
                    int i=(c-1);
                    do {
                        if(board[i][b]>0)
                            return 1;
                        i=(i-1);
                    }   while(i>a);
                    return 0;
                }
                else if(c<a)
                {
                    if(c==(a-1))
                        return 0;
                    int i=(c+1);
                    do {
                        if(board[i][b]>0)
                            return 1;
                        i=(i+1);
                    }   while(i<a);
                    return 0;
                }
                else
                    return 1;
            }
            else
                return 1;
        }
        else
            return 1;
    }
    else
        return 1;
}

int testBishop(int a, int b, int c, int d, int board[COLS][ROWS])
{
    if(board[a][b]==3 && currentTurn==0 && (board[c][d]<=0 || board[c][d]>=7))
    {
        int xdif,ydif;
        xdif = (a-c);
        ydif = (b-d);
        if((xdif*xdif) == (ydif*ydif))
        {
            int i,j;
            if(xdif<0)
            {
                i=(c+1);
                if(ydif<0)
                {
                    if(xdif==-1 && ydif==-1)
                        return 0;
                    j=(d+1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i--;
                        j--;
                    }while(i<a && j<b);
                    return 0;
                }
                else if(ydif>0)
                {
                    if(xdif==-1 && ydif==1)
                        return 0;
                    j=(d-1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i--;
                        j++;
                    }while(i<a && j>b);
                    return 0;
                }
                else
                    return 1;
            }
            else if(xdif>0)
            {
                i=(c-1);
                if(ydif<0)
                {
                    if(xdif==1 && ydif==-1)
                        return 0;
                    j=(d+1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i++;
                        j--;
                    }while(i>a && j<b);
                    return 0;
                }
                else if(ydif>0)
                {
                    if(xdif==1 && ydif==1)
                        return 0;
                    j=(d-1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i++;
                        j++;
                    }while(i>a && j>b);
                    return 0;
                }
                else
                    return 1;
            }
        }
        else
            return 1;
    }
    else if(board[a][b]==9 && currentTurn==1 && board[c][d]<=6)
    {
        int xdif,ydif;
        xdif = (a-c);
        ydif = (b-d);
        if((xdif*xdif) == (ydif*ydif))
        {
            int i,j;
            if(xdif<0)
            {
                i=(c+1);
                if(ydif<0)
                {
                    if(xdif==-1 && ydif==-1)
                        return 0;
                    j=(d+1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i--;
                        j--;
                    }while(i<a && j<b);
                    return 0;
                }
                else if(ydif>0)
                {
                    if(xdif==-1 && ydif==1)
                        return 0;
                    j=(d-1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i--;
                        j++;
                    }while(i<a && j>b);
                    return 0;
                }
                else
                    return 1;
            }
            else if(xdif>0)
            {
                i=(c-1);
                if(ydif<0)
                {
                    if(xdif==1 && ydif==-1)
                        return 0;
                    j=(d+1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i++;
                        j--;
                    }while(i>a && j<b);
                    return 0;
                }
                else if(ydif>0)
                {
                    if(xdif==1 && ydif==1)
                        return 0;
                    j=(d-1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i++;
                        j++;
                    }while(i>a && j>b);
                    return 0;
                }
                else
                    return 1;
            }
        }
        else
            return 1;
    }
    else
        return 1;
}

int testQueen(int a, int b, int c, int d, int board[COLS][ROWS])
{
    if(board[a][b]==5 && currentTurn==0 && (board[c][d]<=0 || board[c][d]>=7))
    {
        int xdif,ydif;
        xdif = (a-c);
        ydif = (b-d);
        if((xdif*xdif) == (ydif*ydif))
        {
            int i,j;
            if(xdif<0)
            {
                i=(c+1);
                if(ydif<0)
                {
                    if(xdif==-1 && ydif==-1)
                        return 0;
                    j=(d+1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i--;
                        j--;
                    }while(i<a && j<b);
                    return 0;
                }
                else if(ydif>0)
                {
                    if(xdif==-1 && ydif==1)
                        return 0;
                    j=(d-1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i--;
                        j++;
                    }while(i<a && j>b);
                    return 0;
                }
                else
                    return 1;
            }
            else if(xdif>0)
            {
                i=(c-1);
                if(ydif<0)
                {
                    if(xdif==1 && ydif==-1)
                        return 0;
                    j=(d+1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i++;
                        j--;
                    }while(i>a && j<b);
                    return 0;
                }
                else if(ydif>0)
                {
                    if(xdif==1 && ydif==1)
                        return 0;
                    j=(d-1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i++;
                        j++;
                    }while(i>a && j>b);
                    return 0;
                }
                else
                    return 1;
            }
        }
        else if(c==a && d!=b)
        {
            if(d>b)
            {
                if(d==(b+1))
                    return 0;
                int i=(d-1);
                do {
                    if(board[a][i]>0)
                        return 1;
                    i=(i-1);
                }   while(i>b);
                return 0;
            }
            else if(d<b)
            {
                if(d==(b-1))
                    return 0;
                int i=(d+1);
                do {
                    if(board[a][i]>0)
                        return 1;
                    i=(i+1);
                }   while(i<b);
                return 0;
            }
            else
                return 1;
            }
        else if(d==b && c!=a)
        {
            if(c>a)
            {
                if(c==(a+1))
                    return 0;
                int i=(c-1);
                do {
                    if(board[i][b]>0)
                        return 1;
                    i=(i-1);
                }   while(i>a);
                return 0;
            }
            else if(c<a)
            {
                if(c==(a-1))
                    return 0;
                int i=(c+1);
                do {
                    if(board[i][b]>0)
                        return 1;
                    i=(i+1);
                }   while(i<a);
                return 0;
            }
            else
                return 1;
        }
        else
            return 1;

    }
    else if(board[a][b]==11 && currentTurn==1 && board[c][d]<=6)
    {
        int xdif,ydif;
        xdif = (a-c);
        ydif = (b-d);
        if((xdif*xdif) == (ydif*ydif))
        {
            int i,j;
            if(xdif<0)
            {
                i=(c+1);
                if(ydif<0)
                {
                    if(xdif==-1 && ydif==-1)
                        return 0;
                    j=(d+1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i--;
                        j--;
                    }while(i<a && j<b);
                    return 0;
                }
                else if(ydif>0)
                {
                    if(xdif==-1 && ydif==1)
                        return 0;
                    j=(d-1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i--;
                        j++;
                    }while(i<a && j>b);
                    return 0;
                }
                else
                    return 1;
            }
            else if(xdif>0)
            {
                i=(c-1);
                if(ydif<0)
                {
                    if(xdif==1 && ydif==-1)
                        return 0;
                    j=(d+1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i++;
                        j--;
                    }while(i>a && j<b);
                    return 0;
                }
                else if(ydif>0)
                {
                    if(xdif==1 && ydif==1)
                        return 0;
                    j=(d-1);
                    do
                    {
                        if(board[i][j]>=1)
                            return 1;
                        i++;
                        j++;
                    }while(i>a && j>b);
                    return 0;
                }
                else
                    return 1;
            }
        }
        else if(c==a && d!=b)
        {
            if(d>b)
            {
                if(d==(b+1))
                    return 0;
                int i=(d-1);
                do {
                    if(board[a][i]>0)
                        return 1;
                    i=(i-1);
                }   while(i>b);
                return 0;
            }
            else if(d<b)
            {
                if(d==(b-1))
                    return 0;
                int i=(d+1);
                do {
                    if(board[a][i]>0)
                        return 1;
                    i=(i+1);
                }   while(i<b);
                return 0;
            }
            else
                return 1;
            }
        else if(d==b && c!=a)
        {
            if(c>a)
            {
                if(c==(a+1))
                    return 0;
                int i=(c-1);
                do {
                    if(board[i][b]>0)
                        return 1;
                    i=(i-1);
                }   while(i>a);
                return 0;
            }
            else if(c<a)
            {
                if(c==(a-1))
                    return 0;
                int i=(c+1);
                do {
                    if(board[i][b]>0)
                        return 1;
                    i=(i+1);
                }   while(i<a);
                return 0;
            }
            else
                return 1;
        }
        else
            return 1;
    }
    else
        return 1;
}




