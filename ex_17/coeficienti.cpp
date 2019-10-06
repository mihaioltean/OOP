#include "coeficienti.h"

t_coeficienti::t_coeficienti()
{
	a = b = c = 0;
}
t_coeficienti::t_coeficienti(const t_coeficienti& sursa)
{
	a = sursa.a;
	b = sursa.b;
	c = sursa.c;
}

void t_coeficienti::set_a(float a)
{
	this->a = a;
}
void t_coeficienti::set_b(float b)
{
	this->b = b;
}
void t_coeficienti::set_c(float c)
{
	this->c = c;
}

float t_coeficienti::get_a(void)
{
	return a;
}
float t_coeficienti::get_b(void)
{
	return b;
}
float t_coeficienti::get_c(void)
{
	return c;
}

t_coeficienti& t_coeficienti::operator=(const t_coeficienti& sursa)
{
	if (this != &sursa) {
		a = sursa.a;
		b = sursa.b;
		c = sursa.c;
	}
	return *this;
}
t_coeficienti& t_coeficienti::operator=(const float sursa)
{
	a = sursa;
	b = sursa;
	c = sursa;
	return *this;
}
