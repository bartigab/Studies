#include<iostream>
using namespace std;

int main() {


    string tabString[3] = { "Ala ma kota", "Bartek ma psa", "Jan ma krolika" };

    for (int i = 0; i < 3; i++) {
        cout << tabString[i] << endl;
    }

    for (int i = 0; i < 3; i++) {
        int j = 0;
        while (tabString[i][j]) {
            cout << tabString[i][j] << " i:"<< i << " j:"<<j << " ";
            j++;
        }
        cout << endl;
    }



    return 0;
}