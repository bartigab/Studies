#pragma once
#include <iostream>
#include "element.h"
using namespace std;



class Lista {
private:
	Element* firstakcja;
	Element* firstdramat;
	Element* firstkomedia;



public:


	Lista(): firstakcja(nullptr), firstdramat(nullptr), firstkomedia(nullptr) 
	{
	}

	~Lista() {
		if (firstakcja != nullptr) {
			Element* temp = firstakcja;
			firstakcja = firstakcja->getNext();
			delete temp;
		}
		if (firstdramat != nullptr) {
			Element* temp = firstdramat;
			firstdramat = firstdramat->getNext();
			delete temp;
		}
		if (firstkomedia != nullptr) {
			Element* temp = firstkomedia;
			firstkomedia = firstkomedia->getNext();
			delete temp;
		}
	}

	void Add(Film* value)
	{
		Element* nowy = new Element(value);
		if (nowy->getData()->getKategoria() == "Akcja") 
		{
			if (firstakcja == nullptr or nowy->getData()->getOcena() > firstakcja->getData()->getOcena())
			{
				nowy->setNext(firstakcja);
				firstakcja = nowy;
			}
			else
			{
				Element* currakcja = firstakcja;

				while (currakcja->getNext()!=nullptr && currakcja->getNext()->getData()->getOcena() > nowy->getData()->getOcena())
				{
					currakcja = currakcja->getNext();
				}
				nowy->setNext(currakcja->getNext());
				currakcja->setNext(nowy);

			}
		}
		if (nowy->getData()->getKategoria() == "Dramat")
		{
			if (firstdramat == nullptr or nowy->getData()->getOcena() > firstdramat->getData()->getOcena())
			{
				nowy->setNext(firstdramat);
				firstdramat = nowy;
			}

			else
			{
				Element* currakcja = firstdramat;

				while (currakcja->getNext() != nullptr && currakcja->getData()->getOcena() > nowy->getData()->getOcena())
				{
					currakcja = currakcja->getNext();
				}
				nowy->setNext(currakcja->getNext());
				currakcja->setNext(nowy);

			}
		}
		if (nowy->getData()->getKategoria() == "Komedia")
		{
			if (firstkomedia == nullptr or nowy->getData()->getOcena() > firstkomedia->getData()->getOcena())
			{
				nowy->setNext(firstkomedia);
				firstkomedia = nowy;
			}
			else
			{
				Element* currakcja = firstkomedia;

				while (currakcja->getNext() != nullptr && currakcja->getData()->getOcena() > nowy->getData()->getOcena())
				{
					currakcja = currakcja->getNext();
				}
				nowy->setNext(currakcja->getNext());
				currakcja->setNext(nowy);

			}
		}

	}


	void Remove(const string& title)
	{

		Element* nodeToRemove = Search(title);


		Element* prev = nullptr;
		if (nodeToRemove==firstakcja)
		{
			Element* curr = firstakcja;
			while (curr != nullptr && curr->getData()->getTytul() != title)
			{
				prev = curr;
				curr = curr->getNext();
			}
			if (curr != nullptr)
			{
				if (prev == nullptr)
				{
					firstakcja = curr->getNext();
					delete curr;
				}
				else
				{
					prev->setNext(curr->getNext());
					delete curr;
				}
			}
		}
		if (nodeToRemove == firstdramat)
		{
			Element* curr = firstdramat;
			while (curr != nullptr && curr->getData()->getTytul() != title)
			{
				prev = curr;
				curr = curr->getNext();
			}
			if (curr != nullptr)
			{
				if (prev == nullptr)
				{
					firstdramat = curr->getNext();
					delete curr;
				}
				else
				{
					prev->setNext(curr->getNext());
					delete curr;
				}
			}
		}
		if (nodeToRemove == firstkomedia)
		{
			Element* curr = firstkomedia;
			while (curr != nullptr && curr->getData()->getTytul() != title)
			{
				prev = curr;
				curr = curr->getNext();
			}
			if (curr != nullptr)
			{
				if (prev == nullptr)
				{
					firstkomedia = curr->getNext();
					delete curr;
				}
				else
				{
					prev->setNext(curr->getNext());
					delete curr;
				}
			}
		}


	}

