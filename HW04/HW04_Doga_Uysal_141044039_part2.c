/*************************************************************
 *                                                           *
 * HW04 Q2                                                   *
 * Student Name: Doga UYSAL                                  *
 * Student ID  : 141044039                                   *
 * Date        : 14.03.2015                                  *
 * Points      : 15   									     *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define PLAINTEXTFILE "Files/Q2/ReceivedMessage.txt"
#define ENCODEDFILE "Files/Q2/EncodedInput.txt"
#define CRYPTEDINPUT "Files/Q2/CryptedInput.txt"
#define TRUE 1
#define FALSE 0

void decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones);
int decode_message(FILE *f_in_ptr, FILE *f_out_ptr);
int decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

int 
main()
{
	FILE *f_plane_ptr, *f_encoded_ptr, *f_crypted_ptr;

	/* exit program and print error if encrypted text file *
	 * could not be opened to read */
	
	f_crypted_ptr=fopen(CRYPTEDINPUT,"r");
	f_encoded_ptr=fopen(ENCODEDFILE,"w");

	/* exit program and print error if encoded text file *
	 * could not be opened to write */
	
	if ( f_crypted_ptr==FALSE ){
		printf("Couldn't read crypted file.\n");
		return 0;
	}

	if ( f_encoded_ptr==FALSE){
		printf("Couldn't read encoded file.\n");
		return 0;
	}


	decrypt_message(f_crypted_ptr, f_encoded_ptr);

	/* close encrypted and encoded files */

	fclose(f_encoded_ptr);
	fclose(f_crypted_ptr);

	/* exit program and print error if plain text file *
	 * could not be opened to write */
	/* exit program and print error if encoded text file *
	 * could not be opened to read */

	f_encoded_ptr=fopen(ENCODEDFILE,"r");
	f_plane_ptr=fopen(PLAINTEXTFILE,"w");

	if ( f_plane_ptr==FALSE ){
		printf("Couldn't read plain text file.\n");
		return 0;
	}

	if ( f_encoded_ptr==FALSE){
		printf("Couldn't read encoded file.\n");
		return 0;
	}

	decode_message(f_encoded_ptr, f_plane_ptr);

	/* close encoded and plain files */
	fclose(f_encoded_ptr);
	fclose(f_plane_ptr);
	
	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void 
decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones)
{	
	switch (number_of_ones){
		case 0 : fprintf(f_out_ptr,"E");
			break;
		case 1 : fprintf(f_out_ptr,"I");
			break;
		case 2 : fprintf(f_out_ptr," ");
			break;
		case 3 : fprintf(f_out_ptr,"T");
			break;
		case 4 : fprintf(f_out_ptr,"C");
			break;
		case 5 : fprintf(f_out_ptr,"N");
			break;
		case 6 : fprintf(f_out_ptr,"A");
			break;
		case 7 : fprintf(f_out_ptr,"G");
			break;
		case 8 : fprintf(f_out_ptr,"B");
			break;
		case 9 : fprintf(f_out_ptr,"Z");
			break;
		case 10 : fprintf(f_out_ptr,"H");
			break;
		case 11 : fprintf(f_out_ptr,"L");
			break;
		case 12 : fprintf(f_out_ptr,"U");
			break;
		case 13 : fprintf(f_out_ptr,"V");
			break;
		case 14 : fprintf(f_out_ptr,"R");
			break;
		case 15 : fprintf(f_out_ptr,"S");
			break;
		case 16 : fprintf(f_out_ptr,"Y");
			break;
	}
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/
int 
decode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{	
	int counter = 0;
	int numb_counter=0;
	char numb;
	int e; /* for eof control */
	

	while(e!=EOF){
		while ( numb!='0' ){
			numb_counter++;		
			fscanf(f_in_ptr,"%c",&numb);
			counter++;		
		}
	decode_and_write_to_file(f_out_ptr, numb_counter);
	numb_counter=0;
	e=fscanf(f_in_ptr,"%c",&numb);
		
	}

	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int 
decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{

	int counter = 0;
	int e; /* for eof control */
	char crypt;

	e=fscanf(f_in_ptr,"%c",&crypt);
	while(e!=EOF){
		if(crypt=='*'){
			fprintf(f_out_ptr,"1");}
		else if ( crypt=='_'){
			fprintf(f_out_ptr,"0");}
		counter++;
		e=fscanf(f_in_ptr,"%c",&crypt);
	}

	return counter;
}
/*############################################################################*/
/*              End of HW04_Doga_Uysal_141044039_part2.c                      */
/*############################################################################*/
