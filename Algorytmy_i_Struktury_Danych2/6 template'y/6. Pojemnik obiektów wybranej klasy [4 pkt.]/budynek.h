#pragma once
#include<iostream>
#include<string>
#include "template.h"
using namespace std;


class Building
{
    private:
    string bname;
    float posX;
    float posY;
    float height;
    
    public:
    Building();
    Building(string bn, float pX, float pY, float h);
    void display() const;
    static bool compare(const Building& b1, const Building& b2);
    
    int getGPS()  { return posX+posY; }
    
};

string bnamegood(string bname);
float xgood(float posX);
float ygood(float posY);
float heightgood(float height);