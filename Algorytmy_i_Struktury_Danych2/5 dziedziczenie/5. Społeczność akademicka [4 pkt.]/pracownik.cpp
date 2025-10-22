#include<iostream>
#include "pracownik.h"
using namespace std;

Pracownik::Pracownik(): Osoba(), nazwafirmy(""), stanowisko(""), wyplata(0.0), staz(0.0)
{

}

Pracownik::Pracownik(string imie_, string nazwisko_, float weight_, float height_, int wiek_, Gender g, string nf, string s, float wy, float st)
	: Osoba(imie_, nazwisko_, weight_, height_, wiek_, g), nazwafirmy(nf), stanowisko(s), wyplata(wy), staz(st)
{

}

int Pracownik::doemerytury() {
    int age = Osoba::age;
    Gender g = Osoba::gender;

    if (g == F)
        return 60 - age;
    else
        return 65 - age;
}