// ConsoleApplication15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "complex.h"
#include <stdio.h>

int main()
{
	t_complex c1;

	printf("real = %f, imaginar = %f\n", c1.get_real(), c1.get_imaginar());

	t_complex c2(1, 2);

	printf("real = %f, imaginar = %f\n", c2.get_real(), c2.get_imaginar());

	c1.aduna(c2);
	printf("real = %f, imaginar = %f\n", c1.get_real(), c1.get_imaginar());

	c1.scade(c2);
	printf("real = %f, imaginar = %f\n", c1.get_real(), c1.get_imaginar());

	t_complex c3;
	c3.set_real(4);
	c3.set_imaginar(2);
	c3.inmulteste(c2);
	printf("real = %f, imaginar = %f\n", c3.get_real(), c3.get_imaginar());


	c1.aduna(c2, c3);
	printf("real = %f, imaginar = %f\n", c1.get_real(), c1.get_imaginar());

	t_complex c4(c1);
	printf("real = %f, imaginar = %f\n", c4.get_real(), c4.get_imaginar());

	printf("modul = %f\n", c4.modul());

	getchar();
}

