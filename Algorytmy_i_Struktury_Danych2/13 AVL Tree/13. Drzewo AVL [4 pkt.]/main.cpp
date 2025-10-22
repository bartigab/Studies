#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    int K, value, L, M;
    Tree<double> drzewo;
    
    cin >> K;
    for(int i = 0; i < K; ++i) {
        cin >> value;
        drzewo.add(value);
    }
    cin >> L;

    drzewo.rmv(L);
    
    cin >> M;
    drzewo.display(M);

    
    return 0;
}