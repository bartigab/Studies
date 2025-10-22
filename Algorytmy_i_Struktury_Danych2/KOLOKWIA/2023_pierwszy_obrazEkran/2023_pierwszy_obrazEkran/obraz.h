#include <iostream>
#pragma once
using namespace std;



class Obraz {
private:
	std::string tekst;
	int szerokosc;
	int wysokosc;

public:

	Obraz(string t, int sz, int w);

	Obraz();

	void DisplayText();


	int getSzer();

	int getWys();

	void DisplayX();


};

