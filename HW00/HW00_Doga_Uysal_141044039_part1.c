/*#########################################*/
/*HW00_Doga_Uysal_141044039_part1.c        */
/*13.02.2015                               */
/*Doga Uysal 141044039                     */
/* Part1 : HW00'in duzenlenmis hali        */
/* 1.dereceden polinomun integralini almak */

#include <stdio.h>

int main () 
{

	double ia0, ia1; /*girdi polinomunun katsayisi*/
	double p0;       /*sonuc polinomun p(0) degeri*/
	double ra0, ra1, ra2; /* sonuc polinomunun katsayilari*/


	printf("Coktan aza dogru polinomun katsayilarini giriniz :\n");
	scanf("%lf%lf", &ia1, &ia0);

	printf("Sonuc polinomunun P(0) degeri :");
	scanf("%lf", &p0);

	ra2=ia1/2;  /* 1/2 tum degerlerde sifir sonucu verip gerekli 
				 *islemleri karsilamiyordu */
	ra1=ia0;
	ra0=p0;

/*Polinomun tam bir sekilde ciktisinin alinabilmesi icin 2 tane daha placeholder
 * ekledim*/
	printf("Sonuc polinomu : %.3fx^2 + %.3fx + %.3f.\n", ra2, ra1, ra0);  
	return (0);
}


/*#########################################*/
/* HW00_Doga_Uysal_141044039_part1.c  Sonu */
/*#########################################*/
