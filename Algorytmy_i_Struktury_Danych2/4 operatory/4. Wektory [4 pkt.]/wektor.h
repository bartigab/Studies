#pragma once
#include <iostream>
using namespace std;

class Wektor
{    
    private:
    
    static const int MAX_ROZMIAR = 100; 
    int size;
    int current_size;

    double vector[MAX_ROZMIAR]{};   

    
    public:
    

    Wektor(int s);
    double podaj(int indeks) const;
    void wpisz(int indeks, double wartosc);
    int rozmiar() const;
    void dodaj(const Wektor &w1);
    Wektor& operator+=(const Wektor &w1);
    Wektor& operator-=(const Wektor &w1);
    Wektor& operator=(const Wektor &w1);
    double& operator[](int indeks);
    friend ostream& operator<<(ostream &cout, const Wektor &w1);
    Wektor operator+(const Wektor &w1);
    Wektor operator-(const Wektor &w1);
    Wektor operator!();
    
};


