/*************************************************************
 *                                                           *
 * HW04 Q3                                                   *
 * Student Name: Doga UYSAL                                  *
 * Student ID  : 141044039                                   *
 * Date        : 14.03.2015                                  *
 * Points      : 45-50										 *
 *                                                           *
 *************************************************************/
#include <stdio.h> 

#define TRUE 1
#define FALSE 0
#define CHARACTERFILE "Files/Q3/CharacterList.txt"
#define SAMPLEFILE "Files/Q3/Sample.txt"
#define ENCODEDFILE "Files/Q3/XUniversityEncoded.txt"
#define PLAINTEXTFILE "Files/Q3/XUniversityMessage.txt"

void swap_int(int *a, int *b);
void swap_char(char *a, char *b);
void sort(char *a, int a_num, char *b, int b_num, char *c, int c_num);
int is_letter(char c);
int read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3);
void count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3);
void decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3);

int 
main()
{
	FILE *f_character_list_ptr, *f_sample_file_ptr, *f_encoded_ptr,
		*f_plain_text_ptr;
	int character_number;
	char c1, c2, c3;
	int r_test;	

	/* exit program and print error if character list file *
	 * could not be opened to read */
	f_character_list_ptr=fopen(CHARACTERFILE,"r");
	
	if ( f_character_list_ptr==FALSE ){
		printf("Couldn't read character_list file.\n");
		return 0;
	}
	/* call read_character_list function and get return value *
	 * if number of letter read is not equal to three exit    *
	 * program                                                */
	r_test=read_character_list(f_character_list_ptr,&c1,&c2,&c3);
		if (r_test!=3){
			printf("Number Of letter read is not equal to three..!\n");
			return 0;
		}
	/* close character list file */
	fclose(f_character_list_ptr);
	/* exit program and print error if sample file *
	 *could not be opened to read */
	f_sample_file_ptr=fopen(SAMPLEFILE,"r");
			if(f_sample_file_ptr==FALSE){
				printf("Couldn't read sample file.\n");
				return 0;
			}
	/* Call count_letters function and swap letters inside function *
	 * according to number of counts                                */	
	count_letters(f_sample_file_ptr,&c1,&c2,&c3);
	/* close sample file */
	fclose(f_sample_file_ptr);
	/* exit program and print error if encoded file *
	 *could not be opened to read */
	f_encoded_ptr=fopen(ENCODEDFILE,"r");
		if(f_encoded_ptr==FALSE){
			printf("Couldn't read encoded file.\n");
			return 0;
		}
	/* exit program and print error if plain text file *
	 * could not be opened to write */
	f_plain_text_ptr=fopen(PLAINTEXTFILE,"w");
		if(f_plain_text_ptr==FALSE){
			printf("Couldn't read plain text file.\n");
			return 0;
		}
	/* Call decode function */	
	decode(f_encoded_ptr,f_plain_text_ptr,c1,c2,c3);
	/* close encoded and plain text file */
	fclose(f_encoded_ptr);
	fclose(f_plain_text_ptr);

	return 0;
}

/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void swap_int(int *a, int *b)
{
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
}

/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void swap_char(char *a, char *b)
{
	char temp;

	temp=*a;
	*a=*b;
	*b=temp;

}

/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void sort(char *a, int an, char *b, int bn, char *c, int cn)
{		
	if(bn>an){
		swap_char(a,b);
		swap_int(&an,&bn);	
	}
	if(cn>bn){
		swap_char(b,c);
		swap_int(&bn,&cn);
	}
	if(bn>an){
		swap_char(a,b);
		swap_int(&an,&bn);
	}
}

/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int is_letter(char c)
{
	char A='A';
	if (c>=A)
		return TRUE;
	else
		return FALSE;
}

/*************************************************************
 * Read characters from character list file and if character *
 * is letter assign characters to c1, c2 and c3.             *
 * If file has not three letters assign NULL to input char   *
 * by order. For ex. file has two letters assign proper      *
 * letters to c1 and c2 and assign NULL to c3. If file has   *
 * four letters assign c1, c2 and c3 first three letters.    *
 * Return number of letters in character list file.          *
 * Do not forget to count only proper letters with your      *
 * is_letter function. Return number of letters not chars    *
 *************************************************************/
int read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3)
{	
	int counter = 0;
	int e; /*for eof control */
	char character;
	int c_letter; /*is_letter func control*/

	fscanf(f_in_ptr,"%c",&character);
	while (c_letter==FALSE && e!=EOF){
		c_letter=is_letter(character);
		e=fscanf(f_in_ptr,"%c",&character);	
	}
	counter++;
	*c1=character;

	fscanf(f_in_ptr,"%c",&character);
	c_letter=is_letter(character);
	while (c_letter==FALSE && e!=EOF){
		e=fscanf(f_in_ptr,"%c",&character);
		c_letter=is_letter(character);	
	}
	counter++;
	*c2=character;

	fscanf(f_in_ptr,"%c",&character);
	c_letter=is_letter(character);	
	while (c_letter==FALSE && e!=EOF){
		e=fscanf(f_in_ptr,"%c",&character);	
		c_letter=is_letter(character);
	}
	counter++;
	*c3=character;

	return counter;
}

/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3)
{
	int e; /* for eof control*/
	int count_ch1=0, count_ch2=0, count_ch3=0; /*char counters*/ 
	char letter;

	e=fscanf(f_in_ptr,"%c",&letter);
	while(e!=EOF){
		if( letter==*c1 )
			count_ch1++;
		else if (letter==*c2)
			count_ch2++;
		else if (letter==*c3)
			count_ch3++;
		e=fscanf(f_in_ptr,"%c",&letter);
	}
	sort(c1,count_ch1,c2,count_ch2,c3,count_ch3);
}

/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3)
{
	int e; /* for eof control*/
	char letter;	
	int numb_counter=0;	

	e=fscanf(f_in_ptr,"%c",&letter);

	while (e!=EOF){
		while(letter!='0'){
			numb_counter++;
			fscanf(f_in_ptr,"%c",&letter);
		}
		if (numb_counter==0)
			fprintf(f_out_ptr,"%c",c1);
		else if (numb_counter==1)
			fprintf(f_out_ptr,"%c",c2);
		else if (numb_counter==2)
			fprintf(f_out_ptr,"%c",c3);
		
		numb_counter=0;
		e=fscanf(f_in_ptr,"%c",&letter);
	}
}

/*############################################################################*/
/*              End of HW04_Doga_Uysal_141044039_part3.c                      */
/*############################################################################*/
