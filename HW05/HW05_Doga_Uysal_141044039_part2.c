/*************************************************************
 *                                                           *
 * HW05_Part2                                                *
 * Student Name: Doga UYSAL                                  *
 * Student ID  : 141044039                                   *
 * Date        : 21.03.2015                                  *
 *                                                           *
 *************************************************************/
#include <stdio.h>

typedef enum { FALSE, TRUE } bool;
int max_array(int array[], int n);
int second_max_array(int array[],int n);
int sum_all_array(int array[], int n);
int count_array(int array[], int n, int value);
bool search_array (int array[], int n, int value);
#define N 9 /*array size*/

int main()
{
	int myarray[N]={6,8,3,3,12,8,3,8,2};
	int	max; /*maximum value*/
	int	sec_max; /*second max value*/
	int	sum; /*sum of all array*/
	int	count; /*count of a value*/
	int	value=0;

	max=max_array(myarray,N);
	printf("Maximum value in array is %d\n\n", max);

	sec_max=second_max_array(myarray,N);
	printf("Second maximum value in array is %d\n\n",sec_max);

	sum=sum_all_array(myarray, N);
	printf("Sum of all array is %d\n\n", sum);
	
	printf("Please enter a value for counting :");
	scanf("%d",&value);
	
	count=count_array(myarray, N, value);
	if ( count!=0 )
		printf("\nCount of value %d is %d\n\n", value, count);
	else
		printf("\nThere is no %d in this array\n\n", value);


	printf("Please enter a value for searching : ");
	scanf("%d", &value);
	search_array(myarray, N, value);

	return 0;
}



/* Functions */

/*Finds max value of an array in a loop*/
int max_array(int array[], int n)
{
	int i; /*for counter*/
	int	max=0; /*max value*/
	
	max=array[0];
	for(i=1;i<n;i++){
		if (array[i]>max)
			max=array[i];
		}
	
	return max;
}

/*2. max degerini, onceden atanmis bir ikincil max ve mevcut en buyuk max deger arasina deger bularak atar*/
int second_max_array(int array[], int n)
{
	int i=0; /*for counter*/
	int	max=0; /*max value*/
	int	sec_max=0; /*second max value*/

	max=max_array(array,n);
	sec_max=array[0];
	for(i=0;i<n;i++){
		if( max>array[i] && array[i]>sec_max ){
			sec_max=array[i];
		}
	}

	return sec_max;	
}

int sum_all_array(int array[], int n)
{
	int sum=0;/*sum of all array*/
	int i;/*counter*/

	for(i=0;i<n;i++){
		sum+=array[i];}

	return sum;
}
/*Counts wanted value*/
int count_array(int array[], int n, int value)
{
	int count;
	int i;

	for(i=0;i<n;i++){
		if ( array[i]==value)
		count++;
	}
	
	return count;
}

/*searchs wanted value in array, if the value isn't in array, prints a warning */
bool search_array(int array[], int n, int value)
{
	int i;
	int check=-1; /*check value for is there any requested value in array*/

	for(i=0;i<n;i++){
		if(value==array[i]){
			printf("\n%d is at [%d]\n", value, i);		
			check=i;
		}
	}

	if (check!=-1)
		return TRUE;
	else {
		printf("There is no requested value in this array.\n");
		return FALSE;
	}
}

/*############################################################################*/
/*              End of HW05_Doga_Uysal_141044039_part2.c                      */
/*############################################################################*/
