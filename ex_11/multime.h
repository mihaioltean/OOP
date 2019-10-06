#define N 100
#define OK 0
#define CAPACITATE_DEPASITA 1
#define ELEMENTUL_EXISTA 2

class c_multime {

    private:
        int elemente[N];
        int nr_elemente;

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
        bool reuneste(const c_multime &);
        
        void intersecteaza(const c_multime &);
        void intersecteaza(const c_multime &, const c_multime &);
        void diferenta(const c_multime &);
        void diferenta(const c_multime &, const c_multime &);    

        bool apartine(int) const;
        bool reuneste(const c_multime &, const c_multime &);

        
};