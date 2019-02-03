#pragma once
#include <string>
#include <vector>
#include "degree.h"
#include <iostream>
using namespace std;

class student
{
public:
	// default constructor and destructor
	student();
	~student();

	// constructor using all data pieces from the data set
	student(string _studentID, string _fname, string _lname, string _email,
		int _age, int _course1, int _course2, int _course3, Degree _degree);
	
	// accessors of the class Student
	string getStudentID();
	string getStudentFirstName();
	string getStudentLastName();
	string getStudentEmail();
	int getStudentAge();
	int* getStudentDaysToCompleteThreeCourses();
	//This data member is declared in sub-classes, not here.
	//Degree getStudentDegree();

	// mutators of the class Student
	void setStudentID(string in_studentID);
	void setStudentFirstName(string in_fname);
	void setStudentLastName(string in_lname);
	void setStudentEmail(string in_email);
	void setStudentAge(int in_age);
	void setStudentDaysToCompleteThreeCourses(int in_course1, int in_course2, int in_course3);

	// virtual print function, that will be implemented in sub-classes
	virtual void print();

	// virtual getDegreeProgram(), that will be implemented in sub-classes
	virtual Degree getDegreeProgram();

protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToCompleteThreeCourses [3];
	Degree degree;
};