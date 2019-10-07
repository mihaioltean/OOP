#include "view.h"
#include <iostream>
using namespace std;

//---------------------------------------------------------------------
float t_eq2_view::read_a(void)
{
	float a;
	cout << "a = ";
	cin >> a;
	return a;
}
//---------------------------------------------------------------------
float t_eq2_view::read_b(void)
{
	float b;
	cout << "b = ";
	cin >> b;
	return b;
}
//---------------------------------------------------------------------
float t_eq2_view::read_c(void)
{
	float c;
	cout << "c = ";
	cin >> c;
	return c;
}
//---------------------------------------------------------------------
void t_eq2_view::print_solutions(float x1_re, float x1_im, float x2_re, float x2_im)
{
	cout << "x1 = " << x1_re << " + " << x1_im << "i" << endl;
	cout << "x2 = " << x2_re << " + " << x2_im << "i" << endl;
}
//---------------------------------------------------------------------