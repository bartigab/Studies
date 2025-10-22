#include<iostream>
#include<string>
#include "budynek.h"
using namespace std;

Building::Building(): bname(""), posX(0.0), posY(0.0), height(0.0)
{
    
}

Building::Building(string bn, float pX, float pY, float h)
: bname(bn), posX(pX), posY(pY), height(h)
{
    
}

void Building::display() const
{
    cout<< bname << " " << posX << " " << posY << " " << height;
}

bool Building::compare(const Building& b1, const Building& b2) {
    return (b1.posX + b1.posY) < (b2.posX + b2.posY);
}


string bnamegood(string bname) {
    while (bname.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos)
        cin >> bname;
    return bname;
}

float xgood(float posX) {
    while(posX>90 || posX<-90)
        cin >> posX;
    return posX;
}

float ygood(float posY) {
    while(posY>180 || posY<-180)
        cin >> posY;
    return posY;
}
float heightgood(float height) {
    while(height<0)
        cin >> height;
    return height;
}



