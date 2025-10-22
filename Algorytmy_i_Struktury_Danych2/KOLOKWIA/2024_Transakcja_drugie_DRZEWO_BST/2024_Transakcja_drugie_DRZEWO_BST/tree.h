#pragma once
#include <iostream>
#include "node.h"
using namespace std;


class Tree {
private:
	Node* root;


public:

	Tree() : root(nullptr) {}

	void Add(Transakcja value)
	{
		Node* nowy = new Node(value);
		if (root == nullptr) 
		{
			root = nowy;
			return;
		}

		
			Node* curr = root;
			Node* child = nullptr;

			while (curr != nullptr)
			{
				child = curr;
				if ( nowy->getData().getKwota() < curr->getData().getKwota())
				{
					curr = curr -> getLeft();
				}
				else
				{
					curr = curr->getRight();
				}
			}

			if (child != nullptr)
			{
				if (nowy->getData().getKwota() < child->getData().getKwota())
				{
					child->setLeft(nowy);
				}
				else
				{
					child->setRight(nowy);
				}
			}

	}

	void PreOrder(Node* node=nullptr) 
	{
		if (node == nullptr)
		{
			node = root;
		}
		if (node != nullptr)
		{
			cout << " ";
			cout << node->getData().getKwota();

			if (node->getLeft() != nullptr)
				PreOrder(node->getLeft());

			if (node->getRight() != nullptr)
				PreOrder(node->getRight());
		}
	}

	void InOrder(Node* node=nullptr)
	{
		if (node == nullptr)
		{
			node = root;
		}
		if (node != nullptr)
		{
			cout << " ";
			if (node->getLeft() != nullptr)
				InOrder(node->getLeft());

			cout << node->getData().getKwota();
			
			if (node->getRight() != nullptr)
				InOrder(node->getRight());
		}
	}

	void PostOrder(Node* node =nullptr)
	{
		if (node == nullptr)
		{
			node = root;
		}
		if (node != nullptr)
		{
			cout << " ";
			if (node->getLeft() != nullptr)
				PostOrder(node->getLeft());

			if (node->getRight() != nullptr)
				PostOrder(node->getRight());

			cout << node->getData().getKwota();
		}
	}



};