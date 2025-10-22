#include <iostream>
#include "ksiazka.h"
#include "element.h"
#include "lista.h"
using namespace std;


int main()
{
	string tytul; // Tytuł książki
	string autor; // Autor książki
	int liczbaStron; // Liczba stron
	bool status; // Status dostępności (true = dostępna, false = wypożyczona)

	//M1
	List<Ksiazka*> lista;
	//M2
	int K;
	cin >> K;
	//M3
	for (int i = 0; i < K; i++)
	{
		cin >> tytul;
		cin >> autor;
		cin >> liczbaStron;
		cin >> status;
		Ksiazka* k = new Ksiazka(tytul, autor, liczbaStron, status);
		lista.Add(k);

	}
	//M4
	lista.Display();
	cout << endl;

	//M5
	lista.Stat();
	cout << endl;

	//M6
	int S;
	cin >> S;
	for (int i = 0; i < S; i++)
	{
		cin >> tytul;
		lista.changeStatus(tytul);
	}

	//M7
	lista.Display();
	cout << endl;

	//M8
	lista.Stat();
	cout << endl;

	//M9
	int J;
	cin >> J;
	for (int i = 0; i < J; i++)
	{
		cin >> tytul;
		lista.Remove(tytul);
	}

	//M10
	lista.Display();
	cout << endl;

	//M11
	lista.Stat();
	cout << endl;



	return 1;
}

