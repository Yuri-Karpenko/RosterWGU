#pragma once
#include "student.h"
class softwareStudent :
	public student
{
public:
	softwareStudent();
	~softwareStudent();
	softwareStudent(string _studentID, string _fname, string _lname, string _email,
		int _age, int _course1, int _course2, int _course3, Degree _degree);
	void setDegree(Degree degree);

	Degree getDegreeProgram();

	void print();
private:
	Degree degree;
};

