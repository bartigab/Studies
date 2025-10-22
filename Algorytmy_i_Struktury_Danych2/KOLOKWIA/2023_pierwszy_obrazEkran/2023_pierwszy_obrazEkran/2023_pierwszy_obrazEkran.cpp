#include <iostream>
#include "obraz.h"
#include "ekran.h"
#include "monitor.h"
using namespace std;


int main()
{
	string nazwa;
	int width;
	int height;

	//m1
	cin >> nazwa >> width >> height;
	Ekran E1(nazwa, width, height);

	cin >> nazwa >> width >> height;
	Ekran E2(nazwa, width, height);

	//m2
	
	string tekst;
	int szerokosc;
	int wysokosc;
	cin >> tekst >> szerokosc >> wysokosc;
	Obraz Obr(tekst, szerokosc, wysokosc);

	//m3
	cout << (E1 == E2);
	cout << " ";

	//m4
	E1.DisplayEkran(Obr);
	cout << " ";
	//m5
	E2.DisplayEkran(Obr);
	cout << " ";

	//m6
	bool lustro;
	cin >> nazwa >> width >> height >> lustro;
	Monitor M(nazwa, width, height, lustro);

	//m7
	M << (Obr);
	cout << " ";

	//m8
	cout << M.getLustro();







	return 1;
}

