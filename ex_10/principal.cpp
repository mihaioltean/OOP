// ConsoleApplication16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "multime.h"
#include "meniu.h"

using namespace std;

int main()
{
	char tasta;
	do {
		afiseaza_meniu();
		tasta = getchar();
		getchar();
		switch (tasta) {
		case '1': // testam constructor implicit
		{
			t_multime a;
			a.afiseaza_ecran();
		}
		break;
		case '2': // testam constructor cu 1 parametru
		{
			t_multime a(3);
			a.afiseaza_ecran();
		}
		break;
		case '3': // testam constructor de copiere
		{
			t_multime a(3);
			t_multime b(a);
			b.afiseaza_ecran();
		}
		break;
		case '4': // testam adauga
		{
			t_multime a(3);

			int x = 4;
			int rezultat = a.adauga(x);
			if (rezultat == CAPACITATE_DEPASITA)
				cout << "Capacitate depasita" << endl;
			else
				if (rezultat == ELEMENTUL_EXISTA)
					cout << "Elementul exista (" << x << ")" << endl;

			x = 3;
			rezultat = a.adauga(x);
			if (rezultat == CAPACITATE_DEPASITA)
				cout << "Capacitate depasita" << endl;
			else
				if (rezultat == ELEMENTUL_EXISTA)
					cout << "Elementul exista (" << x << ")" << endl;
			a.afiseaza_ecran();
		}
		break;
		case '5': // testam apartenenta
		{
			t_multime a(3);
			int x = 2;
			if (a.apartine(x))
				cout << "Elementul " << x << " apartine multimii" << endl;
			else
				cout << "Elementul " << x << " nu apartine multimii" << endl;

			x = 3;
			if (a.apartine(x))
				cout << "Elementul " << x << " apartine multimii" << endl;
			else
				cout << "Elementul " << x << " nu apartine multimii" << endl;
		}
		break;
		case '6': // testam elimina
		{
			t_multime a(2);
			int x = 3;
			if (a.elimina(x)) {
				cout << "Elementul a fost eliminat cu succes" << endl;
				a.afiseaza_ecran();
			}
			else {
				cout << "Elementul nu exista in multime" << endl;
			}

			x = 2;
			if (a.elimina(x)) {
				cout << "Elementul a fost eliminat cu succes" << endl;
				a.afiseaza_ecran();
			}
			else {
				cout << "Elementul nu exista in multime" << endl;
			}
		}
		break;
		case '7': // testam reuniune
		{
			t_multime a(2);
			t_multime b(3);
			if (a.reuniune(b))
				a.afiseaza_ecran();
			else {
				cout << "Capacitate depasita" << endl;
			}
		}
		break;

		case '8': // testam copiere
		{
			t_multime a(2);
			t_multime b(3);
			t_multime c;
			c = a = b;//c.operator=(a.operator=(b));
			//a.copiaza(b);
			c.afiseaza_ecran();
		}
		break;

		case '9': // += (int)
		{
			t_multime a(2);
			a += 3; // a.operator+=(3);
			a.afiseaza_ecran();
		}
		break;

		case '0': // += (multime)
		{
			t_multime a(2);
			t_multime b(3);
			a += b; // a.operator+=(b);
			a.afiseaza_ecran();
		}
		break;
		case 'q': // == (multime)
		{
			t_multime a(3);
			t_multime b(3);
			if (a == b) // if(a.operator==(b))
				cout << "Multimile sunt egale" << endl;
			else
				cout << "Multimile sunt diferite" << endl;
		}
		break;
		case 'w': // c = a + b
		{
			t_multime a(3);
			t_multime b(2);
			t_multime c(1);
			c = a + b; //c.operator=(a.operator+(b))
			c.afiseaza_ecran();
		}
		break;
		case 'r': // a -= 5
		{
			t_multime a(3);
			a += 5;
			a += 4;
			a -= 4;
			a.afiseaza_ecran();
		}
		break;
		case 't': // a -= b
		{
			t_multime a(3);
			a += 5;
			a += 4;

			t_multime b(2);
			b += 5;

			a -= b;
			a.afiseaza_ecran();
		}
		break;
		case 'y': // a *= b
		{
			t_multime a(3);
			a += 5;
			a += 4;

			t_multime b(2);
			b += 5;

			a *= b; // a.operator*=(b); // a.intersectie(b);
			a.afiseaza_ecran();
		}
		break;
		case 'u': // c = a * b
		{
			t_multime a(3);
			a += 2;
			t_multime b(2);
			t_multime c(1);
			c = a * b; //c.operator=(a.operator*(b))
			c.afiseaza_ecran();
		}
		case 'i': // c = a - b
		{
			t_multime a(3);
			a += 2;
			t_multime b(2);
			t_multime c(1);
			c = a - b; //c.operator=(a.operator-(b))
			c.afiseaza_ecran();
		}
		break;
		}// end switch
	} while (tasta != 'e');

	getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
