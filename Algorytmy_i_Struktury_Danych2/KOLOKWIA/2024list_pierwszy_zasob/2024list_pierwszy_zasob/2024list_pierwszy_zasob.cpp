#include <iostream>
#include "zasob.h"
#include "ksiazka.h"
#include "drukarnia.h"
using namespace std;


int main()
{
	int nr_kat; 
	std::string title;  
	int rok_wydania; 
	std::string nazwisko_autora;
	int liczba_przeczytanych_stron;
	int liczba_stron;

	//M1
	int M;
	cin >> M; 
	Ksiazka* ksiazkaTab = new Ksiazka[M];

	//M2
	for (int i=0; i<M; i++)
	{
		cin >> nr_kat;
		cin >> title;
		cin >> rok_wydania;
		cin >> nazwisko_autora;
		cin >> liczba_stron;
		Ksiazka ksiazka(nr_kat, title, rok_wydania, nazwisko_autora,0, liczba_stron);
		ksiazkaTab[i] = ksiazka;
	}
	//M3 liczba zmian stron
	int S;
	cin >> S;

	int index;
	//M4
	for (int i = 0; i < S; i++)
	{
		cin >> index;
		cin >> liczba_przeczytanych_stron;
			for (int j = 0; j < M; ++j)
			{
				ksiazkaTab[index] += liczba_przeczytanych_stron;
			}

	}

	//M5
	for (int i = 0; i < M; i++)
	{
		ksiazkaTab[i].displayKsiazka();
	}

	//M6
	Drukarnia drukarnia;
	int min;
	cin >> min;
	
	drukarnia.setMin_liczba_stron(min);

	//M7
	for (int i = 0; i < M; i++)
	{
		drukarnia += ksiazkaTab[i];
	}

	//M8

	cout << drukarnia;

	return 1;
}

