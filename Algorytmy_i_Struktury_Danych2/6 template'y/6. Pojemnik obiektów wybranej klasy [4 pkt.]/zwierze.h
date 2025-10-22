#pragma once
#include<iostream>
#include<string>
#include "template.h"
using namespace std;

class Animal
{
    private:
    string name;
    float weight;
    int year;
    string id;
    
    
    public:
    Animal();
    Animal(string n, float w, int y, string i);
    void display() const;
    static bool compare(const Animal& x1, const Animal& x2);
    
    int getYear()  { return year; }
    int getWaga()  { return weight; }

    
};


string namegood(string name);
float weightgood(float weight);
int yeargood(int year);
string idgood(string id);
