#include "complex.h"
#include "math.h"



t_complex::t_complex()   // constructor
{
	re = im = 0;
}

t_complex::t_complex(float re, float im)  //constructor cu variabile ce iau valoarea din "private"
{
	this->re = re;   // "this->" tine minte adresa de unde incepe obiectul curent
	this->im = im;
}

float t_complex::get_real(void)
{
	return re;
}

void t_complex::set_real(float re)   // setam ce este in interiorul numarului real
{
	this->re = re;
}

float t_complex::get_imaginar(void)
{
	return im;
}

void t_complex::set_imaginar(float im)
{
	this->im = im;
}

void t_complex::aduna(const t_complex &a)
{
	re = re + a.re;
	im = im + a.im;
}

void t_complex::scade(const t_complex &a)
{
	re = re - a.re;
	im = im - a.im;
}

void t_complex::inmulteste(const t_complex &a)
	{
		float _re = re * a.re - im * a.im; // am pus un float _re aici ca sa nu il suprascriem pe re initial
        im = im * a.re + re * a.im;
		re = _re;
	}

void t_complex::aduna(const t_complex& a, const t_complex& b)
{
	re = a.re + b.re;
	im = a.im + b.im;
}

void t_complex::scade(const t_complex& a, const t_complex& b)
{
	re = a.re - b.re;
	im = a.im - b.im;
}

void t_complex::inmulteste(const t_complex& a, const t_complex& b)
{
	re = a.re * b.re - a.im * b.im;
	im = b.im * a.re + b.re * a.im;
}

t_complex::t_complex(const t_complex &a)
{
	re = a.re;
	im = a.im;
}

t_complex& t_complex::operator=(const t_complex &sursa)
{
	if (this != &sursa)
	{
		re = sursa.re;
		im = sursa.im;
	}
	return *this;
}

bool t_complex::operator==(const t_complex &a) 
{
	/* gresit : if (re == a.re && im == a.im) // nu comparati numerele reale cu == !!!! nu o sa functioneze*/
	if(fabs(re - a.re)<=1e-6 && fabs(im - a.im)<=1e-6) // fabs - valoarea absoluta a unui nr real
		return true;
	else
		return false;
}

bool t_complex::operator!=(const t_complex&a)
{
	return !(*this == a);
}

void t_complex::operator+=(const t_complex&a)
{
	re += a.re;
	im += a.im;
}

void t_complex::operator-=(const t_complex&a)
{
	re -= a.re;
	im -= a.im;
}

void t_complex::operator*=(const t_complex&a)
{
	float t = re * a.re - im * a.im;
	im = im * a.re + re * a.im;
	re = t;
}

t_complex t_complex::operator+(const t_complex&a)
{
	t_complex tmp;
	//var1//tmp.re = re + a.re;
	//var1//tmp.im = im + a.im;
	tmp = *this;
	tmp += a;
	return tmp;
}

t_complex t_complex::operator-(const t_complex&a)
{
	t_complex tmp;
	//var1//tmp.re = re - a.re;
	//var1//tmp.im = im - a.im;
	tmp = *this;
	tmp -= a;
	return tmp;
}
t_complex t_complex::operator*(const t_complex&a)
{
	t_complex tmp;
	tmp = *this;
	tmp *= a;
	return tmp;
}

t_complex t_complex::operator++(int)//c = a++  prima data atribuirea si dupa incrementarea
{
	t_complex a = *this;
	re++;
	im++;
	return a;
}

t_complex t_complex::operator++(void)//++a prima data incrementeaza pe this si dupa returneaza rezultatul
{
	re++;
	im++;
	t_complex a(*this);
	return a;
}

float t_complex::modul(void)
{
	return sqrt(re * re + im * im);
}

void t_complex::tipareste_numar(void)
{
	std::cout << "re= " << re << "im = " << im << endl;
}

//cout << a; // cout.operator<<(const t_complex &a);
//cin >> a; // cin.operator<<(const t_complex &a);

void operator<<(ostream &s, const t_complex &a)
{
	s << "re= " << a.re <<" " << "im = " << a.im << endl;
}
void operator>>(istream &s, t_complex &a)
{
	s >> a.re >> a.im;
}