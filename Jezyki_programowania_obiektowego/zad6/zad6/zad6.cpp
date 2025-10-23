	#include <iostream>
	#include <string>
	#include <map>
	using namespace std;

	class Ship
	{
	public:
		string MS; //nazwa statku
		int capicity; //ladownosc w tonach
		map<string, pair<int, int>> wares;//nazwa, liczba paczek, masa paczki
		static int how_many;

		Ship(string name, int cap) : MS(name), capicity(cap)
		{

		}

		~Ship()
		{

		}

		virtual void loadShip(string name, int packages, int weight)
		{
			if (weight * packages <= capicity)
			{
				if (wares.find(name) != wares.end()) //jeżeli produkt juz istnieje
				{
					wares[name].first += packages; // Update the package count
					wares[name].second += packages * weight; // Update the total weight
				}
				else
				{
					wares[name] = make_pair(packages, packages * weight);
				}
				cout << "Loaded " << packages << " packages of " << name << " to the ship." << endl;
			}
			else {
				cout << "Not enough capacity to load " << endl;
			}
		}

		virtual void unloadShip(string name, int packages, int weight)
		{
			if (wares.find(name) != wares.end()) //jeżeli produkt juz istnieje
			{
				wares[name].first -= packages; //Update the package count
				wares[name].second -= packages * weight; //Update the total weight
			}
		}

		virtual void emptyShip()
		{
			wares.clear();
		}


		void displayShipPackages() {
			cout << "Packages loaded on ship " << MS << ":" << endl;
			for (const auto& pair : wares) {
				cout << " - " << pair.first << ": " << pair.second.first << " packages,total weight " << pair.second.second << " tons" << endl;
			}
		}

	};


	int main()
	{
		Ship myShip("Titanic", 1000); 
		myShip.loadShip("Books", 50, 10); 
		myShip.loadShip("Food", 100, 5); 

		myShip.displayShipPackages();
	}
