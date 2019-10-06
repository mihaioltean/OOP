#pragma once

struct t_coeficienti {
	float a, b, c;
};

struct t_solutie {
	float re, im;
};


void citeste(t_coeficienti &coeficienti);
void rezolva(t_coeficienti coeficienti,	t_solutie &x1, t_solutie &x2);
void afiseaza(t_solutie x1, t_solutie x2);