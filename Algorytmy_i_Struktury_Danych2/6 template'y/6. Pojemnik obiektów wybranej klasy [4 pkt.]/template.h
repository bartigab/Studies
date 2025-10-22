#pragma once
#include<iostream>
#include "zwierze.h"
#include "budynek.h"
#include <algorithm>
using namespace std;

template <class T> class MyTemplate
{

private:
    T tab[6];
    int rozmiar;
    int indexNo;
    T obj;
    
public:  
    MyTemplate();
    MyTemplate(T t, int c, int in, T o);
    
    void dodaj(T element);
    void usun(int indexNo);
    
    T& pobierzObiekt(int index);
    
    void sortContainer();
    void displayElementy();
    
friend class Animal;
friend class Building;

};




