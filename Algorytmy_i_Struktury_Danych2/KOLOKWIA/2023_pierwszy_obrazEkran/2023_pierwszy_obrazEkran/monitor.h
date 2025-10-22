#include <iostream>
#pragma once
using namespace std;

class Ekran;

class Monitor: public Ekran {
private:


protected: 
	bool lustro; //lustrzane odbicie widziane w monitorze

public:
	bool getLustro() {
		return lustro;
	}
	Monitor(string n, int w, int h, bool l) : Ekran(n, w, h), lustro(l)
	{

	}

	void DisplayMonitor(Obraz obr)
	{
		if (obr.getSzer() < this->getWidth() and obr.getWys() < this->getHeight())
		{
			cout << getNazwa() << "_monitor{" << this->getWidth() << "," << this->getHeight() << "}[";
			obr.DisplayText();
			cout << "]";
		}
		else
		{
			cout << getNazwa() << "_monitor{" << this->getWidth() << "," << this->getHeight() << "}[";
			obr.DisplayX();
			cout << "]";
		}

	}

	Monitor& operator<<(const Obraz& obr)
	{
		DisplayMonitor(obr);

		return *this;
	}

};