#include <stdio.h>
#include <math.h>

#include "ec2.h"

//--------------------------------
void citeste(t_coeficienti &coeficienti)
{
	printf("a = ");
	scanf("%f", &coeficienti.a);

	printf("b = ");
	scanf("%f", &coeficienti.b);

	printf("c = ");
	scanf("%f", &coeficienti.c);
}
//--------------------------------
void rezolva(t_coeficienti coeficienti, t_solutie &x1, t_solutie &x2)
{
	float delta = coeficienti.b * coeficienti.b - 4 * coeficienti.a * coeficienti.c;

	if (delta >= 0) {
		x1.re = (-coeficienti.b - sqrt(delta)) / (2 * coeficienti.a);
		x2.re = (-coeficienti.b + sqrt(delta)) / (2 * coeficienti.a);
		x1.im = x2.im = 0;
	}
	else { // delta < 0
		x1.re = -coeficienti.b / (2 * coeficienti.a);
		x1.im = -sqrt(-delta) / (2 * coeficienti.a);
		x2.re = -coeficienti.b / (2 * coeficienti.a);
		x2.im = sqrt(-delta) / (2 * coeficienti.a);
	}
}
//--------------------------------
void afiseaza(t_solutie x1, t_solutie x2)
{
	printf("re = %f, im = %f\n", x1.re, x1.im);
	printf("re = %f, im = %f\n", x2.re, x2.im);
}
//--------------------------------

