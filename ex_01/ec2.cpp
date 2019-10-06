// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	// citire
	printf("a = ");
	scanf("%f", &a);

	printf("b = ");
	scanf("%f", &b);
	
	printf("c = ");
	scanf("%f", &c);
	// calcul
		float delta = b * b - 4 * a * c;

		float x1_re, x1_im, x2_re, x2_im;

		if (delta >= 0) {
			x1_re = (-b - sqrt(delta)) / (2 * a);
			x2_re = (-b + sqrt(delta)) / (2 * a);
			x1_im = x2_im = 0;
		}
		else { // delta < 0
			x1_re = -b / (2 * a);
			x1_im = -sqrt(-delta) / (2 * a);
			x2_re = -b / (2 * a);
			x2_im = sqrt(-delta) / (2 * a);
		}

	// afisare
	printf("re = %f, im = %f\n", x1_re, x1_im);
	printf("re = %f, im = %f\n", x2_re, x2_im);

	getchar();
	getchar();

	return 0;
}

