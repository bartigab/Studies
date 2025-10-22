#include "Katalog.h"
using namespace std;

    Katalog::Katalog():  rozmiar(0)
    {
        
    }
    

    void Katalog::wyswietlprodukt ()
    {
        for (int i=0; i<rozmiar; ++i)
        {
            katalog_[i].wyswietl();
        }
    }    
    
    void Katalog::dodaj (Produkt &p)
    {
        if (rozmiar<10)
        {
            katalog_[rozmiar] = p;
            ++rozmiar;
        }
    }
     
    


