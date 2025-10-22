#pragma once
#include "ksiazka.h"



template <typename T>
class Node {
private:
	T value;
	Node<T>* next;

public:

	Node(T v) : value(v), next(nullptr)
	{
	};

	~Node() {
		delete value;
	}


	T getData() {
		return value;
	}


	Node<T>* getNext() {
		return next;
	}


	void setNext(Node<T>* n) {
		next = n;
	}






};
