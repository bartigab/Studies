#include<iostream>
#include "osoba.h"
#include<string>
using namespace std;

Osoba::Osoba(): imie(""), nazwisko(""), weight(0.0), height(0.0), age(0), gender(F)
{

}

Osoba::Osoba(string imie_, string nazwisko_, float weight_, float height_, int wiek_, Gender g)
    : imie(imie_), nazwisko(nazwisko_), weight(weight_), height(height_), age(wiek_), gender(g)
{
   
}

float Osoba::getWeight() {
    return weight;
}

float Osoba::getHeight() {
    return height;
}

float Osoba::calc_BMI() {
    float bmi_value;
    bmi_value = Osoba::getWeight() / Osoba::getHeight() * Osoba::getHeight();
    return bmi_value;
}

void Osoba::display() {
    cout << imie << " " << nazwisko << " " << weight << " " << height << " " << age << " ";
}

istream& operator>>(istream& s, Gender& g) {
    char temp;
    s >> temp;
    switch (temp) {
    case 'K': {
        g = F;
        break;
    }
    case 'M': {
        g = M;
        break;
    }
    default:
        g = F;
        break;
    }
    return s;
}