// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ec2.h"
#include <stdio.h>

int main()
{
	t_ecuatie_grad2 ec2;

	citeste(ec2.coeficienti);
	rezolva(ec2);
	afiseaza(ec2.solutii);

	getchar();
	getchar();

	return 0;
}
