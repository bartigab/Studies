#include<iostream>
#include<string>
#include "template.h"
#include "zwierze.h"
#include "budynek.h"

using namespace std;

int main() {
    
    MyTemplate<Animal> zwierze;
    MyTemplate<Building> budynek;
    
    string name;
    float weight;
    int year;
    string id;
    
    for(int i=0; i<4; ++i)
    {
        cin>>name;
        name=namegood(name);
        cin>>weight;
        weight=weightgood(weight);
        cin>>year;
        year=yeargood(year);
        cin>>id;
        id=idgood(id);
        
        Animal dane(name, weight, year, id);
        zwierze.dodaj(dane);
    }
    
    string bname;
    float posX;
    float posY;
    float height;
    
        for(int i=0; i<4; ++i)
    {
        cin>>bname;
        bname=bnamegood(bname);
        cin>>posX;
        posX=xgood(posX);
        cin>>posY;
        posY=ygood(posY);
        cin>>height;
        height=heightgood(height);
        
        Building dane2(bname, posX, posY, height);
        budynek.dodaj(dane2);
    }
    
    int indeksdousuniecia;
    cin>>indeksdousuniecia;
    zwierze.usun(indeksdousuniecia);
    
    zwierze.sortContainer();
    budynek.sortContainer();
    
    zwierze.displayElementy();
    cout<< " ";
    budynek.displayElementy();
    
    return 0;
}

