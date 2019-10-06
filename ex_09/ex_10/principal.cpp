// ConsoleApplication17.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
		case '1':// constructor implicit
		{
			t_multime a;
			a.tipareste_ecran();
		}
			break;
		case '2':// constructor copiere
		{
			t_multime a(5);
			t_multime b(a);
			b.tipareste_ecran();
		}
			break;
		case '3': // constructor cu 1 parametru
		{
			t_multime a(5);
			a.tipareste_ecran();
		}
			break;
		case '4': // adauga
		{
			t_multime a;
			int rezultat = a.adauga(5);
			if (rezultat == CAPACITATE_DEPASITA)
				cout << "Am depasit capacitatea multimii!" << endl;
			else
				if (rezultat == ELEMENT_DEJA_EXISTENT)
					cout << "Elementul este deja in multime!" << endl;

			rezultat = a.adauga(5);
			if (rezultat == CAPACITATE_DEPASITA)
				cout << "Am depasit capacitatea multimii!" << endl;
			else
				if (rezultat == ELEMENT_DEJA_EXISTENT)
					cout << "Elementul este deja in multime!" << endl;

			rezultat = a.adauga(7);
			if (rezultat == CAPACITATE_DEPASITA)
				cout << "Am depasit capacitatea multimii!" << endl;
			else
				if (rezultat == ELEMENT_DEJA_EXISTENT)
					cout << "Elementul este deja in multime!" << endl;

			a.tipareste_ecran();
		}
			break;
		case '5': // apartine
		{
			t_multime a;
			int rezultat = a.adauga(5);
			if (rezultat == CAPACITATE_DEPASITA)
				cout << "Am depasit capacitatea multimii!" << endl;
			else
				if (rezultat == ELEMENT_DEJA_EXISTENT)
					cout << "Elementul este deja in multime!" << endl;

			if (a.apartine(5))
				cout << "Elementul 5 este in multime" << endl;
			else
				cout << "Elementul 5 nu este in multime" << endl;

			if (a.apartine(7))
				cout << "Elementul 7 este in multime" << endl;
			else
				cout << "Elementul 7 nu este in multime" << endl;

		}
			break;
		case '6': // reuniune
			break;

		}
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
