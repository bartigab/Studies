#pragma once
#include "element.h"

template class Node <Ksiazka*>;

template <typename T>
class List {
private:
	Node<T>* first;
	int booksCounter;
	int dostepne;
	int wypozyczone;

public:

	List(): booksCounter(0), dostepne(0), wypozyczone(0), first(nullptr)
	{
	};

	~List() {
		while (first)
		{
			Node<T>* temp = first;
			first = first->getNext();
			delete temp;
		}
	}

	//od najmniejszej do najwiekszej liczby str.
	//dodawanie AddFront jeli mniejsza ni� nast�pna 20 50 140 280

	void Add(T value)
	{
		Node<T>* nowy = new Node<T>(value);

		if (first == nullptr || nowy->getData()->getLiczbaStron() < first->getData()->getLiczbaStron())
		{
			nowy->setNext(first);
			first = nowy;
			booksCounter++;
			if (nowy->getData()->czyDostepna() == true)
				dostepne++;
			else
				wypozyczone++;
		}
		else
		{
			Node<T>* curr = first;
			while (curr->getNext() != nullptr && curr->getNext()->getData()->getLiczbaStron() < nowy->getData()->getLiczbaStron())
			{
				curr = curr->getNext();
			}
			nowy->setNext(curr->getNext());
			curr->setNext(nowy);
			booksCounter++;
			if (nowy->getData()->czyDostepna() == true)
				dostepne++;
			else
				wypozyczone++;
		}
	}
	//2.5

	void Remove(string title)
	{
		Node<T>* prev = nullptr;
		Node<T>* curr = first;
		while (curr != nullptr && curr->getData()->getTytul() != title) //node zajety ale NIE ta wartosc
		{
			prev = curr;
			curr = curr->getNext();
		}

		if (curr != nullptr) 
		{
			bool wasDostepna = curr->getData()->czyDostepna();

				if (prev == nullptr)
					first = curr->getNext();
				else
					prev->setNext(curr->getNext());

			delete curr;
			booksCounter--;

			if (wasDostepna)
				dostepne--;
			else
				wypozyczone--;
		}
	}

	//2.6

	void changeStatus(string title) 
	{
		Node<T>* curr = first;
		
		for(curr; curr != nullptr; curr = curr->getNext())
		{
			if (curr->getData()->getTytul() == title)
			{	
				if (curr->getData()->czyDostepna() == true)
				{
					dostepne--;
					wypozyczone++;
				}
				else
				{
					dostepne++;
					wypozyczone--;
				}

				curr->getData()->zmienStatus();

			}
		}
	}

	//2.7

	void Display() {

		Node<T>* curr = first;
		for (curr; curr != nullptr; curr = curr->getNext())
		{
			cout << curr->getData()->getOpis();
		}
	}

	//2.8

	void Stat() 
	{
		cout << "[" << booksCounter << "] [" << dostepne << "] [" << wypozyczone << "]";
	}







};