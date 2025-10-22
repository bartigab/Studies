#include <iostream>
#include "transakcja.h"
#include "node.h"
#include "tree.h"
using namespace std;


int main()
{
	Tree myTree;


	double kwota;

	for (int i = 0; i < 7; i++)
	{
		cin >> kwota;

		Transakcja value(kwota);

		myTree.Add(value);


	}
	
	myTree.PreOrder();

	cout << endl;

	myTree.InOrder();
	cout << endl;

	myTree.PostOrder();
	cout << endl;


}
