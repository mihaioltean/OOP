#include "solutie.h"

t_solutie::t_solutie()
{
	re = im = 0;
}
t_solutie::t_solutie(const t_solutie& sursa)
{
	re = sursa.re;
	im = sursa.im;
}
t_solutie::t_solutie(float re, float im)
{
	this->re = re;
	this->im = im;
}

void t_solutie::set_re(float re)
{
	this->re = re;
}
void t_solutie::set_im(float im)
{
	this->im = im;
}

float t_solutie::get_re(void)
{
	return re;
}
float t_solutie::get_im(void)
{
	return im;
}

t_solutie& t_solutie::operator=(const t_solutie& sursa)
{
	if (this != &sursa) {
		re = sursa.re;
		im = sursa.im;
	}
	return *this;
}
t_solutie& t_solutie::operator=(const float sursa)
{
	re = sursa;
	im = sursa;
	return *this;
}
