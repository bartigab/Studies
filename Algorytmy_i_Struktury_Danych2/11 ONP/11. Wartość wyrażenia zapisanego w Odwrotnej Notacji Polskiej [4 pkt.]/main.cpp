#include<iostream>
#include<string>
#include<stack>
using namespace std;

int dzialanie(double a, double b, char oper)
{
	switch(oper)
	{
		case '+': 
			return a + b;
		case '-': 
			return a - b;
		case '*': 
			return a * b;
		case '/': 
			return a / b;
	}
	return 0;
}

bool czy_cyfra(char znak){
	return znak >= '0' && znak <= '9';
}

bool czy_oper(char znak){
	return znak == '+' || znak == '-' || znak == '*' || znak == '/';
}

int str_to_int(string a, int &poz) {
	int liczba = 0;
	while(poz < a.size() && czy_cyfra(a[poz]))
	{
		liczba = liczba * 10 + a[poz] - '0';
		++poz;
	}
	--poz;
	return liczba;
}

int main()
{
	string ONP;
	

	getline(cin, ONP);
	stack<double> stos;
	double a, b;
	

	for(int i = 0;i < ONP.size(); ++i)	{
		if(czy_cyfra(ONP[i]))
			stos.push((str_to_int(ONP, i)));
		else
			if(czy_oper(ONP[i]))
			{
				if(stos.size() < 2) 
				{
					return 0;
				}
				a = stos.top();	
				stos.pop();
				b = stos.top();
				stos.pop();	
				stos.push(dzialanie(b, a, ONP[i])); 
			}
	}
	
	if(stos.size() != 1)
	{

		return 0;
	}
	cout<<stos.top();
	return 0;
}