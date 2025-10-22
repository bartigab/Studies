#pragma once
#include <iostream>
using namespace std;


class Transakcja
{
private:
	string title;
	double kwota;
	bool completed;

public:
	Transakcja()
	{
	}

	Transakcja(string t, double k, bool c) : title(t), kwota(k), completed(c)
	{
	}

	string getTitle() {
		string temp = title;
		string temp2 = "";
		if (completed == false)
			temp2 = "nieudana_";

		if (kwota >= 0)
			temp = temp2 + "wplata_" + title;
		if (kwota < 0)
			temp = temp2 + "wyplata_" + title;

		return temp;
	}

	string getVanillaTitle() {
		return title;
	}
	double getKwota() {
		return kwota;
	}

	bool getCompleted() {
		return completed;
	}



};

