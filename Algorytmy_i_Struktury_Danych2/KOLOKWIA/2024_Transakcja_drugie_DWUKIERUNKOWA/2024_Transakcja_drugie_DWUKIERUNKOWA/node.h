#pragma once
#include <iostream>
#include "transakcja.h"
using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node<T>* next;
	Node<T>* prev;


public:
	Node() {}

	Node(T d) : data(d), next(nullptr), prev(nullptr)
	{
	}

	T getData() {
		return data;
	}

	void setPrev(Node<T>* n) 
	{
		prev = n;
	}

	void setNext(Node<T>* n)
	{
		next = n;
	}

	Node<T>* getPrev() {
		return prev;
	}

	Node<T>* getNext() {
		return next;
	}





};