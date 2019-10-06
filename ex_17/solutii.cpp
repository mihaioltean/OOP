#include "solutii.h"

t_solutii::t_solutii()
{
	//1.
	x1.set_re(0);
	x1.set_im(0);
	x2.set_re(0);
	x2.set_im(0);
	//2.
	x1 = t_solutie(0, 0);
	x2 = t_solutie(0, 0);
	//3.
	x1 = x2 = 0;
}
t_solutii::t_solutii(const t_solutii& sursa)
{
	x1 = sursa.x1;
	x2 = sursa.x2;
}

void t_solutii::set_x1(t_solutie& x1)
{
	this->x1 = x1;
}
void t_solutii::set_x2(t_solutie& x2)
{
	this->x2 = x2;
}

t_solutie t_solutii::get_x1(void)
{
	return x1;
}
t_solutie t_solutii::get_x2(void)
{
	return x2;
}
t_solutii& t_solutii:: operator=(const t_solutii& sursa)
{
	if (this != &sursa) {
		x1 = sursa.x1;
		x2 = sursa.x2;
	}
	return *this;
}
t_solutii& t_solutii::operator=(const float sursa)
{
	x1 = sursa;
	x2 = sursa;

	return *this;
}