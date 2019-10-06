
#include <string>
#include "student.h"

//----------------------------------------------
t_student::t_student():t_persoana()
{
	facultate = "";
}
//----------------------------------------------
t_student::t_student(string nume, string prenume, unsigned int varsta, unsigned long long cnp, string facultate):
	t_persoana(nume, prenume, varsta, cnp)
{
	this->facultate = facultate;
}
//----------------------------------------------
t_student& t_student::operator=(const t_student& sursa)
{
	if (this != &sursa) {
		t_persoana::operator=(sursa);
		facultate = sursa.facultate;
	}
	return *this;
}
//----------------------------------------------
bool t_student::operator==(const t_student& p)
{
	return t_persoana::operator==(p) && facultate == p.facultate;
}
//----------------------------------------------
void t_student::set_facultate(string facultate)
{
	this->facultate = facultate;
}
//----------------------------------------------
string t_student::get_facultate(void)
{
	return facultate;
}
//----------------------------------------------
ostream& operator<<(ostream &o, const t_student& p)
{
	o << (t_persoana)p;
	o << p.facultate << endl;
	return o;
}
//----------------------------------------------
