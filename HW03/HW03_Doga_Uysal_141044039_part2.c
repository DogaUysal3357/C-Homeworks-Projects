/*############################################################################*/
/*HW03_Doga_Uysal_141044039_part2.c                                           */
/*05.03.2015                                                                  */
/*Doga Uysal 141044039                                                        */
/*Evaluates the vertical distance of the bouncing ball until it reaches the   */
/* limit																      */
/*Inputs :   															      */
/*	-No actual user defined inputs, only randomized numbers                   */
/*Outputs :           														  */
/*	- To console and output file, table of results which includes Rebounching */
/* Height and Total Vertical Distance 										  */
/*############################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define limit 1.00

/* function prototypes*/
int RNG1();
double RNG2();
int count_the_number(int count);
double calculate_the_vertical_distance(double height, double distance);
double calculate_the_new_height(double height, double ratio);

int main()
{
	double first_height=0, ratio=0, current_height=0, distance=0;
	int count=0;	
	FILE *outp;
	
	outp=fopen("Result_Table.txt","w");
	/*assining randomized numbers as an input */
	first_height=RNG1();
	ratio=RNG2();
	current_height=first_height;	
	count=count_the_number(count);
	while ( current_height > limit )
	{	
		/* if it's a stating point, code will print an additional explanation
		 * message. It will be printed only to file.  */
		if (count==1)
		{
			distance=calculate_the_vertical_distance(current_height,
			distance);
			fprintf(outp,"No - The Rebounching -- The Total Vertical Distance"
            "\n\n");
			fprintf(outp,"%d%5c%.3f%7c%.3f\n",count, ' ',current_height, ' ',
			distance);
			printf("%d%5c%.3f%7c%.3f\n",count, ' ',current_height, ' ',
			distance);
			count=count_the_number(count);
			current_height=calculate_the_new_height(current_height,
			ratio);
		}
		else 
		{	/* it calls fnc. 'distance' two times because ball goes all
			 * all the way up and down. After printing all recent results
			 * it calculates new results via functions  */
			distance=calculate_the_vertical_distance(current_height, distance);
			distance=calculate_the_vertical_distance(current_height, distance);	
			fprintf(outp,"%d%5c%.3f%7c%.3f\n",count, ' ',current_height, ' ',
			distance);
			printf("%d%5c%.3f%7c%.3f\n\n",count, ' ',current_height, ' ',
			distance);
			count=count_the_number(count);
			current_height=calculate_the_new_height(current_height,
			ratio);		
		}
	}
	fprintf(outp,"The bouncing isstopped and the task completed...");
	fclose(outp);
	return 0;
}

/* Functions */

/* randomizes a number for first height */
int RNG1 ()
{
	int x;
	srand(time(NULL));
	x=rand()%30+10;
	return x;
}

/* randomizes a number for ratio */
double RNG2 ()
{
	double x;
	srand(time(NULL));
	x=(rand()%4+4)/10.0;
	return x;
}

/* calculates new height by mulriping height by ratio */
double calculate_the_new_height (double height, double ratio)
{
	double new_height;
	new_height=height*ratio;

	return new_height;
}

int count_the_number (int count)
{
	++count;
	return count;
}

/* calculates vertical distance by adding every new height over it */
double calculate_the_vertical_distance (double height, double distance)
{
	distance+=height;
	return distance;	
}

/*############################################################################*/
/*              End of HW03_Doga_Uysal_141044039_part2.c                      */
/*############################################################################*/
