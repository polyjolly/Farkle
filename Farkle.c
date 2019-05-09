#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# include <stdbool.h>

char InputUserRoll(); /*Asks User to Roll or not */
int DiceRoll(); /*Generates Random Numbers on Dice 1-6*/
int CalcDuplicates(int Die[6]); /*Checks and gets scores if there are three of a kind*/
bool CalcWin(int Player, int Computer); /*Calculates and displays Winning Player*/



int main(void) 
{
	char command;
	bool win = false;
	int Player_Score = 0, Computer_Score = 0;
	srand(time(NULL));
	int i, User_Roll[6], Computer_Roll[6];  	
	
	printf("\tWELCOME TO A GAME OF FARKLE!\n");
	

	while (!win)
	{

	command = InputUserRoll();
	
	if (command == 'Y' || command == 'y')
	{
	
	
	for (i = 0; i < 6; i++)
	{
		User_Roll[i] = DiceRoll();	
	}
	
	printf("\tPLAYER\n\n");
	printf("First Roll:  %d\n", User_Roll[0]);
	printf("Second Roll: %d\n", User_Roll[1]);
	printf("Third Roll:  %d\n", User_Roll[2]);
	printf("Fourth Roll: %d\n", User_Roll[3]);
	printf("Fifth Roll:  %d\n", User_Roll[4]);
	printf("Sixth Roll:  %d\n\n", User_Roll[5]);
	
	for (i = 0; i < 6; i++)
	{
		Computer_Roll[i] = DiceRoll();	
	}
	
	printf("\tCOMPUTER\n\n");
	printf("First Roll:  %d\n", Computer_Roll[0]);
	printf("Second Roll: %d\n", Computer_Roll[1]);
	printf("Third Roll:  %d\n", Computer_Roll[2]);
	printf("Fourth Roll: %d\n", Computer_Roll[3]);
	printf("Fifth Roll:  %d\n", Computer_Roll[4]);
	printf("Sixth Roll:  %d\n\n", Computer_Roll[5]);
	
	printf("Player Points Earned: %d \tComputer Points Earned: %d\n", CalcDuplicates(User_Roll), CalcDuplicates(Computer_Roll));
	printf("Player Total Score: %d \tComputer Total Score: %d\n", (Player_Score += CalcDuplicates(User_Roll)), (Computer_Score += CalcDuplicates(Computer_Roll)));
	}
	else if (command == 'N' || command == 'n')
	{
		printf("WAITING FOR PLAYER...\n");
	}
	else printf("INVALID INPUT TRY AGAIN!\n");

	win = CalcWin(Player_Score, Computer_Score);
	
}



	system("PAUSE");
	return 0;
}
	
int DiceRoll()
{	
	return (rand() % 6) + 1;		
}

int CalcDuplicates(int Die[6])
{
	int total_score = 0;
	int count[6] = {0,0,0,0,0,0};
	int i;
	
	for (i = 0; i < 6; i++)
	{
			if (Die[i] == 1)
			{
				count[0]++;
				total_score += 100;
				if(count[0] == 3 || count[0] == 6) (total_score += 700);	
			}
			if (Die[i] == 2)
			{
				count[1]++;
				if (count[1] == 3 || count[1] == 6) total_score += 200;
			}
			if (Die[i] == 3)
			{
				count[2]++;
				if (count[2] == 3 || count[2] == 6) total_score += 300;
			}
			if (Die[i] == 4)
			{
				count[3]++;
				if (count[3] == 3 || count[3] == 6) total_score += 400;
			}
			if (Die[i] == 5)
			{
				count[4]++;
				total_score += 50;
				if(count[4] == 3 || count[4] == 6) (total_score += 350);
			}
			if (Die[i] == 6)
			{
				count[5]++;
				if (count[5] == 3 || count[5] == 6) total_score += 600;
				
			}
			
			
	}
	
	return total_score;	
}
bool CalcWin(int Player, int Computer)
{	
	if (Player >= 5000 && Computer < 5000) 
	{
	printf("PLAYER WINS!\n");
	return true;	
	}
	else if (Computer >= 5000 && Player < 5000) 
	{
	printf("COMPUTER WINS!\n");
	 return true;	
	}
	else return false;	
}
char InputUserRoll()
{
	char input;
	printf("Would You Like To Roll?(y/n): ");
	scanf(" %c", &input);
	return input;
}



