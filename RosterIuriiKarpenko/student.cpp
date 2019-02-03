#include "student.h"

using namespace std;



student::student()
{
}


student::~student()
{
}

student::student(string _studentID, string _fname, string _lname, string _email,
	int _age, int _course1, int _course2, int _course3, Degree _degree)
{
	setStudentID(_studentID);
	setStudentFirstName(_fname);
	setStudentLastName(_lname);
	setStudentEmail(_email);
	setStudentAge(_age);
	setStudentDaysToCompleteThreeCourses(_course1, _course2, _course3);
}


// Mutators of the class Student
void student::setStudentID(string in_studentID)
{
	studentID = in_studentID;
}

void student::setStudentFirstName(string in_fname)
{
	firstName = in_fname;
}

void student::setStudentLastName(string in_lname)
{
	lastName = in_lname;
}

void student::setStudentEmail(string in_email)
{
	email = in_email;
}

void student::setStudentAge(int in_age)
{
	age = in_age;
}

void student::setStudentDaysToCompleteThreeCourses(int in_course1, int in_course2, int in_course3)
{
	daysToCompleteThreeCourses[0] = in_course1;
	daysToCompleteThreeCourses[1] = in_course2;
	daysToCompleteThreeCourses[2] = in_course3;
}



// Accessors of the class Student
string student::getStudentID()
{
	return studentID;
}

string student::getStudentFirstName()
{
	return firstName;
}

string student::getStudentLastName()
{
	return lastName;
}

string student::getStudentEmail()
{
	return email;
}

int student::getStudentAge()
{
	return age;
}

int* student::getStudentDaysToCompleteThreeCourses()
{
	return daysToCompleteThreeCourses;
}





// These 2 virtual functions will be implemented in subclasses
void student::print()
{
	cout << studentID << '\t' <<
		"First Name: " << firstName << '\t' <<
		"Last Name: " << lastName << '\t' <<
		"Age: " << age << '\t' <<
		"Days In Course: {" << daysToCompleteThreeCourses[0] << ", " << daysToCompleteThreeCourses[1] <<
		", " << daysToCompleteThreeCourses[2] << '}\t' <<
		"Degree Program: " << degree << endl;
}

Degree student::getDegreeProgram()
{
	return NA;
}