#include <iostream>
#include <fstream>
#include "multime.h"

c_multime::c_multime()
{
	nr_elemente = 0;
	capacitate = 0;
	elemente = NULL;
}
c_multime::c_multime(const c_multime &a)
{
	copiaza(a);
}
c_multime::c_multime(int x)
{
	nr_elemente = 1;
	capacitate = 10;
	elemente = new int[capacitate];
	elemente[0] = x;
}
c_multime::~c_multime()
{
	nr_elemente = 0;
	delete[] elemente;
	capacitate = 0;
}
int c_multime::cardinal(void)
{
	return nr_elemente;
}

void c_multime::copiaza(const c_multime &a)// c.copiaza(a);
{
	*this = a;
}

c_multime &c_multime::operator=(const c_multime &a)
{
	if (this != &a) {
		if (a.nr_elemente > capacitate) {
			delete[] elemente;
			elemente = NULL;
			if (a.nr_elemente > 0)
				elemente = new int[a.nr_elemente];
			capacitate = a.nr_elemente;
		}

		nr_elemente = a.nr_elemente;
		for (int i = 0; i < nr_elemente; i++)
			elemente[i] = a.elemente[i];
		// this - returneaza adresa unde incepe obiectul curent
		// *this - returneaza obiectul care se afla la adresa respectiva
	}
	return *this;
}

void c_multime::curata(void)
{
	if (elemente != NULL) {
		nr_elemente = 0;
		delete[] elemente;
		elemente = NULL; // 0;
		capacitate = 0;
	}
}

int c_multime::adauga(int x)
{
	if (!apartine(x)) {
		if (nr_elemente == capacitate) {
			int *tmp_elemente = new int[capacitate + 10];//aloc memorie noua
			for (int i = 0; i < nr_elemente; i++)// copiez din memoria curenta in cea noua
				tmp_elemente[i] = elemente[i];
			if (elemente != NULL)
				delete[] elemente; // dezaloc memoria curenta
			elemente = tmp_elemente;
			capacitate += 10;
		}

		elemente[nr_elemente] = x;
		nr_elemente++;
		return OK;
	}
	else
		return ELEMENTUL_EXISTA;
}

void c_multime::operator+=(int x)
{
	adauga(x);
}
void c_multime::tipareste_ecran(void)
{
	std::cout << " Multimea este = {";
	for (int i = 0; i < nr_elemente - 1; i++)
	{
		std::cout << elemente[i] << ", ";
	}
	std::cout << elemente[nr_elemente - 1] << "} \n";
}

void c_multime::tipareste_fisier(void)
{
	//std::cout << " Multimea este = {";
	std::ofstream f;
	f.open("m.txt");
	f << *this;
	/*
	for (int i = 0; i < nr_elemente - 1; i++)
	{
		f << elemente[i] << ", ";
	}
	f << elemente[nr_elemente - 1];
	*/
	f.close();
}

bool c_multime::reuneste(const c_multime &a)
{
	for (int i = 0; i < a.nr_elemente; i++)
		adauga(a.elemente[i]);

	return true;
}
void c_multime::operator+=(const c_multime &a)
{
	for (int i = 0; i < a.nr_elemente; i++)
		*this += a.elemente[i]; // derefentiere
}


void c_multime::intersecteaza(const c_multime &a)
{
}

bool c_multime::apartine(int x) const
{

	for (int i = 0; i < nr_elemente; i++)
	{
		if (elemente[i] == x)
			return true;
	}
	return false;
}

bool c_multime::reuneste(const c_multime &a, const c_multime &b)
{
	curata();
	if (!reuneste(a))
		return false;
	if (!reuneste(b))
		return false;
	return true;
}

// nu folosim ampersant cand returnam un obiect care e definit in functie
c_multime c_multime::operator+(const c_multime &a) {

	c_multime tmp;
	tmp += *this;
	tmp += a;

	return tmp;
}

void c_multime::intersecteaza(const c_multime &a, const c_multime &b)
{
	*this = a * b;
}

void c_multime::operator *=(const c_multime &a) {
	for (int i = 0; i < nr_elemente; i++)
		if (!a.apartine(elemente[i])) {
			*this -= elemente[i];
			i--;
		}
}

void c_multime::diferenta(const c_multime &a)
{
	*this -= a;
}
void c_multime::diferenta(const c_multime &a, const c_multime &b) {
	*this = a - b;
}
bool c_multime::operator==(const c_multime& a) {
	if (nr_elemente != a.nr_elemente) return false;
	for (int i = 0; i < nr_elemente; i++)
		if (!apartine(a.elemente[i])) return false;
	return true;
}

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

void c_multime::operator-=(const c_multime &a) 
{
	for (int i = 0; i < a.nr_elemente; i++)
		*this -= a.elemente[i];  // [this] returneaza adresa de memorie
}

c_multime c_multime::operator-(const c_multime &a) const {
	c_multime tmp;
	tmp = *this;
	tmp -= a;

	return tmp;
}
c_multime c_multime::operator*(const c_multime &a) const {
	c_multime tmp;
	tmp = *this;
	tmp *= a;

	return tmp;

}

ostream& operator<<(ostream& o, const c_multime&m)
{
	o << m.nr_elemente << endl;
	for (int i = 0; i < m.nr_elemente; i++)
		o << m.elemente[i] << " ";
	return o;
}

istream& operator>>(istream& i, c_multime&m)
{
	m.curata();
	int nr_elemente;
	i >> nr_elemente;
	for (int j = 0; j < nr_elemente; j++) {
		int e;
		i >> e;
		m += e;
	}
	return i;
}

void c_multime::citeste_fisier(void)
{
	ifstream f;
	f.open("m.txt");
	f >> *this;
	f.close();
}