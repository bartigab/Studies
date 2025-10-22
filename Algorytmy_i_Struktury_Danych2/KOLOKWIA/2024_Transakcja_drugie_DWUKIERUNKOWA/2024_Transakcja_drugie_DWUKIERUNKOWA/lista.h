#pragma once
#include <iostream>
#include "node.h"
using namespace std;



template <typename T>
class List {
private:
	Node<T>* first;
	Node<T>* last;

	int udane;
	int wszystkie;

public:
	List() : udane(0), wszystkie(0)
	{

	}
	List(int u, int w) : udane(u), wszystkie(w), first(nullptr), last(nullptr)
	{
	}
	
	~List()
	{

		while (first)
		{		
			Node<T>* temp = first;
			first = first->getNext();
			delete temp;

		}
		first = last = nullptr;
	}

	void Display() {
		Node<T>* curr = first;

		for (curr; curr != nullptr; curr = curr->getNext())
		{
			cout << curr->getData().getVanillaTitle() << " " << curr->getData().getKwota() << ", ";
		}

	}

	double Saldo() {
		Node<T>* curr = first;

		double saldo = 0;
		for (curr; curr != nullptr; curr = curr->getNext())
		{
			if (curr->getData().getCompleted() != false)
				saldo += curr->getData().getKwota();
		}
		return saldo;
	}

	/* dziala
	void Add(Transakcja value) {
		Node* nowy = new Node(value);

		if (first == nullptr)
		{
			first = last = nowy;
		}
		else
		{
				last->setNext(nowy);
				last = nowy;

		}
		if (nowy->getData().getCompleted() == true)
			udane++;

		wszystkie++;
	}
*/

	void Add(T value) { //AddLast
		Node<T>* nowy = new Node<T>(value);

		if (first == nullptr)
		{
			first = last = nowy;
		}
		else
		{
			nowy->setPrev(last);			
			last->setNext(nowy);
			last = nowy;
		}

	}

	void Remove(string title)
	{
		Node<T>* curr = first;
		while (curr)
		{
			if (curr->getData().getVanillaTitle() == title)
			{
				Node<T>* toDelete = curr;
				curr = curr->getNext();

				if (toDelete == first)
				{
					first = toDelete->getNext();
					if (first)
						first->setPrev(nullptr);
					else
						last = nullptr;
				}
				if (toDelete == last)
				{
					last = toDelete->getPrev();
					if (last)
						last->setNext(nullptr);
					else
						first = nullptr;
				}
				else
				{
					if (toDelete->getPrev())
						toDelete->getPrev()->setNext(toDelete->getNext());
					if (toDelete->getNext())
						toDelete->getNext()->setPrev(toDelete->getPrev());
				}
				delete toDelete;
			}
			else
			curr = curr->getNext();
		
		}	
		
	}


	void Stat() {
		Node<T>* curr = first;

		cout << Saldo() << " ";
		cout << udane << "/" << wszystkie << " ";
		cout << " ";

	}

	int Search(string tytul)
	{
		Node<T>* curr = first;

		for (curr; curr != nullptr; curr = curr->getNext())
		{
			if (curr->getData().getVanillaTitle() == tytul)
			{
				return 1;
			}
		}
		return 0;

	}





};
