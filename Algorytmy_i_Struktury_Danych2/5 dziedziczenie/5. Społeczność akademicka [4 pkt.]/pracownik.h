#pragma once
#include "osoba.h"

class Pracownik : public Osoba {

private:
	string nazwafirmy, stanowisko;
	float wyplata, staz;

public:
	Pracownik();
	Pracownik(string imie, string nazwisko, float weight, float height, int age, Gender g, string nf, string s, float wy, float st);


	int doemerytury();

};