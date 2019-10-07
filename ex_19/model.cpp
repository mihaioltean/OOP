#include <math.h>
#include "model.h"

//---------------------------------------------------------------------
t_eq2_model::t_eq2_model(void)
{
	a = b = c = x1.im = x1.re = x2.im = x2.re = 0;
}
//---------------------------------------------------------------------
void t_eq2_model::set_a(float a)
{
	this->a = a;
}
//---------------------------------------------------------------------
void t_eq2_model::set_b(float b)
{
	this->b = b;
}
//---------------------------------------------------------------------
void t_eq2_model::set_c(float c)
{
	this->c = c;
}
//---------------------------------------------------------------------
void t_eq2_model::solve(void)
{
	float delta = b * b - 4 * a * c;
	if (delta >= 0) {
		x1.re = (-b - sqrt(delta)) / (2 * a);
		x1.im = 0;
		x2.re = (-b + sqrt(delta)) / (2 * a);
		x2.im = 0;
	}
	else {
		x1.re = -b / (2 * a);
		x1.im = -sqrt(-delta) / (2 * a);
		x2.re = -b / (2 * a);
		x2.im = sqrt(-delta) / (2 * a);
	}
	observer->notify();
}
//---------------------------------------------------------------------
float t_eq2_model::get_x1_re(void)
{
	return x1.re;
}
//---------------------------------------------------------------------
float t_eq2_model::get_x1_im(void)
{
	return x1.im;
}
//---------------------------------------------------------------------
float t_eq2_model::get_x2_re(void)
{
	return x2.re;
}
//---------------------------------------------------------------------
float t_eq2_model::get_x2_im(void)
{
	return x2.re;
}
//---------------------------------------------------------------------
void t_eq2_model::set_observer(t_abstract_controller* observer)
{
	this->observer = observer;
}