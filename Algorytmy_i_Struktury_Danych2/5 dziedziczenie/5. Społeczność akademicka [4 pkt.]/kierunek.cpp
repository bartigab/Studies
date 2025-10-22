#include<iostream>
#include "kierunek.h"
using namespace std;

Kierunek::Kierunek() : nazwa(""), iloscstudentow(0)
{

}

Kierunek::Kierunek(string nazwa_) : nazwa(nazwa_), iloscstudentow(0)
{

}

void Kierunek::addStudent(Student s) {
    int year = s.rok_studiow - 1;

    for (int i = 0; i < 10; i++) 
    {
        if (tabstudent[year][i].indexNo == "")
        {
            tabstudent[year][i] = s;
            break;
        }
    }
    
    iloscstudentow++;
}

void Kierunek::removeStudent(Student s) {
    int year = s.rok_studiow - 1;

    for (int i = 0; i < 10; i++) {
        if (tabstudent[year][i].indexNo == s.indexNo) {
            if (i < 10 - 1) {
                for (int j = i; j < 10 - 1; j++)
                    tabstudent[year][j] = tabstudent[year][j + 1];
            }
            else {
                tabstudent[year][i] = Student();
            }
            break;
        }
    }
    iloscstudentow--;
}

void Kierunek::sort(int year) {
    int n = 10;
    Student temp;
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (tabstudent[year][i] < tabstudent[year][i + 1]) {
                temp = tabstudent[year][i];
                tabstudent[year][i] = tabstudent[year][i + 1];
                tabstudent[year][i + 1] = temp;
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}

void Kierunek::displayBestStudents(int year) {
    int y = year - 1;
    sort(y);
    for (int i = 0; i < 3; i++)
        cout << tabstudent[y][i].indexNo << " " << tabstudent[y][i].imie << " " << tabstudent[y][i].nazwisko << " ";
}