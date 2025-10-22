#include"wektor.h"
using namespace std;


Wektor::Wektor(int s): size(s)
{
    for(int i = 0; i<size; ++i)
    {
        vector[i]= 0.0;
        current_size++;
    }

}

double Wektor::podaj(int indeks) const{
    if(indeks<size && indeks>=0)
        return vector[indeks];
    else
        return vector[0];
}


void Wektor::wpisz(int indeks, double wartosc)
{
    if(indeks<size && indeks>=0)
    vector[indeks]=wartosc;
}

int Wektor::rozmiar() const{
    return size;
}

void Wektor::dodaj(const Wektor &w1)
{
    int what_size;
    if( size < w1.size)
        what_size=size;
    else
        what_size=w1.size;
        
    for(int i=0; i<what_size; ++i)
    {
        vector[i]+=w1.vector[i];
    }
}

Wektor& Wektor::operator+=(const Wektor &w1)
{
     dodaj(w1);
     
     return *this;
     
}

Wektor& Wektor::operator-=(const Wektor &w1)
{
    int what_size;
    if( size < w1.size)
        what_size=size;
    else
        what_size=w1.size;
        
    for(int i=0; i<what_size; ++i)
    {
        vector[i]-=w1.vector[i];
    }
    
    return *this;
}

Wektor& Wektor::operator=(const Wektor &w1)
{
    size=w1.rozmiar();
    for(int i=0; i<size; ++i)
    {
        vector[i]=w1.vector[i];
    }
    
    return *this;
    
}

double& Wektor::operator[](int indeks)
{

    if(indeks<size && indeks>=0)
        return vector[indeks];
    else
        return vector[0];

    
}

