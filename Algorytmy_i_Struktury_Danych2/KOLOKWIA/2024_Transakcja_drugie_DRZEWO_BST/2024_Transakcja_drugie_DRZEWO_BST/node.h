#pragma once
#include <iostream>
#include "transakcja.h"
using namespace std;



class Node {
private:
	Transakcja value;
	Node* left;
	Node* right;

public:
	Node(Transakcja v) : value(v), left(nullptr), right(nullptr)
	{
	}

	Transakcja getData() {
		return value;
	}

	void setLeft(Node* n) {
		left = n;
	}

	Node* getLeft() {
		return left;
	}


	void setRight(Node* n) {
		right = n;
	}
	Node* getRight() {
		return right;
	}




};