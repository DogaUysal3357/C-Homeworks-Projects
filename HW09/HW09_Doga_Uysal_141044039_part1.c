
#include <stdio.h>
#include <string.h>
#define STR_SIZE 30
#define CMB_SIZE 5

typedef struct {
	char name[STR_SIZE];
	char surname[STR_SIZE];
	char department[STR_SIZE];
	char class1[STR_SIZE];
	char class2[STR_SIZE];
	double salary;} type_I;

typedef struct {
	char name[STR_SIZE];
	char surname[STR_SIZE];
	double salary;
	char degree;
	} type_E;

typedef union {
	type_I Instructor;
	type_E Employee;
	} union_type;

typedef struct {
	char people_type;
	union_type union_t;
	} combine_type;





int main()
{
	combine_type person_info[CMB_SIZE];



}






					/***********
					 *Functions*
					 ***********/





combine_type salary_rise(combine_type person_info){


	if (person_info.people_type == 'I'){
		person_info.union_t.type_I.salary +=
 (person_info.union_t.type_I.salary)*5.0/100.0;
		person_info.union_t.type_I.salary +=
 (person_info.union_t.type_I.salary)*5.3/100.0;
	}

	else 
		switch (person_info.union_t.type_E.degree){

		case 'a':
		case 'A': 
				person_info.union_t.type_E.salary += 
 person_info.union_t.type_E.salary*17.5/100.0;
				break;
		case 'b':
		case 'B':
				person_info.union_t.type_E.salary += 
 person_info.union_t.type_E.salary*12.0/100.0;
				break;
		case 'c':
		case 'C':
				person_info.union_t.type_E.salary += 
 person_info.union_t.type_E.salary*9.0/100.0;
				break;
		}

	return person_info;
}



