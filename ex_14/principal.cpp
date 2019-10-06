// ConsoleApplication10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>

#include "student.h"
#include "meniu.h"

int main()
{
	char tasta;
	do {
		afiseaza_meniu();
		tasta = getchar();
		getchar();

		switch (tasta) {
		case '1': // constructor implicit persoana
		{
			t_persoana p;
			p.set_nume("ionescu");
			p.set_prenume("mihai");
			p.set_varsta(20);
			p.set_cnp(1981111123456);

			cout << p;
		}
		break;
		case '2': // constructor cu parametri persoana
		{
			t_persoana p("popescu", "nicolae", 19, 1991011123456);
			cout << p;
		}
		break;
		case '3': // operator <
		{
			t_persoana p("popescu", "nicolae", 19, 1991011123456);
			t_persoana p2("ionescu", "mihai", 20, 1981011123456);
			if (p < p2)
				cout << p.get_nume() << " este mai tanar decat " << p2.get_nume() << endl;
			else
				cout << p.get_nume() << " este mai in varsta sau egal cu " << p2.get_nume() << endl;
		}
		break;
		case '4': // constructor implicit student
		{
			t_student s;
			s.set_nume("ionescu");
			s.set_prenume("mihai");
			s.set_varsta(20);
			s.set_cnp(1981111123456);
			s.set_facultate("info");
			cout << s;
		}
		break;
		case '5': // constructor cu parametri student
		{
			t_student p("popescu", "nicolae", 19, 1991011123456, "info");
			cout << p;
		}
		break;
		case '6': // =student
		{
			t_student p("popescu", "nicolae", 19, 1991011123456, "info");
			t_student p2;
			p2 = p;
			cout << p2;
		}
		break;
		case '7': // ==student
		{
			t_student p("popescu", "nicolae", 19, 1991011123456, "info");
			t_student p2("popescu", "mihai", 19, 1991011123457, "info");
			if (p2 == p)
				cout << "aceeasi persoana" << endl;
			else
				cout << "persoane diferite" << endl;
		}
		break;
		case '8': // operator <
		{
			t_student p("popescu", "nicolae", 19, 1991011123456, "info");
			t_student p2("ionescu", "mihai", 20, 1981011123456, "istorie");
			if (p < p2)
				cout << p.get_nume() << " este mai tanar decat " << p2.get_nume() << endl;
			else
				cout << p.get_nume() << " este mai in varsta sau egal cu " << p2.get_nume() << endl;
		}
		break;

		} // end switch

	} while (tasta != 'e');


	getchar();
}
