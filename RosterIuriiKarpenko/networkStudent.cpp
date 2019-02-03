#include "networkStudent.h"
using namespace std;


// This constructor will only be called IF the data points to networking degree
networkStudent::networkStudent()
{
}


networkStudent::~networkStudent()
{
}


networkStudent::networkStudent(string _studentID, string _fname, string _lname, string _email,
	int _age, int _course1, int _course2, int _course3, Degree _degree)
{
	setStudentID(_studentID);
	setStudentFirstName(_fname);
	setStudentLastName(_lname);
	setStudentEmail(_email);
	setStudentAge(_age);
	setStudentDaysToCompleteThreeCourses(_course1, _course2, _course3);
	setDegree(_degree);
}

void networkStudent::setDegree(Degree set_degree)
{
	degree = set_degree;
}

Degree networkStudent::getDegreeProgram()
{
	return degree;
}

void networkStudent::print()
{
	cout << studentID << '\t' <<
		"First Name: " << firstName << '\t' <<
		"Last Name: " << lastName << '\t' <<
		"Age: " << age << '\t' <<
		"Days In Course: {" << daysToCompleteThreeCourses[0] << ", " << daysToCompleteThreeCourses[1] <<
		", " << daysToCompleteThreeCourses[2] << "}" << '\t' <<
		"Degree Program: Networking" << endl;
}