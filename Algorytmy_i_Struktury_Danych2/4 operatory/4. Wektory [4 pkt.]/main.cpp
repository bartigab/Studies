#include <iostream>
#include"wektor.h"
using namespace std;

ostream& operator<<(ostream &cout, const Wektor &w1)
{
    cout << "[" ;
    
    for (int i = 0; i < w1.rozmiar(); ++i)
    {
        cout <<w1.podaj(i);
        if( i < w1.rozmiar()-1)
        {
            cout << " " ;
        }
    }
    
    cout << "]" ;
    return cout;
}

Wektor Wektor::operator+(const Wektor &w1)
{
    Wektor wynik(size);
    int what_size;
    if( size > w1.size)
        what_size=size;
    else
        what_size=w1.size;
        
    for (int i = 0; i < what_size; ++i)
    {
        wynik.vector[i] = vector[i] + w1.vector[i];
    }
    return wynik;
}

Wektor Wektor::operator-(const Wektor &w1)
{
    Wektor wynik(size);
    int what_size;
    if( size < w1.size)
        what_size=size;
    else
        what_size=w1.size;

    for (int i = 0; i < what_size; ++i)
    {
        wynik.vector[i] = vector[i] - w1.vector[i];
    }
    return wynik;
}

Wektor Wektor::operator!()
{
    Wektor wynik(size);
    for (int i = 0; i < size; ++i)
    {
        wynik.vector[i] = -vector[i];
    }
    return wynik;
}

int main()
{
    
   int n1, n2;
   cout << "n1="; cin >> n1;
   Wektor w1(n1);
   cout << "w1=";
   double x;
   for (int i = 0; i < n1; ++i)
   {
       cin >> x;
       w1.wpisz(i, x);
   }
   
   
   cout << "n2="; cin >> n2;
   Wektor w2(n2);
   
   
   cout << "w2=";
   for (int i = 0; i < n2; ++i)
   {
       cin >> x;
       w2[i] = x;
   }
   
   
   Wektor w3(10), w4(10);
   
   w3 = w1;
   w4 = w1+w2;
   
   
   cout << "w1=" << w1 << endl;
   cout << "w2=" << w2 << endl; 
   cout << "w3=w1=" << w3 << endl;
   cout << "w4=w1+w2" << w4 << endl;
   cout << "!w1=" << !w1 << endl;   
   cout << "w1+w4" << w1+w4 << endl;  
   cout << "w1-w4" << w1-w4 << endl;  
   
   w3.dodaj(w4);
   cout << "w3+=w4 ->" << w3 << endl;
   cout << "w2+=w3 ->" << (w2+=w3) << endl;
   cout << "w1-=w2 ->" << (w1-=w2) << endl;
   

}