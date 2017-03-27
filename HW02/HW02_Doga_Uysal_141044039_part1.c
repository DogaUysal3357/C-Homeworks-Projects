/*############################################################################*/
/*HW02_Doga_Uysal_141044039_part1.c                                           */
/*25.02.2015                                                                  */
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

	number=RNG();
	printf("Guess a number between 1 to 10 : ");
	scanf("%d",&guess);
	
	diff=CalculateTheDifference(guess, number);
	/* if player guesses the number at first try, game ends*/
	if (diff==0)
		printf(" Congratulations, You Win.!\n");
	else
	{	WarnThePlayer(diff);

		printf("You have a second chance to guess.. Try Again :");
		scanf("%d",&guess);
	
		diff=CalculateTheDifference(guess, number);
		WarnThePlayer(diff);
	}

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
/*              End of HW02_Doga_Uysal_141044039_part1.c                      */
/*############################################################################*/
