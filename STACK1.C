#include "stack.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[100][100],n,e,f;

	struct stack sr;
	struct stack sc;

int isEmpty(struct stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

int push(struct stack *s,int data)
{
	s->top=s->top+1;
	s->arr[s->top]=data;
	return 1;
}

int pop(struct stack *s,int *data)
{
	if(isEmpty(s))
	{
		return 0;
	}
	*data=s->arr[s->top];
	s->top=s->top-1;
	return 1;
}
void buildMatrix()
{
	int i,j,trow,tcol,b;
	printf("\n");
	for(i=1;i<=n;i++)
	{
		textcolor(MAGENTA);
		cprintf(" %2d",i);
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{       textcolor(YELLOW);
		cprintf("|");
	  for(j=1;j<=n;j++)
	  {
			if((i+j)%2==0)
				{
					if(a[i][j]=='Q')
					{
						textcolor(GREEN);
					       cprintf("\xDB\xDB\xDB");
					}
					else
					       printf("\xDB\xDB\xDB");

				}
			else
			{
					if(a[i][j]=='Q')
					{
						textcolor(GREEN);
					       cprintf(" %c ",a[i][j]);
					}
					else
					       printf("   ");


			}

	  }
	  textcolor(YELLOW);
	  cprintf("|");
	  textcolor(MAGENTA);
	  cprintf(" %d",i);
	  printf("\n");
	}

}
void placements1()
{
	int b,i,trow,tcol;
	printf("\n 1. Placements ");
	printf("\n 2. Continue");
	printf("\n Enter the choice :");
	scanf("%d",&b);
	printf("\n");
	switch(b)
	{
	case 1:
	{
	printf("\n");
	printf("\n The queens are in the following row and col");
	printf("\n");

	for(i=1;i<=n;i++)
	{
		pop(&sr,&trow);
		pop(&sc,&tcol);
		printf("row - %d,col - %d ",trow,tcol);
		printf("\n");
	}
	getch();
	break;
	}
	case 2:
	{
	break;
	}
	}
}
void placements()
{
	int i,j,b;
	printf("\nQueens are in the following row and col\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{

				if(a[i][j]=='Q'){
				printf("row - %d,col - %d\n",i,j);
			}
		}
	}
}


int PresentQueenColumn(int row)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[row][i]=='Q')
		{
			return(i);
			break;
		}
	}
}
int isSafe(int row,int col)
{
	int i,tcol;
	for(i=1;i<=n;i++)
	{
		tcol=PresentQueenColumn(i);
		if(col==tcol)
			return 0;
		if(abs(row-i)==abs(col-tcol))
			return 0;
	}
	return 1;
}
int placeQueen(int row,int col)
{
	a[row][col]='Q';
	return 1;
}
int removeQueen(int row,int col)
{
	if(a[row][col]=='Q'){

		a[row][col]='.';
	}
	return 1;
}


void nqueens()
{
	int row,col,col1,trow,tcol,trow1,tcol1,i,j;
	row=1;
	col=0;
	col1=col;
	if(row<=n)
	{
		while(col1<=n && row<=n)
		{
			col1=col1+1;
			if(isSafe(row,col1))
			{
				placeQueen(row,col1);
				push(&sr,row);
				push(&sc,col1);
				row=row+1;
				col1=0;
			}
			if(col1>=n)
			{


					pop(&sr,&trow);
					pop(&sc,&tcol);
					removeQueen(trow,tcol);
					row=trow;
					col1=tcol;
					if(tcol==n)
					{
						if(trow==2)
						{
						while(!isEmpty(&sr))
						{
							pop(&sr,&trow1);
							pop(&sc,&tcol1);
							removeQueen(trow1,tcol1);
						}
						row=1;
						col=col+1;
						col1=col;
						}
						else
						{
						pop(&sr,&trow);
						pop(&sc,&tcol);
						removeQueen(trow,tcol);
						row=trow;
						col1=tcol;
						}

					}

			}
		}

	}
	buildMatrix();
	printf("\n");
	placements1();
}

void nqueens1()
{
	int row,col,col1,trow,tcol,trow1,tcol1,i,j;
	row=1;
	col=0;
	col1=col;
	if(row<=n)
	{
		while(col1<=n && row<=n)
		{
			col1=col1+1;
			if(isSafe(row,col1))
			{
				placeQueen(row,col1);
				push(&sr,row);
				push(&sc,col1);
				clrscr();
				printf("\nThe Solution is :      ");
				printf("\n");
				printf("\n");
				buildMatrix();
				printf("\n");
				placements();
				getch();
				row=row+1;
				col1=0;
			}
			if(col1>=n)
			{


					pop(&sr,&trow);
					pop(&sc,&tcol);
					removeQueen(trow,tcol);


					clrscr();
					printf("\nThe Solution is :      ");
					printf("\n");
					printf("\n");
					buildMatrix();
					printf("\n");
					placements();
					getch();
					row=trow;
					col1=tcol;
					if(tcol==n)
					{
						if(trow==2)
						{
						while(!isEmpty(&sr))
						{
							pop(&sr,&trow1);
							pop(&sc,&tcol1);
							removeQueen(trow1,tcol1);

							clrscr();
							printf("\nThe Solution is :      ");
							printf("\n");
							printf("\n");
							buildMatrix();
							printf("\n");
							placements();
							getch();
						}
						row=1;
						col=col+1;
						col1=col;
						}
						else
						{
						pop(&sr,&trow);
						pop(&sc,&tcol);
						removeQueen(trow,tcol);

						clrscr();
						printf("\nThe Solution is :      ");
						printf("\n");
						printf("\n");
						buildMatrix();
						printf("\n");
						placements();
						getch();
						row=trow;
						col1=tcol;
						}

					}

			}
		}

	}
}

int main()
{
	int i,j,b,e=1,k;
	clrscr();

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]='.';
		}
	}
	while(e)
	{
		clrscr();
		printf("\n           N-Queens Problem             ");
		printf("\n ***************************************");
		printf("\n *                                     *");
		printf("\n *                                     *");
		printf("\n *                                     *");
		printf("\n *              1. Start               *");
		printf("\n *                                     *");
		printf("\n *                                     *");
		printf("\n *              2. Exit                *");
		printf("\n *                                     *");
		printf("\n *                                     *");
		printf("\n *                                     *");
		printf("\n ***************************************");
		printf("\n Enter your choice :");
		scanf("%d",&b);
		switch(b)
		{
			case 1:
			{
				printf("\n Enter the number of queens:");
				scanf("%d",&n);
				clrscr();
				printf("\n Placement Statictics ");
				printf("\n");
				printf("\n 1. Step wise Placement ");
				printf("\n 2. Direct Placement    ");
				printf("\n Enter the choice :");
				scanf("%d",&k);
				switch(k)
				{
				case 1:
				{
				clrscr();
				printf("\n The Placements of %d Queens ",n);
				printf("\n");
				printf("\n");
				nqueens1();
				break;
				}
				case 2:
				{
				clrscr();
				printf("\n The Placements of %d Queens ",n);
				printf("\n");
				printf("\n");
				nqueens();
				break;
				}
				}

			break;
			}
			case 2:
			{
				e=0;
				break;
			}
		}
	}
	getch();
	return 0;
}