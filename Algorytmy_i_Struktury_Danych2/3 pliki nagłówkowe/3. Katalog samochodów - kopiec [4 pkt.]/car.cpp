#include "car.h"



    Car::Car() : numer(""), moc(0), waga(0.0), typ('\0')
    {

    }

    Car::Car(string nr, int m, float w, char t) : numer(nr), moc(m), waga(w), typ(t)
    {

    }
    
    
    string Car::getNumer() {
        return numer;
    }
    int Car::getMoc() {
        return moc;
    }
    float Car::getWaga() {
        return waga;
    }
    char Car::getTyp() {
        return typ;
    }



