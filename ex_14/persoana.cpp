
#include <string>
#include "persoana.h"

//-----------------------------------------
t_persoana::t_persoana()
{
	nume = "";
	prenume = "";
	varsta = 0;
	cnp = 0;
}
//-----------------------------------------
t_persoana::~t_persoana()
{
	nume = "";
	prenume = "";
	varsta = 0;
	cnp = 0;
}
//-----------------------------------------
t_persoana::t_persoana(string nume, string prenume, unsigned int varsta, unsigned long long cnp)
{
	this->nume = nume;
	this->prenume = prenume;
	this->varsta = varsta;
	this->cnp = cnp;
}
//-----------------------------------------
t_persoana& t_persoana::operator=(const t_persoana& sursa)
{
	if (this != &sursa) {
		nume = sursa.nume;
		prenume = sursa.prenume;
		varsta = sursa.varsta;
		cnp = sursa.cnp;
	}
	return *this;
}
//-----------------------------------------
bool t_persoana::operator==(const t_persoana& p)
{
	return nume == p.nume && prenume == p.prenume && varsta == p.varsta && cnp == p.cnp;
}
//-----------------------------------------
bool t_persoana::operator<(const t_persoana& p)
{
	return varsta < p.varsta;
}
//-----------------------------------------
void t_persoana::set_nume(string nume)
{
	this->nume = nume;
}
//-----------------------------------------
string t_persoana::get_nume(void)
{
	return nume;
}
//-----------------------------------------
void t_persoana::set_prenume(string nume)
{
	prenume = nume;//!!!!!!!!!!!!!!
}
//-----------------------------------------
string t_persoana::get_prenume(void)
{
	return prenume;
}
//-----------------------------------------
void t_persoana::set_varsta(int varsta)
{
	this->varsta = varsta;
}
//-----------------------------------------
unsigned int t_persoana::get_varsta(void)
{
	return varsta;
}
//-----------------------------------------
void t_persoana::set_cnp(unsigned long long cnp)
{
	this->cnp = cnp;
}
//-----------------------------------------
unsigned long long t_persoana::get_cnp(void)
{
	return cnp;
}
//-----------------------------------------
ostream& operator<< (ostream &o, const t_persoana& p)
{
	o << p.nume << endl;
	o << p.prenume << endl;
	o << p.varsta << endl;
	o << p.cnp << endl;
	return o;
}
//-----------------------------------------