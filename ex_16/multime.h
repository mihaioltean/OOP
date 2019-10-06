
#define OK 0
#define ELEMENTUL_EXISTA 2

#include <iostream>
using namespace std;

class c_multime {

    private:
        int *elemente;
        int nr_elemente;
		int capacitate;

    public:
        c_multime();
        c_multime(const c_multime&);
        c_multime(int);
        ~c_multime();


        int cardinal(void);
        void curata(void);
        void copiaza(const c_multime &);
        int adauga(int);
        
        void operator+=(int);     
        void operator-=(int);
        void operator+=(const c_multime &);
        void operator-=(const c_multime &);
        c_multime operator+(const c_multime &);
        bool operator==(const c_multime&);
        c_multime& operator=(const c_multime &);
        void operator *=(const c_multime &);
        c_multime operator-(const c_multime &) const;
        c_multime operator*(const c_multime &) const;


        void tipareste_ecran(void);
		void tipareste_fisier(void);
		void citeste_fisier(void);
		bool reuneste(const c_multime &);
        
        void intersecteaza(const c_multime &);
        void intersecteaza(const c_multime &, const c_multime &);
        void diferenta(const c_multime &);
        void diferenta(const c_multime &, const c_multime &);    

        bool apartine(int) const;
        bool reuneste(const c_multime &, const c_multime &);

		friend ostream& operator<<(ostream& o, const c_multime&m);
		friend istream& operator>>(istream& i, c_multime&m);
};