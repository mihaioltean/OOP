#include <stdio.h>
#include <math.h>

#include "ec2.h"

//--------------------------------
t_ecuatie_grad2::t_ecuatie_grad2()
{
	coeficienti.a = coeficienti.b = coeficienti.c = 0;
	solutii.x1.re = solutii.x1.im = solutii.x2.re = solutii.x2.im = 0;
}
//--------------------------------
t_ecuatie_grad2::t_ecuatie_grad2(float a, float b, float c)
{
	coeficienti.a = a;
	coeficienti.b = b;
	coeficienti.c = c;
}
//--------------------------------
void t_ecuatie_grad2::citeste(void)
{
	printf("a = ");
	scanf("%f", &coeficienti.a);

	printf("b = ");
	scanf("%f", &coeficienti.b);

	printf("c = ");
	scanf("%f", &coeficienti.c);
}
//--------------------------------
void t_ecuatie_grad2::rezolva(void)
{
	float delta = coeficienti.b * coeficienti.b - 4 * coeficienti.a * coeficienti.c;

	if (delta >= 0) {
		solutii.x1.re = (-coeficienti.b - sqrt(delta)) / (2 * coeficienti.a);
		solutii.x2.re = (-coeficienti.b + sqrt(delta)) / (2 * coeficienti.a);
		solutii.x1.im = solutii.x2.im = 0;
	}
	else { // delta < 0
		solutii.x1.re = -coeficienti.b / (2 * coeficienti.a);
		solutii.x1.im = -sqrt(-delta) / (2 * coeficienti.a);
		solutii.x2.re = -coeficienti.b / (2 * coeficienti.a);
		solutii.x2.im = sqrt(-delta) / (2 * coeficienti.a);
	}
}
//--------------------------------
void t_ecuatie_grad2::afiseaza(void)
{
	printf("re = %f, im = %f\n", solutii.x1.re, solutii.x1.im);
	printf("re = %f, im = %f\n", solutii.x2.re, solutii.x2.im);
}
//--------------------------------

