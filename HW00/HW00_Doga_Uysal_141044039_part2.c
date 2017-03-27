/*############################################*/
/*HW00_Doga_Uysal_141044039_part2.c           */
/*13.02.2015                                  */
/*Doga Uysal 141044039                        */
/* Part2 : 2.dereceden polinom carpimi        */

#include <stdio.h>

int main () 
{

	double p11, p12, p13; /* Birinci pol. katsayilari         */
	double p21, p22, p23; /* Ikinci pol. katsayilari          */
	double p31, p32, p33, p34, p35; /* Sonuc pol. katsayilari */

	printf("1. Polinomun katsayilarini derece sirasina gore giriniz :");
	scanf("%lf%lf%lf", &p11, &p12, &p13); 

	printf("2. Polinomun katsayilarini derece sirasina gore giriniz :");
	scanf("%lf%lf%lf", &p21, &p22, &p23);

	/* Sonuc degerlerinin hesaplandigi part*/
	p31=p11*p21;
	p32=p11*p22+p12*p21;
	p33=p11*p23+p12*p22+p13*p21;
	p34=p12*p23+p13*p22;
	p35=p13*p23;

	/* Sonuc polinomunun output'u*/
	printf("Carpma isleminin sonucu : %.3fx^4 + %.3fx^3 ", p31,p32);
	printf("+ %.3fx^2 + %.3fx + %.3f \n", p33,p34,p35);


	return (0);
}


/*#########################################*/
/* HW00_Doga_Uysal_141044039_part2.c  Sonu */
/*#########################################*/


