#pragma once
#include <iostream>
using namespace std;

class t_complex
{
private:  // datele de intrare sunt private(nu avem acces din main)
	float re, im;

public:    // datele de intrare sunt vizibile si din exteriorul clasei
	t_complex();  // constructor
	t_complex(float re, float im);  //constructor cu variabile ce iau valoarea din "private"
	t_complex(const t_complex &a); 

	float get_real(void);
	void set_real(float re);   // setam ce este in interiorul numarului real

	float get_imaginar(void);
	void set_imaginar(float im);  // -||- nr imaginar

	void aduna(const t_complex& a); // aduna parametrul a la cel existent ; & - referinta (ajuta la marirea vitezei pt ca se lucreaza pe aceeasi zona de memorie)
	void scade(const t_complex& a);

	void inmulteste(const t_complex& a);

	void aduna(const t_complex& a, const t_complex& b);
	void scade(const t_complex& a, const t_complex& b);
	void inmulteste(const t_complex& a, const t_complex& b);

	t_complex& operator=(const t_complex &sursa);
	bool operator==(const t_complex &);
	bool operator!=(const t_complex&);

	void operator+=(const t_complex&);
	void operator-=(const t_complex&);
	void operator*=(const t_complex&);


	t_complex operator+(const t_complex&);
	t_complex operator-(const t_complex&);
	t_complex operator*(const t_complex&);

	t_complex operator++(int);//a++  
	t_complex operator++(void);//++a

	float modul(void); 

	void tipareste_numar(void);

	friend void operator<<(ostream &s, const t_complex &a);  // functie in afara clasei , de asta se foloseste " friend"
	friend void operator>>(istream &s, t_complex &a); // modifica nr deci nu trebuie "const"

};

