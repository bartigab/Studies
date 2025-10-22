#include<iostream>
#include "product.h"
using namespace std;

ostream& operator<<(ostream &cout, const Product &p)
{
    cout<< p.name << " " << p.netPrice<<endl;
    return cout;
}

int main() {
    
    Product tomato("MyTomato", 1.99, 2, gram, 0.99);
    Product avocado("MyAvacado", 4.99, 2, piece, 2.5);
    
    string name;
    double np,w,gp;
    Unit u;
    string u_str;
    cin>> name >> np >> w >> u_str >>gp;
    u_str == "gram" ? u=Unit::gram : u=Unit::piece;
    
    Product p(name, np, w, u, gp);
    
    tomato+=p;
    cout<<tomato;
    
    return 0;
}