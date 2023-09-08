#include <stdio.h>
#include <stdbool.h>
#include <conio.h>  
#include <stdlib.h>     

char position[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char choice[2] = {'x', 'o'};
bool conplay = true;

void board() 
{
	int b;
	printf("\tTic Tac Toe Game\n\n");
	printf("Player (X)\t-\tBot (O)\n\n");
	printf("\t|\t|\t\n");
	printf("   %c\t|   %c\t|   %c\t\n", position[0], position[1], position[2]);
	printf("_______\t|______\t|_______\t\n");
	printf("\t|\t|\t\n");
	printf("   %c\t|   %c\t|   %c\t\n", position[3], position[4], position[5]);
	printf("_______\t|______\t|_______\t\n");
	printf("\t|\t|\t\n");
	printf("  %c\t|   %c\t|   %c\t\n", position[6], position[7], position[8]);
	printf("\t|\t|\t\n\n");
}

void reset()
{
	int i;
	
	for (i=0;i<9;i++)
	{
		position[i] = ' ';
	}
	
	system("cls");
}

void asktoplay()
{
	char askplay[100];
	printf("Play again? (y/n): ");
	scanf("%s", askplay);
	char *p = askplay;
	
	if ((*p=='Y') || (*p=='y'))
	{
		conplay = true;
		reset();
	}
	else if ((*p=='N') || (*p=='n'))
	{
		printf("Bye!\n\n");
		conplay = false;
	}
	else
	{
		printf("Error!\n\n");
		asktoplay();
	}
}

void checkwin()
{
	if (((position[0]=='x') && (position[1]=='x') && (position[2]=='x')) || 
		((position[3]=='x') && (position[4]=='x') && (position[5]=='x')) ||
		((position[6]=='x') && (position[7]=='x') && (position[8]=='x')) ||
		((position[0]=='x') && (position[3]=='x') && (position[6]=='x')) ||
		((position[1]=='x') && (position[4]=='x') && (position[7]=='x')) ||
		((position[2]=='x') && (position[5]=='x') && (position[8]=='x')) ||
		((position[0]=='x') && (position[4]=='x') && (position[8]=='x')) ||
		((position[2]=='x') && (position[4]=='x') && (position[6]=='x')) ) 
	{
		printf("Player win!\n\n");
		asktoplay();
		
	}
	else if (((position[0]=='o') && (position[1]=='o') && (position[2]=='o')) || 
			 ((position[3]=='o') && (position[4]=='o') && (position[5]=='o')) ||
			 ((position[6]=='o') && (position[7]=='o') && (position[8]=='o')) ||
			 ((position[0]=='o') && (position[3]=='o') && (position[6]=='o')) ||
			 ((position[1]=='o') && (position[4]=='o') && (position[7]=='o')) ||
			 ((position[2]=='o') && (position[5]=='o') && (position[8]=='o')) ||
			 ((position[0]=='o') && (position[4]=='o') && (position[8]=='o')) ||
			 ((position[2]=='o') && (position[4]=='o') && (position[6]=='o')) ) 
	{
		printf("Bot win!\n\n");
		asktoplay();
	}
	else if (position[0]!= ' ' && 
			 position[1]!= ' ' && 
			 position[2]!= ' ' && 
			 position[3]!= ' ' && 
			 position[4]!= ' ' && 
			 position[5]!= ' ' && 
			 position[6]!= ' ' && 
			 position[7]!= ' ' && 
			 position[8]!= ' ')
	{
		printf("Game draw!\n\n");
		asktoplay();
	}
	else 
	{
		// Nothing
	}
}

void playerMove()
{
	int pos;
	printf("Position (1-9): ");
	scanf("%d", &pos);
		
	if ((pos>=1) && (pos<=9)) 
	{
		if ((position[pos-1]=='x') || (position[pos-1]=='o')) 
		{
			printf("This position is not available!\n\n");
			playerMove();
		} 
		else 
		{
			position[pos-1] = 'x';
		}
	} 
	else 
	{
		printf("There are only 1-9 positions\n\n");
		playerMove();
	}
}

void botMove()
{
	int bot;
	bot = rand() % 8;
	if ((position[bot]=='x') || (position[bot]=='o')) 
	{
		botMove();
	} 
	else 
	{
		position[bot] = 'o';
	}
}

main() 
{
	while (conplay) 
	{
		botMove();
		board();
		checkwin();
		playerMove();
		board();
		checkwin();
	}
	
	return 0;
}
