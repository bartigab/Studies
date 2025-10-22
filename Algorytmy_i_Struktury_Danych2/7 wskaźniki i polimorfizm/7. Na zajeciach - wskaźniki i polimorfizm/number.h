#pragma once
#include<iostream>
#include<string>
class Number
{
    public:
    virtual void displayNumber() = 0;
    void displayType();
    
    
    
    
};

class Complex: public Number
{
    private:
        float Re, Im;
        
    
    public:
        Complex();
        Complex(float r, float i);
        
        virtual void displayNumber() override;
        void displayType();
    
        
};

class Rational: public Number
{
    private:
        float a, b;
    
    public:
        Rational();
        Rational(float a_, float b_);
        virtual void displayNumber() override;
        void displayType();
};
