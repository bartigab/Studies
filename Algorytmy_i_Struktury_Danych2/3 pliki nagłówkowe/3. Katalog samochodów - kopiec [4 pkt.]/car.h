#pragma once
#include<iostream>
using namespace std;


class Car
{
    private:
    string numer;
    int moc;
    float waga;
    char typ;

    public:
    Car();
    Car(string nr, int m, float w, char t);
    
   


    string getNumer();
    int getMoc();
    float getWaga();
    char getTyp();
  
};
