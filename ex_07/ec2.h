#pragma once

struct t_coeficienti {
	float a, b, c;
};

struct t_solutie {
	float re, im;
};

struct t_solutii {
	t_solutie x1, x2;
};

class t_ecuatie_grad2 {
private:
	t_coeficienti coeficienti;
	t_solutii solutii;

public:
	t_ecuatie_grad2();
	t_ecuatie_grad2(float a, float b, float c);

	void citeste(void);
	void rezolva(void);
	void afiseaza(void);
};