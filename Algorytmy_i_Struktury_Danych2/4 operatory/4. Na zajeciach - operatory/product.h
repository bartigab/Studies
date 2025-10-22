#pragma once
#include <iostream>
using namespace std;
enum Unit {gram, piece};

class Product {
    public:
    
        Product();
        
        Product(std::string, double, double, Unit, double);
        
        ~Product();
        
        bool operator+=(const Product &p2);
        
        friend ostream& operator<<(ostream &cout, const Product &);
        double getGrossPrice() const;
        double calcTotalPrice();
    
        std::string name;
        double netPrice;
        double weight;
        Unit unit;
    private:
        double grossPrice_;
    
};