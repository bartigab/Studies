#pragma once
#include "student.h"

class Kierunek
{
private:
	string nazwa;
	Student tabstudent[5][10]; //5 lat studiow, 10 studentow na roku
	int iloscstudentow;

public:

	Kierunek();
	Kierunek(string nazwa);

	void addStudent(Student s);
	void removeStudent(Student s);
	void sort(int year);
	void displayBestStudents(int year);

};