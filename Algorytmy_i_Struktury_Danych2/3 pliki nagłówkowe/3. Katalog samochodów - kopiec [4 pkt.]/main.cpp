#include <iostream>
#include "catalog.h"
using namespace std;

bool isValidNumer(string numer)
{

    if ((numer.size()) == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if ( (numer[i] >= '0' && numer[i] <= '9') or (numer[i] >= 'a' && numer[i] <= 'z') or (numer[i] >= 'A' && numer[i] <= 'Z') )
            {
                if(i==3)
                return true;
            }
        }
    }
        return false;
}

bool isValidType(char typ)
{
    if (typ == 'B' or typ == 'D' or typ == 'E' or typ == 'H')
        return true;
    else
        return false;
}


int main()
{
        


    Catalog Katalog;

    string numer;
    int moc;
    float waga;
    char typ;




    const int k = 6;
    for (int i = 0; i < k; ++i)
    {
    
        cin >> numer;
        while (!isValidNumer(numer))
        { 
            cin.clear();
            cin >> numer;
           
        }
        
        
        cin >> moc;
        while (cin.fail() or moc < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> moc;
        }


        cin >> waga;
        while (cin.fail() or waga < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> waga;
        }


        cin >> typ;
        while (!isValidType(typ))
        {
            cin.clear();
            cin >> typ;
        }


        Car car(numer, moc, waga, typ);
        Katalog.addCar(car);
    }


    Katalog.displayLicenseAndPower();

    return 0;
}
    