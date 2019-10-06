#include "complex.h"
#include "math.h"

//---------------------------------------
t_complex::t_complex()
{
	re = im = 0;
}
//---------------------------------------
t_complex::t_complex(float re, float im)
{
	this->re = re;
	this->im = im;
}
//---------------------------------------
t_complex::t_complex(const t_complex &a)
{
	re = a.re;
	im = a.im;
}
//---------------------------------------
float t_complex::get_real(void)
{
	return re;
}
//---------------------------------------
void t_complex::set_real(float re)
{
	this->re = re;
}
//---------------------------------------
float t_complex::get_imaginar(void)
{
	return im;
}
//---------------------------------------
void t_complex::set_imaginar(float im)
{
	this->im = im;
}
//---------------------------------------
void t_complex::aduna(const t_complex &a)
{
	re = re + a.re;
	im = im + a.im;
}
//---------------------------------------
void t_complex::scade(const t_complex &a)
{
	re = re - a.re;
	im = im - a.im;
}
//---------------------------------------
void t_complex::inmulteste(const t_complex &a)
{
	float _re = re * a.re - im * a.im;

	im = im * a.re + re * a.im;
	re = _re;
}
//---------------------------------------
void t_complex::aduna(const t_complex& a, const t_complex& b)
{
	re = a.re + b.re;
	im = a.im + b.im;
}
//---------------------------------------
void t_complex::scade(const t_complex& a, const t_complex& b)
{
	re = a.re - b.re;
	im = a.im - b.im;
}
//---------------------------------------
void t_complex::inmulteste(const t_complex& a, const t_complex& b)
{
	re = a.re * b.re - a.im * b.im;
	im = b.im * a.re + b.re * a.im;
}
//---------------------------------------
float t_complex::modul(void)
{
	return sqrt(re * re + im * im);
}
//---------------------------------------
