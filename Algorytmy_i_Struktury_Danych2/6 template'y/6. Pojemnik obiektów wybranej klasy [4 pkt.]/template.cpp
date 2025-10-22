#include<iostream>
#include "template.h"
using namespace std;




template <class T> MyTemplate<T>::MyTemplate() : rozmiar(0)
{
    for (int i = 0; i < 6; ++i)
    {
        tab[i] = T();
    }
}

template <class T> MyTemplate<T>::MyTemplate(T t, int c, int in, T o)
    : rozmiar(c), obj(o)
{
    for (int i = 0; i < 6; ++i)
    {
        tab[i] = t;
    }
}

template <class T> void MyTemplate<T>::dodaj(T element) {
    if (rozmiar < 6) {
        tab[rozmiar] = element;
        rozmiar++;
    }
}
    

template <class T> void MyTemplate<T>::usun(int indexNo) 
{
    
    if (indexNo >= 0 && indexNo < rozmiar) 
    {
        if (indexNo == rozmiar - 1)
            rozmiar--;
        else 
        {
            tab[indexNo] = tab[rozmiar - 1];
            rozmiar--;
        }
    }

       
}

template <class T> T& MyTemplate<T>::pobierzObiekt(int index) 
 {
            return tab[index];
}

template <class T>
void MyTemplate<T>::displayElementy() {
    for (int i = 0; i < rozmiar; i++) {
        if (i == rozmiar - 1) {
            tab[i].display();
            break;
        }
        tab[i].display();
        cout << " ";
    }
}

template <class T>
void MyTemplate<T>::sortContainer() {
    if (rozmiar > 1) {
        sort(tab, tab + rozmiar, T::compare);
    }
}

/*template <>
void MyTemplate<Animal>::displayZwierzeta() {
    int mn_index;
    for(int i = 0; i < rozmiar - 1; i++) {
        mn_index = i;
        for(int j = i + 1; j < rozmiar; j++) {
            if(tab[j].getBirthyear() < tab[mn_index].getBirthyear())
                mn_index = j;
        }
        swap(tab[i], tab[mn_index]);
    }
        for(int i = 0; i < rozmiar; i++)
    {
        tab[i].displayAnimal();
    }
}

/*
template<> void MyTemplate<Animal>::displayZwierzeta()
{
    Animal tmpTab[6];
    for(int i = 0; i < rozmiar; i++)
    {
        tmpTab[i] = tab[i];
    }
    for(int i = 0; i < rozmiar - 1; i++)
    {
        for(int j = i + 1; j < rozmiar; j++)
        {
            if(tmpTab[i].getBirthyear() > tmpTab[j].getBirthyear() ||
               (tmpTab[i].getBirthyear() == tmpTab[j].getBirthyear() && tmpTab[i].getWaga() > tmpTab[j].getWaga()))
            {
                swap(tmpTab[i], tmpTab[j]);
            }
        }
    }
    for(int i = 0; i < rozmiar; i++)
    {
        tmpTab[i].displayAnimal();
    }
}*/



/*template<> void MyTemplate<Building>::displayBudynek()
{
    Building tmpTab[6];
    Building tmp,q;
    for(int i=0;i<rozmiar;i++)
    {
        tmpTab[i]=tab[i];
    }
    for(int i=0;i<rozmiar-1;i++)
    {
        for(int j=i+1;j<rozmiar;j++)
        {
            if(tmpTab[i].getGPS()>tmpTab[j].getGPS())
            {
                swap(tmpTab[i],tmpTab[j]);
            }
        }
    }
    for(int i=0;i<rozmiar;i++)
    {
        tmpTab[i].displayBuilding();
    }
}

template <>
void MyTemplate<Building>::displayBudynek() {
    int mn_index;
    for(int i = 0; i < rozmiar - 1; i++) {
        mn_index = i;
        for(int j = i + 1; j < rozmiar; j++) {
            if(tab[j].getGPS() < tab[mn_index].getGPS())
                mn_index = j;
        }
        swap(tab[i], tab[mn_index]);
    }
        for(int i=0;i<rozmiar;i++)
    {
        tab[i].displayBuilding();
    }
}

*/


 template class MyTemplate<Animal>;
 template class MyTemplate<Building>;



