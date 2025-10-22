#pragma once
#include<iostream>
#include<string>
using namespace std;

enum Gender { F, M };

class Osoba
{
private:
    string imie, nazwisko;
    float weight, height;
    int age;
   

public:

    Gender gender;
    Osoba();
    Osoba(string imie, string nazwisko, float weight, float height, int age, Gender g);

    float getWeight();
    float getHeight();
    float calc_BMI();
    void display();

    friend class Pracownik;
    friend class Kierunek;
};

istream& operator>>(istream& s, Gender& g);