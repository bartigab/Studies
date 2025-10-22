#include "point.h"
#include<iostream>
using namespace std;

Point::Point(string n, double x, double y): 
name(n), x_val(x), y_val(y)
{
    
}

double Point::returnSuma()
{
    return x_val + y_val;
}

double Point::getX()
{
    return x_val;
}

double Point::getY()
{
    return y_val;
}