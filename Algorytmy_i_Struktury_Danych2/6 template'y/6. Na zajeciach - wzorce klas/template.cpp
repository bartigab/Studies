  #include "template.h"
  #include<iostream>
  using namespace std;
  
    template <class T> Sum<T>::Sum(T o1, T o2): obj1(o1), obj2(o2) {}
        
    template <class T> T Sum<T>::dodaj()
    {
        return obj1+obj2;
    }
    
    
        
    template class Sum<int>;
    template class Sum<double>;
    template class Sum<string>;
    
    