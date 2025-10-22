#include "number.h"
#include<iostream>
#include<string>
using namespace std;


Complex::Complex(): Re(0), Im(0)
{
    
}

Complex::Complex(float r, float i)
: Re(r), Im(i)
{
    
}

Rational::Rational(): a(0.0), b(0.0)
{
    
}

Rational::Rational(float a_, float b_): a(a_), b(b_)
{
    
}

void Complex::displayNumber()
{
    cout<< " " << Re << " +/- " << Im << " i";
}

void Rational::displayNumber()
{
    cout<< a << "/" << b;
}

void Complex::displayType()
{
    cout<< "Complex";
}

void Rational::displayType()
{
    cout<< "Rational";
}

