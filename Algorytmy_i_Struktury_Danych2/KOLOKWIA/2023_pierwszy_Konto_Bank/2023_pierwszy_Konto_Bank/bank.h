#pragma once
#include <iostream>
#include "kontoOs.h"
using namespace std;


class Bank {
private:

	KontoOs* kontaTab = new KontoOs[10];
	int ilosc;



public:
	Bank() {

	}

	~Bank() {
		delete[] kontaTab;

	}

	void setIlosc(int temp)
	{
		ilosc = temp;
	}
	

	int Create(double bilans, double limit, int i)
	{
		
		if (i < ilosc)
		{
			int tempnr;
			KontoOs temp(bilans, limit);
			kontaTab[i] = temp;
			kontaTab[i].setNumer(100 + i);

			tempnr = kontaTab[i].getNumer();
			return tempnr;
		}



		return -1;
	}
	void Remove(int nr_value)
	{
		for (int i = 0; i < ilosc; i++)
		{
			if (kontaTab[i].getNumer() == nr_value)
			{
				for (int j = i; j < ilosc; j++)
				{
					if (j+1 < ilosc)
						kontaTab[j] = kontaTab[j + 1];
					if (j + 1 == ilosc)
						ilosc = ilosc - 1;


				}
			}


		}
	}

	void Display() {
		for (int i = 0; i < ilosc; i++)
		{
			cout << "| Nr=";
			cout << kontaTab[i].getNumer() << " B=" << kontaTab[i].getStan() << " L=" << kontaTab[i].getLimit();
			cout << "| ";
		
		}
	}

	void UjemnyBilans() 
	{
		for (int i = 0; i < ilosc; i++)
		{
			if (kontaTab[i].getStan() < 0)
			{
				cout << "| Nr=";
				cout << kontaTab[i].getNumer() << " B=" << kontaTab[i].getStan() << " L=" << kontaTab[i].getLimit();
				cout << "| ";
			}

		}
	}

	void WplataNaNumer(int nr, double value) 
	{
		for (int i = 0; i < ilosc; i++)
		{
			if (kontaTab[i].getNumer() == nr)
			{
				kontaTab[i].Wplata(value);
			}

		}
	}

	void WyplataZNumeru(int nr, double value)
	{
		for (int i = 0; i < ilosc; i++)
		{
			if (kontaTab[i].getNumer() == nr)
			{
				kontaTab[i].Wyplata(value);
			}

		}
	}


};