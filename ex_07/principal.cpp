// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ec2.h"
#include <stdio.h>

int main()
{
	t_ecuatie_grad2 ec2;

	ec2.citeste();
	ec2.rezolva();
	ec2.afiseaza();

	t_ecuatie_grad2 ec2_1(1, 2, 5);
	ec2_1.rezolva();
	ec2_1.afiseaza();

	getchar();
	getchar();

	return 0;
}
