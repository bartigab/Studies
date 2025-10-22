#pragma once
#include <iostream>
using namespace std;


class Transakcja
{
private:

	double kwota;


public:
	Transakcja()
	{
	}

	Transakcja(double k): kwota(k)
	{
	}



	double getKwota() {
		return kwota;
	}


};

