#pragma once
#include <iostream>
using namespace std;


class Zasob {
private:
	int nr_kat; // np 12345
	std::string title;  //encyklopedia
	int rok_wydania; //2005


public:

	Zasob(int nr, std::string t, int rw) : nr_kat(nr), title(t), rok_wydania(rw)
	{
	};

	Zasob() : Zasob(0, "", 0)
	{
	}

	// Konstruktor kopiuj¹cy
	Zasob(const Zasob& other)
		: nr_kat(other.nr_kat), title(other.title), rok_wydania(other.rok_wydania) {
	}

	int getKat() {
		return nr_kat;
	}
	string getTitle() {
		return title;
	}
	int getRok() {
		return rok_wydania;
	}

	void displayZasob() {
		cout << nr_kat << "(" << title << " " << rok_wydania << ")";
	}

	




};