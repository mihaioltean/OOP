#pragma once

#define N 100

#define OK 0
#define CAPACITATE_DEPASITA 1
#define ELEMENT_DEJA_EXISTENT 2

class t_multime {
private:
	int elemente[N];
	int nr_elemente;

public:
	t_multime();
	t_multime(const t_multime& a);
	t_multime(int x);
	~t_multime();

	int cardinal(void);

	int adauga(int x);

	void tipareste_ecran(void);

	bool reuneste(const t_multime&a);
	void intersecteaza(const t_multime&a);
	void diferenta(const t_multime&a);

	bool apartine(int x);

	bool reuneste(const t_multime&a, const t_multime&b);
	void intersecteaza(const t_multime&a, const t_multime&b);
	void diferenta(const t_multime&a, const t_multime&b);
};