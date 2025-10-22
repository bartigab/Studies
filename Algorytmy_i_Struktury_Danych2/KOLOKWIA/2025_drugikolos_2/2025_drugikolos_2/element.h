#pragma once
#include <iostream>
#include "film.h"
using namespace std;


class Element{
private:
	Film* data;
	Element* next;



public:
	Element(Film* d) : data(d), next(nullptr)
	{}

	Film* getData() {
		return data;
	}

	Element* getNext() {
		return next;
	}

	void setNext(Element* n) {
		next = n;
	}








};