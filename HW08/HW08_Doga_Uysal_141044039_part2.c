/*****************************************************************
 *                                                               *
 * HW08 P2                                                       *
 * Student Name: Doga UYSAL                                      *
 * Student ID  : 141044039										 *
 * Date        : 19.04.2015                                      *
 *                                                               *
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10
#define STR_SIZE 30

typedef enum {MALE,FEMALE}Gender_t;
typedef enum{JANUARY=1,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,AUGUST,
		SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER}Months_t;

typedef struct {int hour; int minute; }Time_t;
typedef struct {int first_half; int second_half; }TCId_no_t;
typedef struct {TCId_no_t id_no; char name[STR_SIZE]; char surname[STR_SIZE];
				Gender_t gender;} People_t;
typedef struct {int year; Months_t month; int day; Time_t time;}Date_t;
typedef struct {People_t people; Date_t date;}Appointment_t;

/*Kayit yaptiran tum insanlari kayit edip, kac kisi oldugunu return eder*/
int get_people(const char *file_name, People_t people[], int max_size);
/*Tum basvurulari okuyarak kaydeder ve kac baasvuru yapildigini return eder*/
int get_appointments(const char *file_name, Appointment_t appointments[], 
int max_size);
/*Basvurularda bulunan TC'lere gore isimlerin atamasini yapar*/
void write_names(Appointment_t appointments[], int size_app, const People_t 
people[], int size_people);
/*Tum basvurulari gozden gecirerek, ayni tarih ve saate basvuru yapan 2 kisiden
2. basvuruyu yapani siler ve yeni size'i return eder*/
int check_appointments(Appointment_t appointments[], int size);
/*Tarihlerine gore basvurulari siralar*/
void sort_appointments(Appointment_t appointments[], int size);
/*Tum basvurulari dosyaya yazdirir*/
void write_appointments(const char *file_name, Appointment_t appointments[], int size);


int main()
{
	char people_file[STR_SIZE]="People.txt";
	char requests_file[STR_SIZE]="AppointmentReqs.txt";
	char appointments_file[STR_SIZE]="Appointments.txt";
	int size_app=0, size_people=0;
	Appointment_t appointments[MAX_SIZE];
	People_t people[MAX_SIZE];

	size_people=get_people(people_file, people, MAX_SIZE);

	size_app=get_appointments(requests_file, appointments, MAX_SIZE);	

	write_names(appointments, size_app, people, size_people);

	size_app=check_appointments(appointments, size_app);

	sort_appointments(appointments, size_app);

	write_appointments(appointments_file, appointments, size_app);

	return 0;
}

					/****************
					 *	Functions	*
					 ****************/

/*Kayit dosyasinda ki tum insanlari kayit edip, kac kisi oldugunu return eder*/
int get_people(const char *file_name, People_t people[], int max_size)
{
	int size;
	int status=0;
	char gender;
	FILE *inp;
	inp=fopen(file_name,"r");
	
	/*Dosyaya erisilemezse ekrana hata verir.*/
	if(inp==0)
		printf("\aPeople.txt dosyasi bulunamadi");	

	/*Dosyadan dongu icinde okuma yapar */
	for(size=0;status!=EOF && size<max_size-1 ;size++){
		status=fscanf(inp,"%6d%5d %s %s %c", &(people[size].id_no.first_half),
&(people[size].id_no.second_half), people[size].name, people[size].surname,
&gender );
		if(gender=='M')
			people[size].gender = MALE;
		else
			people[size].gender = FEMALE;
		
	}
	
	fclose(inp);
	return size-1; /*EOF degeri yuzunden arttirilan size, 1 azaltilir*/
}

