#include<iostream>
#include "osoba.h"
#include "student.h"
#include "pracownik.h"
#include "kierunek.h"
#include<string>
using namespace std;

int main() {

    string nazwakierunku;
    cin >> nazwakierunku;
    Kierunek faculty(nazwakierunku);

    string imie, nazwisko;
    float weight, height;
    int age;
    Gender gender;
    double oceny[10]{};

    string indexNo;
    int rok_studiow;

    for (int i = 0; i < 10; ++i)
    {
        cin >> imie;
        cin >> nazwisko;
        cin >> weight;
        cin >> height;
        cin >> age;
        cin >> gender;
        cin >> indexNo;
        cin >> rok_studiow;

            for (int x = 0; x < 5; x++)
                cin >> oceny[x];

        Student student(imie, nazwisko, weight, height, age, gender, indexNo, rok_studiow, oceny);
        faculty.addStudent(student);

    }

    int year;
    cin >> year;
    faculty.displayBestStudents(year);

    string nazwafirmy, stanowisko;
    float wyplata, staz;

    for (int i = 0; i < 2; ++i) 
 {
        cin >> imie;
        cin >> nazwisko;
        cin >> weight;
        cin >> height;
        cin >> age;
        cin >> gender;

        cin >> nazwafirmy;
        cin >> stanowisko;
        cin >> wyplata;
        cin >> staz;

        if(i==0){
            Pracownik pracownikjeden(imie, nazwisko, weight, height, age, gender, nazwafirmy, stanowisko, wyplata, staz);
            cout << pracownikjeden.doemerytury();

        }
        if(i==1){
            Pracownik pracownikdwa(imie, nazwisko, weight, height, age, gender, nazwafirmy, stanowisko, wyplata, staz);
            cout << " " << pracownikdwa.doemerytury();

        }

       
 }





    return 0;
}