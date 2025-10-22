#include<iostream>
#include"number.h"
//#include"rational.h"

using namespace std;

int main() {
    Complex *p1;
    
    float a, b;

    cin >> a >> b;
    p1 = new Complex (a, b);
    
    p1 -> displayType();
    p1 -> displayNumber();
    cout << endl;
    
    Number *p2;
    cin >> a >> b;
    p2 = new Rational (a, b);;
    
    p2 -> displayType();
    p2 -> displayNumber();
    cout << endl;

    int size;
    cin >> size; 
    Complex *ctab = new Complex[size];
    
    for (int i = 0; i < size; ++i)
    {
        ctab[i].displayType();
        ctab[i].displayNumber();
    }
    cout << endl;

    cin >> size;    
    Number **tab = new Number*[size];
    
    for (int i = 0; i < size; ++i)
    {
        cin >> a >> b;
        if (((i + 1) % 2) != 0)
        {
            Rational r(a, b);
            tab[i] = &r;
        }
        else
        {
            Complex c(a, b);
            tab[i] = &c;            
        }
        
        tab[i] -> displayType();
        tab[i] -> displayNumber();
    }
    
    
    return 0;
}