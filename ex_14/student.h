#pragma once

#include "persoana.h"

class t_student: public t_persoana {
private:
	string facultate;
public:
	t_student();
	t_student(string nume, string prenume, unsigned int varsta, unsigned long long cnp, string facultate);
	t_student& operator=(const t_student&);
	bool operator==(const t_student&);
	void set_facultate(string facultate);
	string get_facultate(void);

	friend ostream& operator<<(ostream &o, const t_student&);
};