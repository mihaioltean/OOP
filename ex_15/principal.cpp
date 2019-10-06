#include <iostream>
#include "multime.h"
#include "meniu.h"

int main()
{
    char tasta;
    do
    {
        afiseaza_meniu();
        tasta = getchar();getchar();
        switch (tasta)
        {
        case '1': // implicit
        {
            c_multime a;
            a.tipareste_ecran();
        }
        break;
        case '2': // copiere
        {
            c_multime a(5);
            c_multime b(a);
            b.tipareste_ecran();
        }
        break;
        case '3': // 1 parametru
        {
            c_multime a(5);
        }
        break;
        case '4': // adaugare
        {
            c_multime a;
            int cod = a.adauga(5);
            if (cod == ELEMENTUL_EXISTA)
                std::cout << " Exista deja \n";
            a.tipareste_ecran();
        }
        break;
        case '5': // apartine
        {
            c_multime a;
            int rezultat = a.adauga(5);
            if (a.apartine(5)){
                std::cout << 1;
            }
        }
        break;
        case '6': // reuniune
        {
            c_multime a(3);
            c_multime b(4);
            if (a.reuneste(b))
                a.tipareste_ecran();
            else
                std::cout << " Am depasit capacitatea multimii \n";
        }
        break;
        case '7': // reuniune 2
        {
            c_multime a(3);
            c_multime b(4);
            c_multime c(1);
            if (c.reuneste(a, b))
                c.tipareste_ecran();
            else
                std::cout << " Am depasit capacitatea multimii \n";
        }
        break;
        case '8': // copiaza
        {
            c_multime a(3);
            c_multime b(4);
            c_multime c(1);
            //b.copiaza(a);
            //b.operator=(a);
            // operator overload
            c= b = a; // forma lunga c.operator=(b.operator=(a));
            c.tipareste_ecran();
        }
        break;
        case '9': // +=(int)
        {
            c_multime a(3);
            a += 4;  // forma lunga a.operator+=(4);
            a.tipareste_ecran();
        }
        break;        
        case '0': // +=(c_multime &)
        {
            c_multime a(3);
            c_multime b(4);
            a += b;  // forma lunga a.operator+=(b);
            a.tipareste_ecran();
        }
        break;  
        case 'q': // c = a + b;
        {
            c_multime a(3);
            c_multime b(4);
            c_multime c(2);
            c = a+b; // c.operator=(a.operator+(b));
            c.tipareste_ecran();
        }
        break;        
        case 'w': // a==b
        {
            c_multime a(4);
            c_multime b(4);
            if(a==b) std::cout<<"Multimile sunt egale \n";
            else std::cout<<"Multimile sunt diferite \n";
        }
        break;
        case 'r': // a-=5
        {
            c_multime a(4);
            a+=5;
            a+=3;
            a+=2;
            a-=9;
            a.tipareste_ecran();
        }
        break;
        case 't': // a-=b
        {
            c_multime a(4);
            c_multime b(3);
            b+=5;
            a+=5;
            a+=3;
            a+=2;
            a-=b;
            a.tipareste_ecran();
        }
        break;
        case 'y': // a-=b
        {
            c_multime a(4);
    
            a+=5;
            a+=3;
            a+=2;

            c_multime b(3);
            b+=5;
            
            a*=b;
            a.tipareste_ecran();
        }
        break;     
        case 'u': // a-=b
        {
            c_multime a(4);
    
            a+=5;
            a+=3;
            a+=2;

            c_multime b(3);
            b+=5;
            
            c_multime c;
            c=a-b;
            c.tipareste_ecran();
        }
        break;   
        case 'i': // a-=b
        {
            c_multime a(4);
    
            a+=5;
            a+=3;
            a+=2;

            c_multime b(3);
            b+=5;
            
            c_multime c;
            c=a*b;
            c.tipareste_ecran();
        }
        break;                                   
        }
    } while (tasta != 'E' && tasta != 'e');

}