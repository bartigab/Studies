#pragma once
#include<string>
#include "osoba.h"
using namespace std;

class Student : public Osoba {
private:
	string indexNo;
	int rok_studiow;
	double oceny[10];

public:

	Student();
	Student(string imie, string nazwisko, float weight, float height, int age, Gender g, string indexNo, int rok_studiow, double oceny[10]);

	double srednia();
	bool operator<(Student& s);

	friend class Kierunek;
};