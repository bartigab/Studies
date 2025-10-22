#include<iostream>
#include "Produkt.h"
#include "Katalog.h"
using namespace std;


int main() {
    
    Katalog katalog;
    string nazwa;
    double netto, brutto, waga;
    string jednostka;
    
    const int k = 4;
    for(int i=0; i < k; ++i)
    {
        cin>> nazwa >> netto >> waga >> jednostka >> brutto;
        Produkt p(nazwa, netto, waga, jednostka, brutto);
        katalog.dodaj(p);
    }
    
    katalog.wyswietlprodukt();
    
    
    return 0;
}