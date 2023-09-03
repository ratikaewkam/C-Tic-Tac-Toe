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
	}
	else if (position[0] != ' ' && 
			 position[1] != ' ' && 
			 position[2] != ' ' && 
			 position[3] != ' ' && 
			 position[4] != ' ' && 
			 position[5] != ' ' && 
			 position[6] != ' ' && 
			 position[7] != ' ' && 
			 position[8] != ' ')
	{
		printf("Game draw!\n\n");
	}
	else 
	{
		// Nothing
	}
}

main() 
{
	int pos;
	
	while (conplay) 
	{
		printf("Position (1-9): ");
		scanf("%d", &pos);
		
		if ((pos>=1) && (pos<=9)) 
		{
			if ((position[pos-1]=='x') || (position[pos]-1=='o')) 
			{
				printf("This position is not available!\n\n");
			} 
			else 
			{
				position[pos-1] = 'x';
				board();
				checkwin();
			}
		} 
		else 
		{
			printf("There are only 1-9 positions\n\n");
		}
	}
	
	return 0;
}
