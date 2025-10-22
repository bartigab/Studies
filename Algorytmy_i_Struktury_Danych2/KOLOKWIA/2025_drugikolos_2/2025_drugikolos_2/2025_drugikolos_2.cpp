#include <iostream>
#include "film.h"
#include "element.h"
#include "lista.h"
using namespace std;


int main()
{
	//M1
	Lista list; 

	//M2
	int M;
	cin >> M;

	//M3
	string tytul;
	string rezyser;
	int dlugosc;
	double ocena;
	string kategoria;
	for (int i = 0; i < M; ++i)
	{
		cin >> tytul >> rezyser >> dlugosc >> ocena >> kategoria;
		Film* val = new Film(tytul, rezyser, dlugosc, ocena, kategoria);
		list.Add(val);
	}
	//M4
	list.Display();

	//M5
	list.Stat();

	//M6 
	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> tytul >> ocena;
		list.changeRating(tytul, ocena);
	}

	
	//M7 

	list.Display();

	//M8
	list.Stat();

	//M9
	int K;
	cout << "podaj liczbe filmow do usuniecia: ";
	cin >> K;
	for (int i = 0; i < K; ++i) 
	{
		cout << "podaj tytul do usuniecia: ";
		cin >> tytul;
		list.Remove(tytul);
	}

	//M10 
	list.Display();

	//M1
	list.Stat();




	



	return 1;
}
