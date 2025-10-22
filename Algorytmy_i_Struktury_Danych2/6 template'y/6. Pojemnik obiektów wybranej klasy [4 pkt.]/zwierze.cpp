#include<iostream>
#include<string>
#include "zwierze.h"
using namespace std;

Animal::Animal(): name(""), weight(0.0), year(0), id("")
{
    
}

Animal::Animal(string n, float w, int y, string i)
: name(n), weight(w), year(y), id(i)
{
    
}

    
void Animal::display() const
{
    cout<< name << " " << weight << " " << year << " " << id;
}

bool Animal::compare(const Animal& x1, const Animal& x2) {
    if (x1.year != x2.year)
        return x1.year > x2.year;
    else
        return x1.weight < x2.weight;
}


string namegood(string name) {
    while (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos)
        cin >> name;
    return name;
}

float weightgood(float weight) {
    while(weight<=0)
        cin >> weight;
    return weight;
}

int yeargood(int year) {
    string YEARSTRING = to_string(year);
    while(year<0 || (YEARSTRING.find_first_not_of("0123456789") != string::npos) )
    {
        cin >> year;
    }
    return year;
}

string idgood(string id) {
    while (id.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos)
        cin >> id;
    return id;
}

