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

struct t_ecuatie_grad2 {
	t_coeficienti coeficienti;
	t_solutii solutii;
};


void citeste(t_coeficienti &coeficienti);
void rezolva(t_ecuatie_grad2& ec2);
void afiseaza(t_solutii solutii);