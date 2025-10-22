#pragma once
#include <iostream>
using namespace std;


class Konto {
protected:
	double stan;
	int numer;


public:



	Konto(double s): stan(s)
	{

	}
	Konto(): numer(100){

	}
	void setNumer(double temp) {
		numer = temp;
	}
	void Wplata(double value) {
		if (value <= 0)
		{
			return;
		}
		else
		{
			stan += value;
		}
	}

	virtual void Wyplata(double value)
	{
		if (value <= 0)
		{
			return;
		}
		else
		{
			if ( stan - value >= 0)
				stan -= value;
			else
				stan = 0;
		}
	}

	double getStan() const {
		return stan;
	}
	int getNumer() const{
		return numer;
	}


};

