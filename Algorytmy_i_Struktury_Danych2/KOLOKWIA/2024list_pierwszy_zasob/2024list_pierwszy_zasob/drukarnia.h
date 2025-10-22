#pragma once
#include <iostream>
#include "ksiazka.h"
using namespace std;

class Ksiazka;

class Drukarnia {
private:

	int min_liczba_stron; //min liczba stron wymaganych do druku
	int printed_zasob_counter;
	
public:
	Drukarnia()
	{		
		min_liczba_stron = 0;
		printed_zasob_counter = 0;
	}

	Drukarnia(int m, int p) : min_liczba_stron(m), printed_zasob_counter(p)
	{

	}

	int getCounter()
	{
		return printed_zasob_counter;
	}

	void setMin_liczba_stron(int min) 
	{
		min_liczba_stron = min;
	}

	void Print(const Ksiazka& ksiazka, Drukarnia& d1)
	{
		if (ksiazka.getStrony() >= d1.min_liczba_stron)
			d1.printed_zasob_counter++;
		else return;
	}

	friend ostream& operator<<(ostream& os, Drukarnia d)
	{
		os << "wydrukowano: " << d.getCounter() << " szt.";
		return os;
	}

};

Drukarnia& operator += (Drukarnia& d1, const Ksiazka& k1)
{
	d1.Print(k1, d1);

	return d1;
}

