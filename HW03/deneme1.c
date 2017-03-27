/*############################################################################*/
/*HW03_Doga_Uysal_141044039_part1.c                                           */
/*03.03.2015                                                                  */
/*Doga Uysal 141044039                                                        */
/*Generates a random number to let the player guess it                        */
/*Input : Player guessed integer numbers                                      */
/*Outputs : Warnings about how close the guess is                             */
/*############################################################################*/

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int CalculateTheDifference();
void WarnThePlayer();
int RNG();

int main()
{
	int guess, number, diff; 
	char choice, choice1;
	number=RNG();

	printf("Do you wanna play a game, P/E ?");
	scanf("%c",&choice);	

	if (choice == 'p' || choice == 'P')
		
		for ( ; choice1 != 'P' || choice1 != 'p'; scanf("%c",&choice1)) 
		{
		printf("Guess a number between 1 to 10 : ");
		scanf("%d",&guess);
		diff=CalculateTheDifference(guess, number);
		/* if player guesses the number at first try, game ends*/
		if (diff==0)
			printf("Congratulations, You Win.!\n");
		else
		{	
			while (diff!=0)
			{
			WarnThePlayer(diff);
			printf("Try Again :");
			scanf("%d",&guess);
			diff=CalculateTheDifference(guess, number);
			}
			printf("Congratulations, You Win.!\n\n");
		}

		printf("Want to play again, P/E ?\n");
		}
	else if ( choice == 'e' || choice == 'E' )
		printf("ok, come back when you want to play\n");
	
	else
		printf("Wrong entry. You don't deserve to play this game..!\n");


	return 0;

}

/* Calculates difference between guess and number to warn the player */
int CalculateTheDifference(int x, int y)
{
	int diff, temp;
	if (x>=y)
		diff=x-y;
	else{
		temp=y;
		y=x;
		x=temp;
		diff=x-y;}
	return (diff);
}

/* Function that warns the player about how close his/her guess is */
void WarnThePlayer(int x)
{ 
	if (x>=5)
		printf("You are too far from the number\n");
	else if (x>=3)
		printf("You are far from the number\n");
	else if (0<x<=2)
		printf("You are close to the number\n");
	else
		printf(" Congratulations..!\n");
}

/* Function that randomizes a number between 1-10 */
int RNG ()
{
	int x;
	srand(time(NULL));
	x=rand()%9+1;
	return x;
}

/*############################################################################*/
/*              End of HW03_Doga_Uysal_141044039_part1.c                      */
/*############################################################################*/
