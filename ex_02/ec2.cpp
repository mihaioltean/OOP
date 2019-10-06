// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

//--------------------------------
void citeste(float &aaa, float &bbb, float &ccc)
{
	printf("a = ");
	scanf("%f", &aaa);

	printf("b = ");
	scanf("%f", &bbb);

	printf("c = ");
	scanf("%f", &ccc);
}
//--------------------------------
void rezolva(float a, float b, float c, 
	float &x1_re, float &x1_im, float &x2_re, float &x2_im)
{
	float delta = b * b - 4 * a * c;

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
}
//--------------------------------
void afiseaza(float x1_re, float x1_im, float x2_re, float x2_im)
{
	printf("re = %f, im = %f\n", x1_re, x1_im);
	printf("re = %f, im = %f\n", x2_re, x2_im);
}
//--------------------------------
int main()
{
	float a, b, c;
	float x1_re, x1_im, x2_re, x2_im;

	citeste(a, b, c);
	rezolva(a, b, c, x1_re, x1_im, x2_re, x2_im);
	afiseaza(x1_re, x1_im, x2_re, x2_im);
	
	citeste(a, b, c);
	rezolva(a, b, c, x1_re, x1_im, x2_re, x2_im);
	afiseaza(x1_re, x1_im, x2_re, x2_im);
	
	getchar();
	getchar();

    return 0;
}

