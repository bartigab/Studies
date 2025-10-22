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
	List(): udane(0), wszystkie(0)
	{

	}
	List(int u, int w) : udane(u), wszystkie(w), first(nullptr), last(nullptr)
	{
	}

	~List()
	{
		Node<T>* curr = first;
		if (curr != nullptr)
		{
			Node<T>* temp = curr;
			curr = curr->getNext();
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
	
	void Add(T value) //> first najwiekszy
	{
		Node<T>* nowy = new Node<T>(value);

		if (first == nullptr or nowy->getData().getKwota() > first->getData().getKwota())
		{
			nowy->setNext(first);
			first = last = nowy;
		}
		else
		{			
			Node<T>* curr = first;
			while (curr->getNext() != nullptr and curr->getNext()->getData().getKwota() > nowy->getData().getKwota())
			{
				curr = curr -> getNext();
			}
			nowy->setNext(curr->getNext());
			curr->setNext(nowy);
		}
	}


	void Remove(string title)
	{
		Node<T>* curr = first;
		Node<T>* prev = nullptr;

		while (curr != nullptr and curr->getData().getVanillaTitle() != title)
			{
				prev = curr;
				curr = curr->getNext();
			}

			if (curr != nullptr) 
			{
				if (prev == nullptr)
				{
					first = curr->getNext();
					delete curr;
				}
				else
				{
					prev->setNext(curr->getNext());
					delete curr;
				}
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
