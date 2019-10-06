#include <iostream>
#include "multime.h"

//--------------------------------------
c_multime::c_multime()
{
	nr_elemente = 0;
	capacitate = 0;
	elemente = NULL;
}
//--------------------------------------
c_multime::c_multime(const c_multime &a)
{
	copiaza(a);
}
//--------------------------------------
c_multime::c_multime(int x)
{
	nr_elemente = 1;
	capacitate = 10;
	elemente = new int[capacitate];
	elemente[0] = x;
}
//--------------------------------------
c_multime::~c_multime()
{
	curata();
}
//--------------------------------------
int c_multime::cardinal(void)
{
	return nr_elemente;
}
//--------------------------------------

void c_multime::copiaza(const c_multime &a) // c.copiaza(a);
{
	*this = a;
}
//--------------------------------------
c_multime &c_multime::operator=(const c_multime &a)
{
	if (this != &a) {
		if (a.nr_elemente > capacitate) {
			capacitate = a.nr_elemente;
			if (elemente > 0) {
				delete[] elemente;
				elemente = 0; // NULL
			}
			if (capacitate)
				elemente = new int[capacitate];
		}

		nr_elemente = a.nr_elemente;
		for (int i = 0; i < nr_elemente; i++)
			elemente[i] = a.elemente[i];
	}
	return *this;
}
//--------------------------------------
void c_multime::curata(void)
{
	if (elemente != 0) {
		delete[] elemente;
		elemente = 0; //
	}
	nr_elemente = 0;
	capacitate = 0;
}
//--------------------------------------
int c_multime::adauga(int x)
{
	if (!apartine(x)) {
		*this += x;
		return OK;
	}
	else
		return ELEMENTUL_EXISTA;
}
//--------------------------------------
void c_multime::operator+=(int x)
{
	if (!apartine(x)) {
		if (nr_elemente == capacitate) {
			capacitate += 10; // noua capacitate
			int *tmp_e; // noul vector care stocheaza elemente
			tmp_e = new int[capacitate]; // aloc memorie pt. noul vector de elemente
			for (int i = 0; i < nr_elemente; i++)
				tmp_e[i] = elemente[i]; // copiez elementele in noua zona de memorie
			if (elemente) // dezaloc memoria curenta
				delete[] elemente;
			elemente = tmp_e; // atribui variabilei elemente noua adresa unde incepe in memorie vectorul cu elemente
		}

		elemente[nr_elemente] = x;
		nr_elemente++;
	}
}
//--------------------------------------
void c_multime::tipareste_ecran(void)
{
	std::cout << " Multimea este = {";
	for (int i = 0; i < nr_elemente - 1; i++) {
		std::cout << elemente[i] << ", ";
	}
	std::cout << elemente[nr_elemente - 1] << "} \n";
}
//--------------------------------------
bool c_multime::reuneste(const c_multime &a)
{
	for (int i = 0; i < a.nr_elemente; i++)
		adauga(a.elemente[i]);
	return true;
}
//--------------------------------------
void c_multime::operator+=(const c_multime &a)
{
	for (int i = 0; i < a.nr_elemente; i++)
		*this += a.elemente[i]; // derefentiere
}

//--------------------------------------

void c_multime::intersecteaza(const c_multime &a)
{
}

//--------------------------------------
bool c_multime::apartine(int x) const
{
	for (int i = 0; i < nr_elemente; i++) {
		if (elemente[i] == x)
			return true;
	}
	return false;
}
//--------------------------------------

bool c_multime::reuneste(const c_multime &a, const c_multime &b)
{
	curata();
	if (!reuneste(a))
		return false;
	if (!reuneste(b))
		return false;
	return true;
}
//--------------------------------------

// nu folosim ampersant cand returnam un obiect care e definit in functie
c_multime c_multime::operator+(const c_multime &a) {

	c_multime tmp;
	tmp += *this;
	tmp += a;

	return tmp;
}
//--------------------------------------

void c_multime::intersecteaza(const c_multime &a, const c_multime &b)
{
	*this = a * b;
}
//--------------------------------------

void c_multime::operator *=(const c_multime &a) 
{
	for (int i = 0; i < nr_elemente; i++)
		if (!a.apartine(elemente[i])) {
			*this -= elemente[i];
			i--;
		}
}
//--------------------------------------

void c_multime::diferenta(const c_multime &a)
{
	*this -= a;
}
//--------------------------------------
void c_multime::diferenta(const c_multime &a, const c_multime &b)
{
	*this = a - b;
}
//--------------------------------------
bool c_multime::operator==(const c_multime& a)
{
	if (nr_elemente != a.nr_elemente)
		return false;
	for (int i = 0; i < nr_elemente; i++)
		if (!apartine(a.elemente[i]))
			return false;
	return true;
}
//--------------------------------------

void c_multime::operator-=(int x) 
{
	for (int i = 0; i < nr_elemente; i++) {
		if (elemente[i] == x) {
			elemente[i] = elemente[nr_elemente - 1];
			nr_elemente--;
			break;
		}
	}
}
//--------------------------------------

void c_multime::operator-=(const c_multime &a) 
{
	for (int i = 0; i < a.nr_elemente; i++)
		*this -= a.elemente[i];  // [this] returneaza adresa de memorie
}
//--------------------------------------

c_multime c_multime::operator-(const c_multime &a) const 
{
	c_multime tmp;
	tmp = *this;
	tmp -= a;

	return tmp;
}
//--------------------------------------
c_multime c_multime::operator*(const c_multime &a) const 
{
	c_multime tmp;
	tmp = *this;
	tmp *= a;

	return tmp;

}
//--------------------------------------
