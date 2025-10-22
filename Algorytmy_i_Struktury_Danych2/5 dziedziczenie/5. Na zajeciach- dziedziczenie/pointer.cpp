#include<iostream>
#include "pointer.h"

using namespace std;

Pointer::Pointer(string n_, float x_, float y_): name(n_), x(x_), y(y_)
{
    
}

void  Pointer::displayPointer() {
    
    cout<< "Point: " << name << "(" << x << ", " << y << ")";
}