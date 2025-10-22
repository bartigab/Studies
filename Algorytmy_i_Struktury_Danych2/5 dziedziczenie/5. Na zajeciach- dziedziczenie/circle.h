#pragma once
#include<string>
#include "pointer.h"

using namespace std;

class Circle : public Pointer  {
    
    private:
        string circlename;
        float radius;

    public:
    void displayCircle();
    float calcObwod();
    
    Circle(string pointName, string name, float radius, float x, float y);
    
    
    
    
};