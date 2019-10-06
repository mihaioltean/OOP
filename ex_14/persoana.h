#pragma once

#include <iostream>

using namespace std;

class t_persoana {

private:
	string nume, prenume;
	unsigned int varsta;
	unsigned long long cnp;
public:
	t_persoana();
	~t_persoana();
	t_persoana(string nume, string prenume, unsigned int varsta, unsigned long long cnp);

	t_persoana& operator=(const t_persoana&);
	bool operator==(const t_persoana&);
	bool operator<(const t_persoana&);

	void set_nume(string nume);
	string get_nume(void);

	void set_prenume(string nume);
	string get_prenume(void);

	void set_varsta(int varsta);
	unsigned int get_varsta(void);

	void set_cnp(unsigned long long cnp);
	unsigned long long get_cnp(void);

	friend ostream& operator<< (ostream &o, const t_persoana&);
};