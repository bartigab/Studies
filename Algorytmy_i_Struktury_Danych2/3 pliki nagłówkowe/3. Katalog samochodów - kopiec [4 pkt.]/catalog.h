#pragma once
#include "car.h"



class Catalog {

    public:
    Catalog();



    int heapMinChild(int parent);
    void heapRemoveMin();
    void addCar(Car& dane);
    void displayLicenseAndPower();


    
    private:
    Car cars[7];
    int carsSize = 0;

  

};