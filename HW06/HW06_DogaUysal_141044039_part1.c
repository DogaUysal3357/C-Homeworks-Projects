/*************************************************************
 *                                                           *
 * HW06_Part1                                                *
 * Student Name: Doga UYSAL                                  *
 * Student ID  : 141044039                                   *
 * Date        : 05.04.2015                                  *
 *                                                           *
 *************************************************************/

#include <stdio.h>
#include <string.h>

#define N_EMP 4
#define N_DAY 7
#define SIZE 100

typedef enum {Ali, Ayse, Fatma, Mehmet} employee;
typedef enum {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday} day;

void read_matrix(const char *file_name, int m[N_EMP][N_DAY]);
void create_work_plan(int job_schedule[N_EMP][N_DAY], int m[N_EMP][N_DAY]);
employee find_the_employer_of_the_day(int work_schedule[N_EMP][N_DAY], day day_name);
employee find_the_employer_of_the_week(int work_schedule[N_EMP][N_DAY]);
void report(const char *file_name, int job_scheduling[N_EMP][N_DAY]);

int main()
{
	char input[15]="energies.txt";
	char output[13]="report.txt";
	int job_energies[N_EMP][N_DAY];
	int work_schedule[N_EMP][N_DAY];
	int i,j;

	read_matrix(input,job_energies);
/*
	for(i=0;i<N_EMP;i++){
		for(j=0;j<N_DAY;j++)
			printf("%d ", job_energies[i][j]);
		printf("\n");
	}

*/
	create_work_plan(job_energies, work_schedule);

	report (output, work_schedule);

	return 0;
}

void read_matrix(const char *file_name, int m[N_EMP][N_DAY])
{
	FILE *inp;
	inp=fopen(file_name,"r");
	int i, j;


	for(j=0;j<N_DAY;j++)
		for(i=0;i<N_EMP;i++)
			fscanf(inp,"%d", &m[i][j]);

	fclose(inp);
}

void sort(int js[][N_DAY], int k)
{
	int i,j;
	int temp;

	for(i=0;i<N_EMP;i++){
	    for(j=i+1;j<N_EMP;j++){
	        if(js[i][k]>js[j][k]){
	            temp=js[i][k];
	            js[i][k]=js[j][k];
	            js[j][k]=temp;
			}
		}
	}
}

void index_finder(int array[], int n, int *frst_ind, int *scnd_ind, 
				  int *thrd_ind,int *frth_ind)
{
	int i; /*for counter*/
	int	frst_max=0, scnd_max=0, thrd_max=0, frth_max=0;	
	
	for(i=0;i<n;i++){
		if (array[i]>frst_max)
			frst_max=array[i];
			*frst_ind=i;
		}

	for(i=0;i<n;i++){
		if( frst_max>array[i] && array[i]>scnd_max ){
			scnd_max=array[i];
			*scnd_ind=i;
		}
		if(frst_max==array[i] && *frst_ind!=i){
			*scnd_ind=i;
		}
	}

	for(i=0;i<n;i++){
		if( scnd_max>array[i] && array[i]>thrd_max ){
			thrd_max=array[i];
			*thrd_ind=i;
		}		
		if(scnd_max==array[i] && *scnd_ind!=i){
			*thrd_ind=i;
		}
	}

	for(i=0;i<n;i++){
		if( thrd_max>array[i] && array[i]>frth_max ){
			frth_max=array[i];
			*frth_ind=i;
		}
		if(thrd_max==array[i] && *thrd_ind!=i){
			*frth_ind=i;
		}
	}
}
	
