// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "complex.h"
#include <stdio.h>
#include "meniu.h"

int main()
{
	char tasta;
	do {
		afiseaza_meniu();
		tasta = getchar();
		getchar();
		switch (tasta)
		{
		case '1' : {
			t_complex c1;  // se va afisa ce e inregistrat in c1
			cout << c1;
		}
			break;
		case '2': {
			t_complex c2(1, 2);  // se va afisa re = 1 si im = 2
			printf("real=%f,imaginar=%f\n", c2.get_real(), c2.get_imaginar());
		}
			break;
		case '3': {
			t_complex c2(1, 2);
			t_complex c1(c2);
			printf("real=%f,imaginar=%f\n", c1.get_real(), c1.get_imaginar());
		}
			break;
		case '4':
		{  t_complex c2(1, 2);
		     t_complex c1(c2);
		   c1.aduna(c2); // il aduna pe c1 la c2 si afiseaza c1
		   printf("real=%f,imaginar=%f\n", c1.get_real(), c1.get_imaginar()); 
		}
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
		{
			t_complex a;
			cin >> a;
			cout << a;
		}
			break;
		case '9'://a++
		{
			t_complex a(2, 3);
			t_complex c;
			c = a++;
			cout << a;
			cout << c;
		}
			break;
		case '0'://++a
		{
			t_complex a(2, 3);
			t_complex c;
			c = ++a;
			cout << a;
			cout << c;
		}
			break;
		}
	} while (tasta != 'e');


	/*

	t_complex c2(1,2);  // se va afisa re = 1 si im = 2
	printf("real=%f,imaginar=%f\n", c2.get_real(), c2.get_imaginar());

	

	c1.scade(c2);
	printf("real=%f,imaginar=%f\n", c1.get_real(), c1.get_imaginar());

	t_complex c3;
	c3.set_real(4);
	c3.set_imaginar(2);
	c3.inmulteste(c2);
	printf("real=%f,imaginar=%f\n", c3.get_real(), c3.get_imaginar());

	c1.aduna(c2, c3);
	printf("real=%f,imaginar=%f\n", c1.get_real(), c1.get_imaginar());

	t_complex c4(c1); // constructor de copiere - copiaza c1 in c4
	printf("real=%f,imaginar=%f\n", c4.get_real(), c4.get_imaginar());

	printf("modul=%f\n", c4.modul()); 
	a.tipareste_numar(); */

	getchar(); //sterge linia ce apare in mod normal in consola ca sa ramana doar rezultatul problemei
}

