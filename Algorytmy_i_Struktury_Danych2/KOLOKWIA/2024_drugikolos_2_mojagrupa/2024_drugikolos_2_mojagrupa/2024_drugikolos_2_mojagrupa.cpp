#include <iostream>
#include "Element.h"
#include "List.h"
using namespace std;

int main()
{
	List lista;

	int N;
	cin >> N;
	int v;


	for (int i = 0; i < N; i++)
	{
		cin >> v;
		lista.Add(v);
	}
	cout << "[";
	lista.Display();
	cout << "] ";

	int P;
	cin >> P;
	lista.Pary(P);

	lista.Swap();
	cout << "[";
	lista.Display();
	cout << "] ";

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> v;
		lista.Remove(v);
	}

	cout << "[";
	lista.Display();
	cout << "]";






	return 1;
}