void create_work_plan(int js[N_EMP][N_DAY], int m[N_EMP][N_DAY])
{
	int i, j, k;
	int toplam[N_EMP];
	int frst_ind=0, scnd_ind=0, thrd_ind=0, frth_ind=0;

	for(i=0;i<N_EMP;i++){
		m[i][0]=js[i][0];
	}
	toplam[0]=m[0][0];
	toplam[1]=m[1][0];
	toplam[2]=m[2][0];
	toplam[3]=m[3][0];	
	

	for(j=1;j<N_DAY;j++){
		sort(js,j);
		index_finder(toplam, N_EMP, &frst_ind, &scnd_ind, &thrd_ind, &frth_ind);
		m[frst_ind][j]=js[3][j];
		m[scnd_ind][j]=js[2][j];
		m[thrd_ind][j]=js[1][j];
		m[frth_ind][j]=js[0][j];
		for(k=0;k<N_EMP;k++)
			toplam[k]+=m[k][j];	
	}

}

employee find_the_employer_of_the_day(int work_schedule[N_EMP][N_DAY],
									  day day_name){

	employee daily_best=Ali;
	int i;	
	int max=0;

	for(i=0;i<N_EMP;i++){
		if (work_schedule[i][day_name]>max){
			max=work_schedule[i][day_name];
			daily_best=i;
		}
	}

	return daily_best;
}

employee find_the_employer_of_the_week(int work_schedule[N_EMP][N_DAY])
{
	int toplam[N_EMP];
	int i, j;
	int frst_ind, scnd_ind, thrd_ind, frth_ind;
	employee weekly_best=Ali;

	for(i=0;i<N_EMP;i++){	
		toplam[i]=0;
		for(j=0;j<N_DAY;j++)
			toplam[i]+=work_schedule[i][j];
	}
	
	index_finder(toplam, N_EMP, &frst_ind, &scnd_ind, &thrd_ind, &frth_ind);
	weekly_best=frst_ind;

	return weekly_best;
}


void report(const char *file_name, int ws[N_EMP][N_DAY])
{
	int i, k;
	//char best[]="The best employer of ";
	char dys[N_DAY][SIZE];
	strcpy(dys[0], "Monday");
	strcpy(dys[1], "Tuesday");
	strcpy(dys[2], "Wednesday");
	strcpy(dys[3], "Thursday");
	strcpy(dys[4], "Friday");
	strcpy(dys[5], "Saturday");
	strcpy(dys[6], "Sunday");
	char employe[N_EMP][SIZE];
	strcpy(employe[0], "Ali");
	strcpy(employe[1],"Ayse");
	strcpy(employe[2],"Fatma");
	strcpy(employe[3],"Mehmet");	
	FILE *outp;
	outp=fopen(file_name,"w");
		
	fprintf(outp,"%6cMonday%3cTuesday%3cWednesday%3cThursday%3cFriday%3c"
	"Saturday%3cSunday\n\n",' ',' ',' ',' ',' ',' ',' ');
	fprintf(outp,"Ali");
	for(i=0;i<N_DAY;i++)
		fprintf(outp,"%6c%d",' ',ws[Ali][i]); 
	fprintf(outp,"\n");
	fprintf(outp,"Ayse");
	for(i=0;i<N_DAY;i++)
		fprintf(outp,"%6c%d",' ',ws[Ayse][i]); 
	fprintf(outp,"\n");
	fprintf(outp,"Fatma");
	for(i=0;i<N_DAY;i++)
		fprintf(outp,"%6c%d",' ',ws[Fatma][i]);
	fprintf(outp,"\n");
	fprintf(outp,"Mehmet");
	for(i=0;i<N_DAY;i++)
		fprintf(outp,"%6c%d",' ',ws[Mehmet][i]);
	fprintf(outp,"\n");
	
	for(i=0;i<N_DAY;i++){
	k=find_the_employer_of_the_day(ws,i);
	fprintf(outp," The best employer of %s : %s\n\n",dys[i], employe[k]);
	}
		
	k=find_the_employer_of_the_week(ws);
	fprintf(outp," The best employer of the week is %s. Congratulations %s",
	employe[k], employe[k] );

	(outp);
}


/*############################################################################*/
/*              End of HW06_Doga_Uysal_141044039_part1c                      */
/*############################################################################*/
