#pragma once
#include <iostream>
using namespace std;


class Node {
private:
	int value;
	Node* prev;
	Node* next;

public:
	Node(int v) : value(v), prev(nullptr), next(nullptr) {}

	int getData() {
		return value;
	}

	Node* getNext() {
		return next;
	}
	Node* getPrev() {
		return prev;
	}

	void setNext(Node* n) {
		next = n;
	}
	void setPrev(Node* n) {
		prev = n;
	}











};