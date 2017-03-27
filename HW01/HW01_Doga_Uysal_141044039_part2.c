/*############################################################################*/
/*HW01_Doga_Uysal_141044039_part2.c                                           */
/*22.02.2015                                                                  */
/*Doga Uysal 141044039                                                        */
/*Calculates two unknown of equations and function's result                   */
/*Inputs:                                                                     */
/*	-Coefficients and results of both equation                                */
/*Outputs:                                                                    */
/*	-Value of two unknown and function's result                               */


#include <stdio.h>

/* Function Prototypes*/
double CalculateX();
double CalculateY();
double CalculateF();

int main ()
{
	/*Inputs/outputs for coefficients and results*/
	double x1, x2; //Coefficients of x 
	double y1, y2; //Coefficients of y
	double s1, s2; // Results
	double f1, f2; // Coefficients for function
	double x0, y0, s0 // Outputs
	FILE *inp1, *inp2, *outp;

	inp1=fopen("EqCoefficients.txt","r");
	inp2=fopen("FuncCoefficients.txt","r");
	outp=fopen("Results2.txt","w");

	/* Gathering All inputs */
	fscanf(inp1,"%lf%lf%lf%lf%lf%lf", &x1, &y1, &s1, &x2, &y2, &s2);
	fscanf(inp2,"%lf%lf", &f1, &f2);

	/*Calculating outputs via functions */
	x0=CalculateX(x1, y1, s1, x2, y2, s2);	
	y0=CalculateY(x1, y1, s1, x2, y2, s2);
	s0=CalculateF(x0, y0, f1, f2);

	printf(" The x is %f\n The y is %f\n F(x,y) is %f\n", x0, y0, s0);
	fprintf(outp,"%f %f %f", x0, y0, s0);


	fclose(inp1);
	fclose(inp2);
	fclose(outp);

	return 0;
}


/*Function that calculates y with using all inputs in EqCoefficients.txt */
double CalculateY(double x1, double y1, double z1, double x2, double y2,
	 			  double z2)
{
	double y0;
	y0=((z1*x2)-(z2*x1))/((y1*x2)-(y2*x1));
	return y0;
}

/*Function that calculates x with using all inputs in EqCoefficients.txt*/
double CalculateX(double x1, double y1, double z1, double x2, double y2,
	 			  double z2)
{
	double x0;
	x0=((z1*y2)-(z2*y1))/((x1*y2)-(x2*y1));
	return x0;
}


double CalculateF(double x0, double y0, double f1, double f2)
{
	double f0;
	f0=(x0*f1)+(y0*f2);
	return f0;
}
 

/*############################################################################*/
/*             End of HW01_Doga_Uysal_141044039_part2.c                       */
/*############################################################################*/

