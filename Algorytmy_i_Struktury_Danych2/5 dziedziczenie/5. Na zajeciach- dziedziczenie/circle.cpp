#include<iostream>
#include "circle.h"
#include "pointer.h"

using namespace std;

Circle::Circle(string pointName, string cn_, float r_, float x_, float y_): Pointer(pointName, x_, y_), circlename(cn_), radius(r_)
{
    
}

void Circle::displayCircle()
{
    displayPointer();
    cout<< ", circle: " << circlename << ", radius = " << radius ;
}

float Circle::calcObwod(){
    return 2 * 3.14 * radius;
}