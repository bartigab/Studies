#include<iostream>
#include "tree.h"
using namespace std;

int main() {
    int K, value, L, M;
    Tree<double> drzewo;
    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> value;
        drzewo.add(value);
    }
    cin >> L;
    for(int i = 0; i < L; i++) {
        cin >> value;
        drzewo.rmv(value);
    }
    cin >> M;
    drzewo.display(M);
    cout << drzewo.longestPath(0,*drzewo.root,0) << ' ';
    cout << drzewo.shortestPath(0,*drzewo.root,drzewo.counter) << ' ';
    
    return 1;
}