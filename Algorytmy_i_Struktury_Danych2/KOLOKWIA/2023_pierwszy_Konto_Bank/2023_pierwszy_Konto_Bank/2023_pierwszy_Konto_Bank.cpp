#include <iostream>
#include "konto.h"
#include "kontoos.h"
#include "bank.h"
using namespace std;

int main()
{
	//m1
	int N;
	cin >> N;
	while (N<1 || N>10) //mniejsze od 1 i wieksze od 10
	{
	cin >> N;
	}


	double stan;
	double limit;

	Bank b;
	b.setIlosc(N);

	//m2
	for (int i = 0; i < N; i++)
	{
		cin >> stan;
		cin >> limit;

		b.Create(stan, limit, i);

	}

	//m3
	b.Display();
	cout << endl;

	int numer;
	double kwota;
	//m4
	cin >> numer;
	cin >> kwota;
	b.WplataNaNumer(numer, kwota);

	//m5
	cin >> numer;
	cin >> kwota;
	b.WyplataZNumeru(numer,kwota);

	//m6
	b.Display();
	cout << endl;

	//m7
	b.UjemnyBilans();
	cout << endl;

	//m8
	cin >> numer;
	b.Remove(numer);

	//m9
	b.Display();













	return 0;
}

