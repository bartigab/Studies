#include <iostream>
#include "product.h"
using namespace std;


Product::Product()
{
    //cout << "Creating a product." << endl;
}

Product::~Product() 
{
   // cout << "Now Im become death, the destroyer of the product " << name << endl;
}
        
double Product::getGrossPrice() const {
            return grossPrice_;
}
        
Product::Product(string n, double np, double w, Unit u, double grossPrice)
                : name(n), netPrice(np), weight(w), unit(u), grossPrice_(grossPrice) 
{
    //cout << "Creating a product with data." << endl;
}

double Product::calcTotalPrice() {
    if (unit == gram) {
        return weight/1000*netPrice;
    }
    else
        return weight*netPrice;
}

bool::Product::operator+=(const Product &p2)
{

    netPrice += p2.netPrice;
    grossPrice_ += p2.grossPrice_;
    name += "+" + p2.name;
    return( unit == p2.unit);
}