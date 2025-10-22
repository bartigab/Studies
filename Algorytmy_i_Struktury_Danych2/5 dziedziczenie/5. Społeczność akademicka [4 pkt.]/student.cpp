#include<iostream>
#include "student.h"
using namespace std;

Student::Student(): Osoba(), indexNo(""), rok_studiow(0)
{
	for (int i = 0; i < 10; ++i)
		oceny[i] = 0.0;
}

Student::Student(string imie_, string nazwisko_, float weight_, float height_, int wiek_, Gender g, string in, int rok, double oc[10]) : Osoba(imie_, nazwisko_, weight_, height_, wiek_, g), indexNo(in), rok_studiow(rok){
	for (int i = 0; i < 10; ++i)
		oceny[i] = oc[i];
}

double Student::srednia()
{
	double avg = 0.0;
	for (int i = 0; i < 10; ++i)
	{
		avg += oceny[i];
	}
	avg = avg / 10;
	return avg;
}

bool Student::operator<(Student& s) {
	return srednia() < s.srednia();
}