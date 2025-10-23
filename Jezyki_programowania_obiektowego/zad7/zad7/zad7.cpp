#include <iostream>
#include <fstream>
#include<string>
#include<regex>
using namespace std;

int find(string name, string nazwisko, string data)
{
    ifstream file("patientRecords.txt");
    //file.open(
    //    R"(C:\Users\Dell\source\repos\zad7\zad7\patientRecords.txt)",
    //    ios::in);
    //string input;

    // regex pattern("^" + name + "\\s+" + nazwisko + "$");
    regex pattern(name + "\\s+" + nazwisko + "\\s" + data + "\\d{5}");

    string line;
    int recordNumber = 1;

    while (getline(file, line)) {
        if (regex_search(line, pattern)) {
            file.close();
            return recordNumber;
        }
        recordNumber++;
    }

    file.close();
    return 0;
    
}
int main()
{
    string name = "Adam";
    string nazwisko = "Nowak";
    string data = "680510";

    int wynik = find(name, nazwisko, data);

    cout << wynik;

    return 1;   
}
