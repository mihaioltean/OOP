#pragma once

#define N 10

#define OK 0
#define CAPACITATE_DEPASITA 1
#define ELEMENTUL_EXISTA 2

class t_multime {
private:
	int elemente[N];
	int nr_elemente;
public:
	t_multime();
	t_multime(int x);
	t_multime(const t_multime& sursa);
	~t_multime();

	void curata(void);

	void copiaza(const t_multime& sursa);
	t_multime& operator=(const t_multime& sursa);

	void afiseaza_ecran(void);
	bool apartine(int x) const;

	int adauga(int x);
	void operator+=(int x);

	bool elimina(int x);
	void operator-=(int x);

	bool reuniune(const t_multime &a);
	void operator+=(const t_multime &a);
	void operator*=(const t_multime &a);
	void operator-=(const t_multime &a);

	bool reuniune(const t_multime &a, const t_multime &b);

	void intersectie(const t_multime &a);
	void intersectie(const t_multime &a, const t_multime &b);

	void diferenta(const t_multime &a);
	void diferenta(const t_multime &a, const t_multime &b);

	bool operator==(const t_multime& a);

	t_multime operator+(const t_multime& a);
	t_multime operator*(const t_multime& a) const;
	t_multime operator-(const t_multime& a) const;
};