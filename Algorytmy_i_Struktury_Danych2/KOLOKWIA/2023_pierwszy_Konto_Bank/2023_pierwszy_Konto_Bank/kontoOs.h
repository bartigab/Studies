#pragma once
#include <iostream>
#include "konto.h"
using namespace std;



class KontoOs : public Konto
{
protected:
	double limit; //wartoœæ  na któr¹ mo¿emy siê zapo¿yczyæ w banku




public:
	KontoOs(double s,double lim) : Konto(s), limit(lim)
	{
	}

	KontoOs(): limit(0)
	{

	}

	double getLimit() const {
		return limit;
	}

	virtual void Wyplata(double value) override
	{
		if (value <= 0)
		{
			return;
		}
		else
		{
			if (stan - value >= 0-limit)
				stan -= value;
			else
				stan = 0;
		}
	}


	bool operator<(double& value)
	{
		return stan < value;
	}

	ostream& operator<<(ostream& os)
	{
		os << "Nr= " << numer << "B=" << stan << "L=" << limit;
		return os;
	}

};





/* poza klas¹ ostream ok 
	ostream& operator<<(ostream& os, const KontoOs& k)
	{
		os << "Nr= " << k.getNumer() << "B=" << k.getStan() << "L=" << k.getLimit();
		return os;
	}
*/
