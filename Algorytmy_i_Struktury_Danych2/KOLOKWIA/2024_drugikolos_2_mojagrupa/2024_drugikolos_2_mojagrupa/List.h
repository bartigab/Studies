#pragma once
#include "Element.h"
#include <iostream>
using namespace std;

class List {
private:
	Node* first;
	Node* last;




public:
	List() : first(nullptr), last(nullptr) {}

	void Add(int value) {
		Node* nowy = new Node(value);

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

	void Display() {
		Node* curr = first;
		for (curr; curr != nullptr; curr = curr->getNext())
		{
			cout << curr->getData();
			if (curr->getNext() != nullptr)
			{
				cout << " ";
			}
		}
	}

	void Swap() {
		if (!first or !first->getNext()) return;

		Node* curr = first;
		first = curr->getNext();

		while (curr && curr->getNext()) {
			Node* nextNode = curr->getNext();

			// Swap the two nodes
			curr->setNext(nextNode->getNext());
			nextNode->setNext(curr);

			// Update previous pointers
			if (curr->getNext()) {
				curr->getNext()->setPrev(curr);
			}

			nextNode->setPrev(curr->getPrev()); // Maintain previous link
			curr->setPrev(nextNode);

			// If nextNode has a previous node, link it properly
			if (nextNode->getPrev()) {
				nextNode->getPrev()->setNext(nextNode);
			}


			curr = curr->getNext();
		}

		// Update last pointer
		last = curr;
		last->setNext(nullptr); // Ensure last node has no next pointer
	}


	void Remove(int val) {
		Node* curr = first;
		while (curr) {
			if (curr->getData() == val) //!!!
			{
				Node* toDelete = curr;
				curr = curr->getNext();
				if (toDelete == first)
				{ //usuwany jest pierwszy element z listy
					first = toDelete->getNext();
					if (first)
						first->setPrev(nullptr);
					else
						last = nullptr;

				}
				if (toDelete == last)
				{	//usuwany ostatni element z listy
					last = toDelete->getPrev();
					if (last)
						last->setNext(nullptr);
					else
						first = nullptr;

				}
				else
				{ //usuwany jakis element w srodku
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

	void Pary(int P)
	{
		Node* curr = first;
		Node* tempfirst = first;
		for (curr; curr != nullptr; curr = curr->getNext())
		{
			tempfirst = curr->getNext();
			for (tempfirst; tempfirst != nullptr; tempfirst = tempfirst->getNext())
			{
				if ((curr->getData() + tempfirst->getData()) == P)
				{
					cout << "(" << curr->getData() << "," << tempfirst->getData() << ") ";

				}

			}
		}
	}

};