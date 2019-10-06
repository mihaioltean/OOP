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
void rezolva(t_ecuatie_grad2& ec2)
{
	float delta = ec2.coeficienti.b * ec2.coeficienti.b - 4 * ec2.coeficienti.a * ec2.coeficienti.c;

	if (delta >= 0) {
		ec2.solutii.x1.re = (-ec2.coeficienti.b - sqrt(delta)) / (2 * ec2.coeficienti.a);
		ec2.solutii.x2.re = (-ec2.coeficienti.b + sqrt(delta)) / (2 * ec2.coeficienti.a);
		ec2.solutii.x1.im = ec2.solutii.x2.im = 0;
	}
	else { // delta < 0
		ec2.solutii.x1.re = -ec2.coeficienti.b / (2 * ec2.coeficienti.a);
		ec2.solutii.x1.im = -sqrt(-delta) / (2 * ec2.coeficienti.a);
		ec2.solutii.x2.re = -ec2.coeficienti.b / (2 * ec2.coeficienti.a);
		ec2.solutii.x2.im = sqrt(-delta) / (2 * ec2.coeficienti.a);
	}
}
//--------------------------------
void afiseaza(t_solutii solutii)
{
	printf("re = %f, im = %f\n", solutii.x1.re, solutii.x1.im);
	printf("re = %f, im = %f\n", solutii.x2.re, solutii.x2.im);
}
//--------------------------------

