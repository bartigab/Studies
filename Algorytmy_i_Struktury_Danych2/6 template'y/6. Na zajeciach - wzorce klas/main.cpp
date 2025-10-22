#include<iostream>
using namespace std;
#include "template.h"

int main() {
    
    int x,y;
    cin>> x>>y;
    Sum<int> dodaj_(x,y);
    cout<< dodaj_.dodaj()<< " ";
    
    double c,d;
    cin>> c>>d;
    Sum<double> dodaj2_(c,d);
    cout<< dodaj2_.dodaj()<< " ";
    
    string e,f;
    cin>> e>>f;
    Sum<string> dodaj3_(e,f);
    cout<< dodaj3_.dodaj()<< " ";

    
    
    
    return 0;
}