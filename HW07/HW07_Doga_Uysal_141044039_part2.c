/*************************************************************
 *                                                           *
 * HW07_Part2                                                *
 * Student Name: Doga UYSAL                                  *
 * Student ID  : 141044039                                   *
 * Date        : 10.04.2015                                  *
 *                                                           *
 *************************************************************/
#include <stdio.h>

/* verilen verilerin komkbinasyonunu hesaplar */
int combination (int n, int k);
/*merdiven basamaklarinin kac farkli sekilde cikalabilecegini hesaplar*/
int ways (int n);

int main ()
{
	int n=0;/*kullanicidan alinacak basamak sayisi*/
	int res=0; /*kac farkli sekilde cikilabileceginin sonucu*/

	printf("Cikilacak basamak sayisini giriniz : \n>");
	scanf("%d", &n);
	
	res=ways(n);

	printf("\n%d farkli sekilde cikilabilir.\n", res);	
	
	return 0;
} 

/*Kombinasyon hesaplamasi yapan recursive fonksyon. */
int combination (int n, int k)
{
	int result;

	if (n==k || k==0)
		result = 1;
	else 
		result=combination(n-1,k-1)+combination(n-1,k);

	return result;
}

/*Basamaklari cikarken 2'li cikma durumlarini hesaplayan ve hepsinin         *
 * kombinasyonlarini teker teker combination fonksyonunu cagirarak hesaplayan*
 * fonksyon.*/
int all_combinations(int n, int k)
{
	int result;

	if (n==k)
		result=1;
	else if (n==k+1)
		result=combination(n,k);	
	else 
		result=all_combinations(n-1,k+1)+combination(n,k);

	return result;
}

/*Kac farkli sekilde cikilabilecegini return eden fonksyon*/
int ways (int n)
{
	int res;
	res=all_combinations(n,0);
	return res;

}

/*############################################################################*/
/*              End of HW07_Doga_Uysal_141044039_part2.c                      */
/*############################################################################*/
