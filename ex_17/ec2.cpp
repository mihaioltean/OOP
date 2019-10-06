#include <iostream>
#include <stdio.h>
#include <math.h>

#include "ec2.h"

using namespace std;
//--------------------------------
t_ecuatie_grad2::t_ecuatie_grad2()
{
	coeficienti = 0;
	solutii = 0;
}
//--------------------------------
t_ecuatie_grad2::t_ecuatie_grad2(float a, float b, float c)
{
	coeficienti.set_a(a);
	coeficienti.set_b(b);
	coeficienti.set_c(c);
}
//--------------------------------
void t_ecuatie_grad2::citeste(void)
{
	float x;

	cout << "a = ";
	cin >> x;
	coeficienti.set_a(x);

	cout << "b = ";
	cin >> x;
	coeficienti.set_b(x);

	cout << "c = ";
	cin >> x;
	coeficienti.set_c(x);
}
//--------------------------------
void t_ecuatie_grad2::rezolva(void)
{
	float delta = coeficienti.get_b() * coeficienti.get_b() - 
		4 * coeficienti.get_a() * coeficienti.get_c();

	if (delta >= 0) {
		t_solutie x1((-coeficienti.get_b() - sqrt(delta)) / (2 * coeficienti.get_a()), 0);
		solutii.set_x1(x1);

		t_solutie x2((-coeficienti.get_b() + sqrt(delta)) / (2 * coeficienti.get_a()), 0);
		solutii.set_x2(x2);
	}
	else { // delta < 0
		t_solutie x1(-coeficienti.get_b() / (2 * coeficienti.get_a()), -sqrt(-delta) / (2 * coeficienti.get_a()));
		t_solutie x2(-coeficienti.get_b() / (2 * coeficienti.get_a()), sqrt(-delta) / (2 * coeficienti.get_a()));
		solutii.set_x1(x1);
		solutii.set_x2(x2);
	}
}
//--------------------------------
void t_ecuatie_grad2::afiseaza(void)
{
	cout << "re = " << solutii.get_x1().get_re() << "im =" << solutii.get_x1().get_im() << endl;;
	cout << "re = " << solutii.get_x2().get_re() << "im =" << solutii.get_x2().get_im() << endl;;
}
//--------------------------------

