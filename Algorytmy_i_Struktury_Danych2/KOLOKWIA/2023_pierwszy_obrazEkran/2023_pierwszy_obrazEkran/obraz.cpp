#include "obraz.h"
#include <iostream>




Obraz::Obraz(string t, int sz, int w) : tekst(t), szerokosc(sz), wysokosc(w)
{
}


Obraz::Obraz() : tekst(""), szerokosc(0), wysokosc(0)
{
}

void Obraz::DisplayText()
{
	cout << tekst;
}

int Obraz::getSzer() {
	return szerokosc;
}


int Obraz::getWys() {
	return wysokosc;
}


void Obraz::DisplayX()
{
	int size = 0;
	size = tekst.length();
	for (int i = 0; i < size; i++)
	{
		cout << "x";
	}
}