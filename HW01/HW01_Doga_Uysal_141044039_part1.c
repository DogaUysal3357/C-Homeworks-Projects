/*############################################################################*/
/*HW01_Doga_Uysal_141044039_part1.c                                           */
/*19.02.2015                                                                  */
/*Doga Uysal 141044039                                                        */
/*Verilen degerler ile bileske fn hesaplar                                    */
/*Inputs :                                                                    */
/*	-Isleme tabii tutulacak degerler                                          */
/*Outputs :                                                                   */
/*	- fog ve gof bileske fn'lerinin sonuclari                                 */
/*############################################################################*/


#include <stdio.h>
#include <math.h>

/* Sabit Micro tanimi */
#define Y 3

/* Fonksyonlarin prototipleri */
double fo(int x);
double go(int x);
double gof(int x);
double fog(int x);

int main()
{	
	int x, z; // Dosyalardan alinacak degerler
	FILE *inp, *outp; // Output ve input dosyalarinin pointerlari

	// output ve input dosyalarini ac
	inp=fopen("Variables.txt","r");
	outp=fopen("Results1.txt","w");


	/* Dosyadan inputlari alip bileske fn. degerlerini output dosyasina yaz*/
	fscanf(inp," %d %d ", &x, &z);
	fprintf(outp," %f \n %f ", gof(x), fog(z));
	
	// Terminalde gorunecek olan cikti
	printf ("gof(%d) = %f\nfog(%d) = %f \n", x,gof(x),z,fog(z));


	/* output ve input dosyalarini kapat */
	fclose(inp);
	fclose(outp);


	return (0);
}

double fo(int x)
{   // fo  fonksyonun yapacagi matematiksel islemler
	return (pow(sin(x+Y) /x + log(pow(3,x) / (2*x +1)), 2.5));
}

double go(int x)
{   // go fonksyonunun yapacagi matematiksel islemler 
	return (x+1 / ((Y / (2*x)) + x));
}


/* Fonksyonlarin bileskelerinin tanimlandigi fonksyonlar*/
double fog(int x)
{   
	return fo(go(x));
}
double gof(int x)
{ 
	return go(fo(x));
}



/*############################################################################*/
/*             End of HW01_Doga_Uysal_141044039_part1.c                       */
/*############################################################################*/

