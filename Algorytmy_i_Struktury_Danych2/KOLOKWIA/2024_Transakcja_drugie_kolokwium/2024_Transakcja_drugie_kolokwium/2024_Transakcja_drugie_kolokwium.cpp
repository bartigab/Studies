#include <iostream>
#include "transakcja.h"
#include "node.h"
#include "lista.h"
using namespace std;


int main()
{
	//m1
	List<Transakcja> mylista;

	string title_;
	double kwota_;
	bool completed_;

	//m2
	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
	cin>> title_;
	cin>> kwota_;
	cin>> completed_;
	Transakcja values(title_, kwota_, completed_);

	mylista.Add(values);
	}
	
	//m3
	/*
	cout << endl;
	mylista.Stat();
	*/

	//m4
	cout << endl;
	mylista.Display();
	cout << endl;

	cin >> title_;
	mylista.Remove(title_);
	mylista.Display();



	/*
	//m5
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> title_;
		cout<< mylista.Search(title_);
	
		cout << " ";
	}
	*/

}
