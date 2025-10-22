#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ksiazka {
public:

	Ksiazka(string tytul, string autor, int liczbaStron, bool dostepnosc) : tytul_(tytul), autor_(autor), liczbaStron_(liczbaStron), dostepnosc_(dostepnosc)
	{
	};

	void zmienStatus() {
		dostepnosc_ = !dostepnosc_;
	}

	std::string getOpis() const {
		string status = dostepnosc_ ? "Dostepna" : "Wypozyczona";
		return "[" + tytul_ + " " + autor_ + " " + std::to_string(liczbaStron_) + " " + status + "]";
	}

	int getLiczbaStron() const
	{
		return liczbaStron_;
	}

	std::string getTytul() const
	{
		return tytul_;
	}


	bool czyDostepna() const
	{
		return dostepnosc_;
	}
private:
	string tytul_; // Tytu� ksi��ki
	string autor_; // Autor ksi��ki
	int liczbaStron_; // Liczba stron
	bool dostepnosc_; // Status dost�pno�ci (true = dost�pna, false = wypo�yczona)

};