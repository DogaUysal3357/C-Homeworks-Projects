/*****************************************************************
 *                                                               *
 * HW04 Q1                                                       *
 * Student Name: Doga UYSAL                                      *
 * Student ID  : 141044039										 *
 * Date        : 12.03.2015                                      *
 * Points      : 25-30   									     *
 *                                                               *
 ****************************************************************/
#include <stdio.h>

#define PLAINTEXTFILE "Files/Q1/PlainMessagesToSent.txt"
#define ENCODEDFILE "Files/Q1/EncodedMessages.txt"
#define CRYPTEDFILE "Files/Q1/CryptedMessages.txt"
#define FALSE 0
#define TRUE 1


void encode_and_write_to_file(FILE *f_out_ptr, char character);
int encode_message(FILE *f_in_ptr, FILE *f_out_ptr);
int crypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

int 
main()
{
	FILE *f_plane_ptr, *f_encoded_ptr, *f_crypted_ptr;

	/* exit program and print error if plain text file *
	 * could not be opened to read */
	
	f_plane_ptr=fopen(PLAINTEXTFILE,"r");
		if ( f_plane_ptr==FALSE )
		{	printf(" Couldn't reach plain file \n");
			return 0;
		}

	/* exit program and print error if encoded text file *
	 * could not be opened to write */
	f_encoded_ptr=fopen(ENCODEDFILE,"w");
		if ( f_encoded_ptr==FALSE )
		{	printf(" Couldn't reach encode file \n");
			return 0;
		}

	encode_message(f_plane_ptr, f_encoded_ptr);

	/* close plain and encoded files */
	fclose(f_plane_ptr);
	fclose(f_encoded_ptr);

	/* exit program and print error if encoded text file *
	 * could not be opened to read */
		f_encoded_ptr=fopen(ENCODEDFILE,"r");
		if ( f_encoded_ptr==FALSE )
		{	printf(" Couldn't reach encode file \n");
			return 0;
		}
	/* exit program and print error if crypted text file *
	 * could not be opened to write */	
	f_crypted_ptr=fopen(CRYPTEDFILE,"w");
		if ( f_crypted_ptr==FALSE )
		{	printf(" Couldn't reach crypted file \n");
			return 0;
		}
	
	crypt_message(f_encoded_ptr, f_crypted_ptr);

	/* close crypted and encoded files */
	fclose(f_encoded_ptr);
	fclose(f_crypted_ptr);

	return 0;
}
/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void 
encode_and_write_to_file(FILE *f_out_ptr, char character)
{
	int count;

	switch (character)
	{
	case 'E' : count=0;
				break;
	case 'I' : count=1;
				break;
	case ' ' : count=2;
				break;
	case 'T' : count=3;
				break;
	case 'C' : count=4;
				break;
	case 'N' : count=5;
				break;
	case 'A' : count=6;
				break;
	case 'G' : count=7;
				break;
	case 'B' : count=8;
				break;
	case 'Z' : count=9;
				break;
	case 'H' : count=10;
				break;
	case 'L' : count=11;
				break;
	case 'U' : count=12;
				break;
	case 'V' : count=13;
				break;
	case 'R' : count=14;
				break;
	case 'S' : count=15;
				break;
	case 'Y' : count=16;
				break;
	}
	
	while ( count!=0 )
	{	fprintf(f_out_ptr,"1");
		count--;
	}
	
	fprintf(f_out_ptr,"0");
}
/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int 
encode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	int counter = 0, e;
	char character;
		
	e=fscanf(f_in_ptr,"%c",&character);
	counter++;
	while (e!=EOF)
	{
		encode_and_write_to_file(f_out_ptr, character);
		e=fscanf(f_in_ptr,"%c",&character);
		counter++;
	}
	return counter;
}
/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return number of characters read from encoded text file   *
 *************************************************************/
int 
crypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	int counter = 0;
	int counter_for_hyphen=0;	
	int e=0;
	char encoded_mess;

	e=fscanf(f_in_ptr,"%c",&encoded_mess);
	
	while (e!=EOF)
	{
		if ( encoded_mess=='1' )
			fprintf(f_out_ptr,"*");
		else
			fprintf(f_out_ptr,"_");
	counter_for_hyphen++;
	counter++;	

	if ( counter_for_hyphen==5)
		fprintf(f_out_ptr,"-");
	else if (counter_for_hyphen==9 )
		fprintf(f_out_ptr,"-");
	else if (counter_for_hyphen==12 )
		fprintf(f_out_ptr,"-");
	else if (counter_for_hyphen==14 )
		fprintf(f_out_ptr,"-");
	else if (counter_for_hyphen==15 )
		 fprintf(f_out_ptr,"-");

	if ( counter_for_hyphen==15 )
		counter_for_hyphen=0;

	e=fscanf(f_in_ptr,"%c",&encoded_mess);	
	}

	return counter;
}
/*############################################################################*/
/*              End of HW04_Doga_Uysal_141044039_part1.c                      */
/*############################################################################*/
