#include <iostream>
#include "multime.h"

c_multime::c_multime()
{
    nr_elemente = 0;
}
c_multime::c_multime(const c_multime &a)
{
    copiaza(a);
}
c_multime::c_multime(int x)
{
    nr_elemente = 1;
    elemente[0] = x;
}
c_multime::~c_multime()
{
    nr_elemente = 0;
}
int c_multime::cardinal(void)
{
    return nr_elemente;
}

void c_multime::copiaza(const c_multime &a)
{
    nr_elemente = a.nr_elemente;
    for (int i = 0; i < nr_elemente; i++)
        elemente[i] = a.elemente[i];
}

c_multime &c_multime::operator=(const c_multime &a)
{
    nr_elemente = a.nr_elemente;
    for (int i = 0; i < nr_elemente; i++)
        elemente[i] = a.elemente[i];
    // this - returneaza adresa unde incepe obiectul curent
    // *this - returneaza obiectul care se afla la adresa respectiva
    return *this;
}

void c_multime::curata(void)
{
    nr_elemente = 0;
}
int c_multime::adauga(int x)
{

    if (!apartine(x))
    {
        if (nr_elemente == N)
            return CAPACITATE_DEPASITA;

        elemente[nr_elemente] = x;
        nr_elemente++;
        return OK;
    }
    else
        return ELEMENTUL_EXISTA;
}

void c_multime::operator+=(int x)
{
    if (!apartine(x))
    {
        elemente[nr_elemente] = x;
        nr_elemente++;
    }
}
void c_multime::tipareste_ecran(void)
{
    std::cout << " Multimea este = {";
    for (int i = 0; i < nr_elemente - 1; i++)
    {
        std::cout << elemente[i] << ", ";
    }
    std::cout << elemente[nr_elemente - 1] << "} \n";
}
bool c_multime::reuneste(const c_multime &a)
{
    for (int i = 0; i < a.nr_elemente; i++)
        if (adauga(a.elemente[i]) == CAPACITATE_DEPASITA)
            return false;
    return true;
}
void c_multime::operator+=(const c_multime &a)
{
    for (int i = 0; i < a.nr_elemente; i++)
        *this += a.elemente[i]; // derefentiere
}


void c_multime::intersecteaza(const c_multime &a)
{
}

bool c_multime::apartine(int x) const
{

    for (int i = 0; i < nr_elemente; i++)
    {
        if (elemente[i] == x)
            return true;
    }
    return false;
}

bool c_multime::reuneste(const c_multime &a, const c_multime &b)
{
    curata();
    if (!reuneste(a))
        return false;
    if (!reuneste(b))
        return false;
    return true;
}

// nu folosim ampersant cand returnam un obiect care e definit in functie
c_multime c_multime::operator+(const c_multime &a) { 
    
    c_multime tmp;
    tmp += *this;
    tmp += a;

    return tmp;
}

void c_multime::intersecteaza(const c_multime &a, const c_multime &b)
{
    *this = a*b;
}

void c_multime::operator *=(const c_multime &a) {
    for(int i = 0; i < nr_elemente; i++)
        if(!a.apartine(elemente[i])) {
            *this -= elemente[i];
            i--;
        }
}

void c_multime::diferenta(const c_multime &a)
{
    *this -= a;
}
void c_multime::diferenta(const c_multime &a, const c_multime &b) {
    *this=a-b;
}   
bool c_multime::operator==(const c_multime& a) {
    if(nr_elemente != a.nr_elemente) return false;
    for(int i = 0; i< nr_elemente; i++) 
        if(!apartine(a.elemente[i])) return false;
    return true;
}

void c_multime::operator-=(int x){

    for (int i = 0; i < nr_elemente; i++) {
        if(elemente[i]==x) {
            elemente[i]=elemente[nr_elemente -1];
            nr_elemente--;
            break;
        }
    }
}

void c_multime::operator-=(const c_multime &a) {
    for (int i = 0; i < a.nr_elemente; i++) 
        *this -= a.elemente[i];  // [this] returneaza adresa de memorie
}

c_multime c_multime::operator-(const c_multime &a) const{ 
    c_multime tmp;
    tmp = *this;
    tmp-=a;

    return tmp;
}
c_multime c_multime::operator*(const c_multime &a) const {
    c_multime tmp;
    tmp = *this;
    tmp*=a;

    return tmp;

}