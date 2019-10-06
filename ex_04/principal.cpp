// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "ec2.h"
#include <stdio.h>

int main()
{
	t_coeficienti coeficienti;
	t_solutie x1, x2;

	citeste(coeficienti);
	rezolva(coeficienti, x1, x2);
	afiseaza(x1, x2);

	getchar();
	getchar();

	return 0;
}

