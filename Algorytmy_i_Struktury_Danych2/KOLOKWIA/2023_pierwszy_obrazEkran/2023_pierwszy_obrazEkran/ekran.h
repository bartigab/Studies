#include <iostream>
#pragma once
using namespace std;


class Ekran {
private:
	string nazwa;
	int width;
	int height;



public:
	
	Ekran(string n, int w, int h) : nazwa(n), width(w), height(h)
	{

	}
	
	Ekran()
	{

	}

	string getNazwa() {
		return nazwa;
	}
	int getWidth() const{
		return width;
	}
	int getHeight() const{
		return height;
	}

	void DisplayEkran(Obraz obr)
	{
		cout << nazwa << "_ekran{" << getWidth() << "," << getHeight() << "}[";
		obr.DisplayText();
		cout << "]";
	}

};

bool operator==(const Ekran& e1, const Ekran& e2)
{
	return (e1.getWidth() == e2.getWidth() && e1.getHeight() == e2.getHeight());
}