	Element* Search(const string& title) {


		Element* currakcja = firstakcja;
		for (currakcja; currakcja != nullptr; currakcja = currakcja->getNext())
		{
			if (currakcja->getData()->getTytul() == title)
			{
				return currakcja;
			}
		}
		Element* currdramat = firstdramat;
		for (currdramat; currdramat != nullptr; currdramat = currdramat->getNext())
		{
			if (currdramat->getData()->getTytul() == title)
			{
				return currdramat;
			}
		}
		Element* currkomedia = firstkomedia;
		for (currkomedia; currkomedia != nullptr; currkomedia = currkomedia->getNext())
		{
			if (currkomedia->getData()->getTytul() == title)
			{
				return currkomedia;
			}
		}
		return nullptr;
	}

	void Display() {

		Element* currakcja = firstakcja;

		if (firstakcja != nullptr) {
			for (currakcja; currakcja != nullptr; currakcja = currakcja->getNext())
			{
				cout << "[";
				cout << currakcja->getData()->getTytul();
				cout << "]";
			}
			cout << endl;
		}



		Element* currdramat = firstdramat;
		if (firstdramat != nullptr) {
			for (currdramat; currdramat != nullptr; currdramat = currdramat->getNext())
			{
				cout << "[";
				cout << currdramat->getData()->getTytul();
				cout << "]";
			}
			cout << endl;
		}


		Element* currkomedia = firstkomedia;
		if (firstkomedia != nullptr) {
			for (currkomedia; currkomedia != nullptr; currkomedia = currkomedia->getNext())
			{
				cout << "[";
				cout << currkomedia->getData()->getTytul();
				cout << "]";
			}
			cout << endl;
		}


	}

	void Stat() 
	{
		int counterakcja=0;
		int counterdramat=0;
		int counterkomedia=0;
		double srednia=0;


		Element* currakcja = firstakcja;
		for (currakcja; currakcja != nullptr; currakcja = currakcja->getNext())
		{
			counterakcja++;
			srednia += currakcja->getData()->getOcena();
		}		
		srednia = srednia / counterakcja;
		cout << "Akcja:[" << counterakcja << "] [" << srednia << "]" << endl;

		Element* currdramat = firstdramat;
		for (currdramat; currdramat != nullptr; currdramat = currdramat->getNext())
		{
			counterdramat++;
			srednia += currdramat->getData()->getOcena();
		}
		srednia = srednia / counterdramat;
		cout << "Dramat:[" << counterdramat << "] [" << srednia << "]" << endl;

		Element* currkomedia = firstakcja;
		for (currkomedia; currkomedia != nullptr; currkomedia = currkomedia->getNext())
		{
			counterdramat++;
			srednia += currkomedia->getData()->getOcena();
		}
		srednia = srednia / counterakcja;
		cout << "Komedia:[" << counterkomedia << "] [" << srednia << "]" << endl;

	}

	void changeRating(string tytul, double ocena)
	{
		Element* currakcja = firstakcja;
		for (currakcja; currakcja != nullptr; currakcja = currakcja->getNext())
		{
			if (currakcja->getData()->getTytul() == tytul) 
			{
				currakcja->getData()->setOcena(ocena);
			}
		}
		Element* currdramat = firstdramat;
		for (currdramat; currdramat != nullptr; currdramat = currdramat->getNext())
		{
			if (currdramat->getData()->getTytul() == tytul)
			{
				currakcja->getData()->setOcena(ocena);
			}
		}
		Element* currkomedia = firstkomedia;
		for (currkomedia; currkomedia != nullptr; currkomedia = currkomedia->getNext())
		{
			if (currkomedia->getData()->getTytul() == tytul)
			{
				currakcja->getData()->setOcena(ocena);
			}
		}




	}





};