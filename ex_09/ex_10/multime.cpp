#include "multime.h"

#include <iostream>
using namespace std;

//-------------------------------------------
t_multime::t_multime()
{
	nr_elemente = 0;
}
//-------------------------------------------
t_multime::t_multime(const t_multime& a)
{
	nr_elemente = a.nr_elemente;
	for (int i = 0; i < nr_elemente; i++)
		elemente[i] = a.elemente[i];
}
//-------------------------------------------
t_multime::t_multime(int x)
{
	nr_elemente = 1;
	elemente[0] = x;
}
//-------------------------------------------
t_multime::~t_multime()
{
	nr_elemente = 0;
}
//-------------------------------------------
int t_multime::cardinal(void)
{
	return nr_elemente;
}
//-------------------------------------------
int t_multime::adauga(int x)
{
	if (!apartine(x)) {
		if (nr_elemente == N)
			return CAPACITATE_DEPASITA;
		else {
			elemente[nr_elemente] = x;
			nr_elemente++;
			return OK;
		}
	}
	else
		return ELEMENT_DEJA_EXISTENT;
}
//-------------------------------------------
void t_multime::tipareste_ecran(void)
{
	cout << "Multimea este = {";
	for (int i = 0; i < nr_elemente; i++)
		if (i < nr_elemente - 1)
			cout << elemente[i] << ", ";
		else
			cout << elemente[i];
	cout << "}" << endl;
}
//-------------------------------------------
bool t_multime::reuneste(const t_multime&a)
{
	return true;
}
//-------------------------------------------
void t_multime::intersecteaza(const t_multime&a)
{

}
//-------------------------------------------
void t_multime::diferenta(const t_multime&a)
{

}
//-------------------------------------------
bool t_multime::apartine(int x)
{
	for (int i = 0; i < nr_elemente; i++)
		if (elemente[i] == x)
			return true;
	return false;
}
//-------------------------------------------
bool t_multime::reuneste(const t_multime&a, const t_multime&b)
{
	return true;
}
//-------------------------------------------
void t_multime::intersecteaza(const t_multime&a, const t_multime&b)
{

}
//-------------------------------------------
void t_multime::diferenta(const t_multime&a, const t_multime&b)
{

}
//-------------------------------------------