#pragma once
#include <iostream>
using namespace std;

class Film {
private:
	string tytul;
	string rezyser;
	int dlugosc;
	double ocena;
	string kategoria;


public:

	Film(string t, string r, int d, double o, string k) : tytul(t), rezyser(r), dlugosc(d), ocena(o), kategoria(k)
	{
	}

	string getTytul() {
		return tytul;
	}
	string getRezyser() {
		return rezyser;
	}
	int getDlugosc() {
		return dlugosc;
	}
	double getOcena() {
		return ocena;
	}
	string getKategoria() {
		return kategoria;
	}

	void setOcena(double newOcena){
		ocena = newOcena;
	}



};