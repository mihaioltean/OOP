// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "ec2.h"
#include <stdio.h>

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

