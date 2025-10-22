#pragma once
#include <iostream>
#include "transakcja.h"
using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node<T>* next;


public:
	Node(){}

	Node(T d) : data(d), next(nullptr)
	{
	}

	T getData() {
		return data;
	}

	void setNext(Node<T>* n)
	{
		next = n;
	}

	Node<T>* getNext() {
		return next;
	}





};