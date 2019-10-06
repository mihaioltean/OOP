#pragma once


#include "coeficienti.h"
#include "solutii.h"


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