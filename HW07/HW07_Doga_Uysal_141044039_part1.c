/*************************************************************
 *                                                           *
 * HW07_Part1                                                *
 * Student Name: Doga UYSAL                                  *
 * Student ID  : 141044039                                   *
 * Date        : 10.04.2015                                  *
 *                                                           *
 *************************************************************/


/* Null karakterine kadar recursive seklinde okuma yapip string uzunlugu bulan*
 * func */
int find_size (const char *string)
{
	int size;

	if(string[0]=='\0')
		size=0;
	else{
		size=find_size(&string[1]);
		size++;
	}

	return size;
}

/*String icinde string aramasini karakter karakter yaparak ilerleyen, her *
 *taramadan sonra arama yapilan stringi bir karakter az gondererek tekrar *
 *tarama yapan recursive func*/
int char_number(const char *string, const char *wish_to_find)
{
	int count=0;
	int size1; /*aranan string uzunlugu*/
	int size2; /*icinde arama yapilan string uzunlugu*/
	int i;
	int check=1;

	size2=find_size(string);
	size1=find_size(wish_to_find);
	
/*arama yapilan string istenen string'ten kisa oldugu zaman -1 check ederek*
 * arama islemini sonlandirir*/
	if(size1>size2)
		check=-1;

	for(i=0;i<size1;i++)
		if(string[i]!=wish_to_find[i])
			check=0;
	
	if(check==1){
		count=char_number(&string[1],wish_to_find);	
		count++;
	}
	else if (check==0){
		count=char_number(&string[1],wish_to_find);	
	}


	return count;
}

/*############################################################################*/
/*              End of HW07_Doga_Uysal_141044039_part1.c                      */
/*############################################################################*/
