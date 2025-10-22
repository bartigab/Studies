#include<iostream>
#include <string>
#pragma once
using namespace std;

class Point
{
    private:
    string name;
    double x_val;
    double y_val;
    
    public:
    
    Point(string n, double x, double y);
    double returnSuma();
    double getX();
    double getY();
    
    friend ostream& operator<<(ostream &cout, const Point &p1);
    
    bool operator<(const Point& other) const {
        
        double sum= x_val+y_val;
        double otherSum= other.x_val + other.y_val;
        
        if( sum!= otherSum)
        {
            return sum < otherSum;
        }
        else if( x_val != other.x_val)
        {
           return x_val < other.x_val; 
        }
        else
        {
            return name < other.name;    
        }
            
        
        
    }
};

