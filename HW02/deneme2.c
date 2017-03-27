/*############################################################################*/
/*HW02_Doga_Uysal_141044039_part2.c                                           */
/*26.02.2015                                                                  */
/*Doga Uysal 141044039                                                        */

#include <stdio.h>
#include <stdlib.h>

int CalculateGrade (int midterm1, int midterm2, int final);
char LetterGrade(int grade);
double CalculateContribution(char lgrade);


int main ()
{
	char name1, name2, name3, name4, name5; /*inputs for names*/
	char sur1, sur2, sur3, sur4, sur5; /*inputs for surnames*/
	int m1p1, m1p2, m1p3, m1p4, m1p5, m2p1, m2p2, m2p3, m2p4, m2p5;
	int f1, f2, f3, f4, f5; /* inputs for all Midterms and finals*/
	int grade1, grade2, grade3, grade4, grade5; 
	char lgrade1, lgrade2, lgrade3, lgrade4, lgrade5;
	double cont1, cont2, cont3, cont4, cont5;
	FILE *inp, *outp;

	inp=fopen("Students.txt","r");
	outp=fopen("Grades.txt","w");
	
	fscanf(inp,"%c%c%d%d%d\n%c%c%d%d%d\n%c%c%d%d%d\n%c%c%d%d%d\n%c%c%d%d%d", &name1,
	&sur1, &m1p1, &m2p1, &f1, &name2, &sur2, &m1p2, &m2p2, &f2, &name3,
	&sur3, &m1p3, &m2p3, &f3, &name4, &sur4, &m1p4, &m2p4, &f4, &name5, 
	&sur5, &m1p5, &m2p5, &f5);

	/* Calculating each students grade */
	grade1=CalculateGrade(m1p1,m2p1,f1);
	grade2=CalculateGrade(m1p2,m2p2,f2);
	grade3=CalculateGrade(m1p3,m2p3,f3);
	grade4=CalculateGrade(m1p4,m2p4,f4);
	grade5=CalculateGrade(m1p5,m2p5,f5);

	lgrade1=LetterGrade(grade1);
	lgrade2=LetterGrade(grade2);
	lgrade3=LetterGrade(grade3);
	lgrade4=LetterGrade(grade4);
	lgrade5=LetterGrade(grade5);

	cont1=CalculateContribution(lgrade1);
	cont2=CalculateContribution(lgrade2);
	cont3=CalculateContribution(lgrade3);
	cont4=CalculateContribution(lgrade4);
	cont5=CalculateContribution(lgrade5);

	fprintf(outp,"%c %c %d %.2f\n",name1,sur1,grade1,cont1);
	fprintf(outp,"%c %c %d %.2f\n",name2,sur2,grade2,cont2);
	fprintf(outp,"%c %c %d %.2f\n",name3,sur3,grade3,cont3);
	fprintf(outp,"%c %c %d %.2f\n",name4,sur4,grade4,cont4);
	fprintf(outp,"%c %c %d %.2f\n",name5,sur5,grade5,cont5);	

	fclose(inp);
	fclose(outp);
	

	return 0;
}

int CalculateGrade (int midterm1, int midterm2, int final)
{
	
	return ((30.0/100.0)*midterm1)+((30.0/100.0)*midterm2)+((40.0/100.0)*final);
}

char LetterGrade(int grade)
{
	char lgrade, A, B, C, D, F;
	A='A';
	B='B';
	C='C'; 
	D='D'; 
	F='F';

	if (grade>=85)
		lgrade='A' ;
	else if (grade>=70)
		lgrade='B';
	else if (grade>=65)
		lgrade='C';
	else if (grade>=40)
		lgrade='D';
	else 
		lgrade='F';
	
	return lgrade;
}

double CalculateContribution(char lgrade)
{ 
	double cont;
	switch ( lgrade ) 
	{
	case 'A' :	cont=4.0/3.0*20.0;
				break;
	case 'B' :	cont=3.0/3.0*20.0;
				break;
	case 'C' :	cont=2.0/3.0*20.0;
				break;
	case 'D' :	cont=1.0/3.0*20.0;
				break;
	case 'F' :	cont=0.0;
				break;
	} 
	return cont;
}