/*Tum basvurulari okuyarak kaydeder ve kac basvuru yapildigini return eder*/
int get_appointments(const char *file_name, Appointment_t appointments[], 
	int max_size)
{	
	int size;
	int status=0;
	int month;
	FILE *inp;
	inp=fopen(file_name,"r");
	if(inp==0)
		printf("AppointmentsReqs.txt dosyasi bulunamadi");

	/*Dosyadan dongu icinde okuma yapar */
	for(size=0;status!=EOF && size<max_size-1;size++){
		status=fscanf(inp,"%6d%5d %d %d %d %d:%d", 
&(appointments[size].people.id_no.first_half),
&(appointments[size].people.id_no.second_half),
&(appointments[size].date.year), &month, 
&(appointments[size].date.day), &(appointments[size].date.time.hour), 
&(appointments[size].date.time.minute) );
		appointments[size].date.month=(Months_t)month;
	}

	fclose(inp);
	return size-1; /*EOF degeri yuzunden arttirilan size, 1 azaltilir*/
}

/*Basvurularda bulunan TC'lere gore isimlerin atamasini yapar*/
void write_names(Appointment_t appointments[], int size_app, 
	const People_t people[], int size_people)
{
	int i=0, j=0;

	/*eger tc numaralari esit ise paket yapisinda ki people memberlarini *
	 * transfer eder*/
	for(i=0;i<size_app;i++)
		for(j=0;j<size_people;j++)
			if((appointments[i].people.id_no.first_half == 
people[j].id_no.first_half) && (appointments[i].people.id_no.second_half ==
people[j].id_no.second_half) ){
				appointments[i].people=people[j];
			}	
}

/*Tum basvurulari gozden gecirerek, ayni tarih ve saate basvuru yapan 2 kisiden
2. basvuruyu yapani siler ve yeni size'i return eder*/
int check_appointments(Appointment_t appointments[], int size)
{
	int i=0,j=0, n=0;
	Appointment_t temp;
	
	/*Sirali sekilde ilk basvurudan baslayarak tarama yapar. Eger ilk deger ile 
	 * ayni tarihte baska bir basvuru varsa o degeri silerek boyutu yeniden
	 * duzenler ve son size'i return eder */
	for(i=0;i<size;i++)
		for(j=i+1;j<size;j++){
			if((appointments[i].date.year==appointments[j].date.year) &&
( appointments[i].date.month == appointments[j].date.month ) && 
( appointments[i].date.day == appointments[j].date.day) && 
( appointments[i].date.time.hour == appointments[j].date.time.hour) && 
( appointments[i].date.time.minute == appointments[j].date.time.minute ) ) {
			
				if(j<size-1){
					for(n=j; n<size-1; n++){
						appointments[n]=appointments[n+1];
					}
					size--;
				}
				else
					size--;
			}	
		}

	return size;
}

/*Tarihlerine gore basvurulari siralar*/
void sort_appointments(Appointment_t appointments[], int size)
{
	Appointment_t temp;
	int i=0,j=0;

	for(j=0;j<size;j++)
		for(i=0;i<size-1;i++)
			if((appointments[i].date.year > appointments[i+1].date.year) || 
( appointments[i].date.month > appointments[i+1].date.month ) || 
( appointments[i].date.day > appointments[i+1].date.day) || 
( appointments[i].date.time.hour > appointments[i+1].date.time.hour) ||
( appointments[i].date.time.minute > appointments[i+1].date.time.minute ) ){
			
				temp=appointments[i];
				appointments[i]=appointments[i+1];
				appointments[i+1]=temp;
		}
}

/*Tum basvurulari duzgun sekilde dosyaya bastirir*/
void write_appointments(const char *file_name, Appointment_t appointments[],
	int size)
{
	int i;
	FILE *inp;

	inp=fopen(file_name,"w");

	for(i=0;i<size;i++){

	fprintf(inp,"%d %d %d %d:%d %d%d %s %s ", appointments[i].date.year, 
 (int)appointments[i].date.month, appointments[i].date.day, 
 appointments[i].date.time.hour, appointments[i].date.time.minute, 
 appointments[i].people.id_no.first_half,
 appointments[i].people.id_no.second_half, appointments[i].people.name,
 appointments[i].people.surname);

	if(appointments[i].people.gender==MALE)
		fprintf(inp,"M\n");
	if(appointments[i].people.gender==FEMALE)
		fprintf(inp,"F\n");
	}
}

/*############################################################################*/
/*              End of HW08_Doga_Uysal_141044039_part2.c                      */
/*############################################################################*/
