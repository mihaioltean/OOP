#include "multime.h"
#include <iostream>

//---------------------------------------
t_multime::t_multime()
{
	nr_elemente = 0;
}
//---------------------------------------
t_multime::t_multime(const t_multime&a)
{
	copiaza(a);
}
//---------------------------------------
void t_multime::copiaza(const t_multime& sursa)
{
	nr_elemente = sursa.nr_elemente;
	for (int i = 0; i < nr_elemente; i++)
		elemente[i] = sursa.elemente[i];
}
//---------------------------------------
t_multime& t_multime::operator=(const t_multime& sursa)
{
	nr_elemente = sursa.nr_elemente;
	for (int i = 0; i < nr_elemente; i++)
		elemente[i] = sursa.elemente[i];

	return *this;
}
//---------------------------------------
t_multime::t_multime(int x)
{
	elemente[0] = x;
	nr_elemente = 1;
}
//---------------------------------------
t_multime::~t_multime()
{
	nr_elemente = 0;
}
//---------------------------------------
void t_multime::curata(void)
{
	nr_elemente = 0;
}
//---------------------------------------
void t_multime::afiseaza_ecran(void)
{
	std::cout << "Multimea este = {";
	for (int i = 0; i < nr_elemente; i++)
		if (i < nr_elemente - 1)
			std::cout << elemente[i] << ", ";
		else
			std::cout << elemente[i];

	std::cout << "}" << std::endl;
}
//---------------------------------------
bool t_multime::apartine(int x) const
{
	for (int i = 0; i < nr_elemente; i++)
		if (elemente[i] == x)
			return true;
	return false;
}
//---------------------------------------
int t_multime::adauga(int x)
{
	if (nr_elemente < N) {
		if (apartine(x))
			return ELEMENTUL_EXISTA;
		elemente[nr_elemente] = x;
		nr_elemente++;
		return OK;
	}
	else
		return CAPACITATE_DEPASITA;
}
//---------------------------------------
void t_multime::operator+=(int x)
{
	if (!apartine(x)) {
		elemente[nr_elemente] = x;
		nr_elemente++;
	}
}
//---------------------------------------
bool t_multime::elimina(int x)
{
	for (int i = 0; i < nr_elemente; i++)
		if (elemente[i] == x) {
			for (int j = i; j < nr_elemente - 1; j++)
				elemente[j] = elemente[j + 1];
			nr_elemente--;
			return true;
		}
	return false;
}
//---------------------------------------
void t_multime::operator-=(int x)
{
	for (int i = 0; i < nr_elemente; i++)
		if (elemente[i] == x) {
			for (int j = i; j < nr_elemente - 1; j++)
				elemente[j] = elemente[j + 1];
			nr_elemente--;
		}
}
//---------------------------------------
bool t_multime::reuniune(const t_multime &a)
{
	for (int i = 0; i < a.nr_elemente; i++)
		if (adauga(a.elemente[i]) == CAPACITATE_DEPASITA)
			return false;
	return true;
}
//---------------------------------------
void t_multime::operator+=(const t_multime &a)
{
	for (int i = 0; i < a.nr_elemente; i++)
		*this += a.elemente[i];
}
//---------------------------------------
bool t_multime::reuniune(const t_multime &a, const t_multime &b)
{
	curata();
	// adauga a
	if (!reuniune(a))
		return false;

	if (reuniune(b))
		return false;

	return true;
}
//---------------------------------------
void t_multime::intersectie(const t_multime &a)
{
	*this *= a;
}
//---------------------------------------
void t_multime::intersectie(const t_multime &a, const t_multime &b)
{
	*this = a * b;
}
//---------------------------------------
void t_multime:: diferenta(const t_multime &a)
{
	*this -= a;
}
//---------------------------------------
void t_multime::diferenta(const t_multime &a, const t_multime &b)
{
	*this = a - b;
}
//---------------------------------------
bool t_multime::operator==(const t_multime& a)
{
	if (nr_elemente != a.nr_elemente)
		return false;

	for (int i = 0; i < nr_elemente; i++)
		if (!apartine(a.elemente[i]))
			return false;
	
	return true;
}
//---------------------------------------
t_multime t_multime ::operator+(const t_multime& a)
{
	t_multime tmp;
	tmp += *this;
	tmp += a;

	return tmp;
}
//---------------------------------------
t_multime t_multime::operator*(const t_multime& a) const
{
	t_multime tmp;
	tmp += *this;
	tmp *= a;

	return tmp;
}
//---------------------------------------
t_multime t_multime::operator-(const t_multime& a) const
{
	t_multime tmp;
	tmp += *this;
	tmp -= a;

	return tmp;
}
//---------------------------------------
void t_multime::operator-=(const t_multime &a)
{
	for (int i = 0; i < a.nr_elemente; i++)
		if (apartine(a.elemente[i]))
			*this -= a.elemente[i];
}
//---------------------------------------
void t_multime::operator*=(const t_multime &a)
{
	for (int i = 0; i < nr_elemente; i++)
		if (!a.apartine(elemente[i])) {
			*this -= elemente[i];
			i--;
		}
}
//---------------------------------------