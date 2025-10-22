#pragma once
#include <iostream>
#include "zasob.h"
using namespace std;

class Ksiazka : public Zasob
{
private:
	string nazwisko_autora;
	int liczba_przeczytanych_stron;
	int liczba_stron;

public:

	Ksiazka()
	{
		liczba_przeczytanych_stron = 0;
		liczba_stron = 0;
	}

	Ksiazka(int nr, std::string t, int rw, std::string NA, int LPS, int LS) : Zasob(nr, t , rw), nazwisko_autora(NA), liczba_przeczytanych_stron(LPS), liczba_stron(LS)
	{

	};

	void setLiczbaPrzeczytanychStron(int val) {
		liczba_przeczytanych_stron = val;
	}

	string getNazwisko() const{
		return nazwisko_autora;
	}
	int getPrzeczytaneStrony() const{
		return liczba_przeczytanych_stron;
	}
	int getStrony() const {
		return liczba_stron;
	}
	void displayKsiazka()
	{
		cout << getKat() << "(" << getTitle() << " " << getRok() << ") "; //z klasy zasob
		cout << nazwisko_autora << ", str." << liczba_przeczytanych_stron << "/" << liczba_stron << endl;
	}

	bool operator!() 
	{
	return this->getPrzeczytaneStrony() == this->getStrony();
	}



};	

	Ksiazka& operator+=(Ksiazka& k, const int &value) //dodanie liczby przeczytanych stron do ksiazki
		{
		if (value <= k.getStrony())
			k.setLiczbaPrzeczytanychStron(value);
		else
		{
			int full = k.getStrony();
			k.setLiczbaPrzeczytanychStron(full);
		}


		return k;
		}
