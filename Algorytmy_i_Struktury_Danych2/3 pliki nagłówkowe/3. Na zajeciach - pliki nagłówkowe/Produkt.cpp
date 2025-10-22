#include "Produkt.h"
#include<iostream>
using namespace std;
    Produkt::Produkt(): nazwa(""), netto(0.0), waga(0.0), jednostka(Jednostka::gram), brutto(0.0)
    {
    
    }
    
    Produkt::Produkt(string nzw, double n, double w, string j, double b): nazwa(nzw), netto(0.0), waga(0.0), brutto(0.0)
    {
        if( j == "gram")
            jednostka=Jednostka::gram;
        else
            jednostka=Jednostka::szt;
    }

        
    void Produkt::wyswietl()
    {
        
        cout<< nazwa << " ";
    }
    


