#pragma once
#include<iostream>
using namespace std;

enum Jednostka
{
    szt,
    gram
};

class Produkt 
{    
    public:
    Produkt();
    Produkt(string nzw, double n, double w, string j, double b);

    void wyswietl();
    
        
    string nazwa;
    double netto, waga;
    Jednostka jednostka;
    
    private:
    double brutto;
    
    

};