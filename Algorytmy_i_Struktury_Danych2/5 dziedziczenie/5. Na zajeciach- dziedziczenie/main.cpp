#include<iostream>
#include "pointer.h"
#include "circle.h"
using namespace std;

int main() {
    
 string pointerName, circleName;
 float x, y, radius;
 cin>> x >> y>> radius >> pointerName >> circleName;
 
 Circle circle(pointerName, circleName, radius, x, y);
 circle.displayPointer();
 cout<< " ";
 circle.displayCircle();
 cout<< " " << circle.calcObwod();
    return 0;
}