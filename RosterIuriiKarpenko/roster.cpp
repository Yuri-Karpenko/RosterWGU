/*
This project is a task from Western Governors University.
Course: Scripting and Programming - Applications.
The program converts the existing array of strings (information about students)
into objects, and creates an array of pointers to point to those Student objects (roster).
There are 3 sub-classes to Student class, that inherit everything, except the program
students are enrolled in (private data member, and setters / getters). Also, print function
is overridden in sub-clases.
Program also can remove students from roster, access different fileds within objects, and
print the information requested.

Author: Yuri Karpenko. January - February, 2019
*/


#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include "Degree.h"
using namespace std;


roster::roster()
{
	int i;
	for (i = 0; i < 5; ++i)
	{
		istringstream tableRowData(studentData[i]);
		string dataPiece;
		vector<string> arguments;
		Degree inputDegree;
		while (getline(tableRowData, dataPiece, ','))
		{
			arguments.push_back(dataPiece);
		}
		if (arguments.at(8) == "NETWORK")
		{
			inputDegree = NETWORKING;
		}
		else if (arguments.at(8) == "SECURITY")
		{
			inputDegree = SECURITY;
		}
		else
		{
			inputDegree = SOFTWARE;
		}
		add(arguments.at(0), arguments.at(1), arguments.at(2), arguments.at(3),
			stoi(arguments.at(4)), stoi(arguments.at(5)), stoi(arguments.at(6)), stoi(arguments.at(7)), inputDegree);
	}
}


roster::~roster()
{
	int i;
	for (i = 0; i < classRosterArray.size(); ++i)
	{
		delete classRosterArray[i];
	}
}


void roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	switch (degreeProgram)
	{
	case NETWORKING:
	{
		networkStudent* networkStudentPntr = nullptr;
		networkStudentPntr = new networkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
		classRosterArray.push_back(networkStudentPntr);
		break;
	}
	case SECURITY:
	{
		securityStudent* securityStudentPntr = nullptr;
		securityStudentPntr = new securityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
		classRosterArray.push_back(securityStudentPntr);
		break;
	}
	case SOFTWARE:
	{
		softwareStudent* softwareStudentPntr = nullptr;
		softwareStudentPntr = new softwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
		classRosterArray.push_back(softwareStudentPntr);
		break;
	}
	}
}


void roster::printAll()
{
	int i;
	for (i = 0; i < 5; ++i)
	{
		classRosterArray[i]->print();
	}
}


void roster::remove(string studentID)
{
	bool found = false;
	int i;
	for (i = 0; i < classRosterArray.size(); ++i)
	{
		string tableStudentID;
		tableStudentID = classRosterArray[i]->getStudentID();
		student* toRemove = nullptr;
		if (tableStudentID.compare(studentID) == 0)
		{
			toRemove = classRosterArray[i];
			delete toRemove;
			classRosterArray.erase(classRosterArray.begin()+i);
			cout << "Student with student ID " << studentID << " was removed from the roster." << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "EROR: There is no student with student ID " << studentID << " in the roster. Your request cannot be completed." << endl;
	}
}


void roster::printInvalidEmails()
{
	cout << endl << "Invalid emails are:" << endl;
	int i;
	for (i = 0; i < 5; ++i)
	{
		string email;
		email = classRosterArray[i]->getStudentEmail();
		if (strchr(email.c_str(), '@') == NULL || strchr(email.c_str(), '.') == NULL || strchr(email.c_str(), ' ') != NULL)
		{
			cout << classRosterArray[i]->getStudentEmail() << endl;
		}
	}
	cout << endl;
}


void roster::printAverageDaysInCourse(string studentID)
{
	int i;
	for (i = 0; i < 5; ++i)
	{
		string tableStudentID;
		tableStudentID = classRosterArray[i]->getStudentID();
		if (tableStudentID.compare(studentID) == 0)
		{
			int* arrayOfDays;
			arrayOfDays = classRosterArray[i]->getStudentDaysToCompleteThreeCourses();
			int avrDaysInCourse = (arrayOfDays[0] + arrayOfDays[1] + arrayOfDays[2]) / 3;
			cout << classRosterArray[i]->getStudentFirstName() << " " << classRosterArray[i]->getStudentLastName() << ": " << avrDaysInCourse << endl;
		}
	}
}


void roster::printByDegreeProgram(Degree programDegree)
{
	cout << endl << "Students in Software program are:" << endl;
	int i;
	for (i = 0; i < 5; ++i)
	{
		Degree inputProgramDegree;
		inputProgramDegree = classRosterArray[i]->getDegreeProgram();
		if (programDegree == inputProgramDegree)
		{
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}



int main()
{
	cout << "Course: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 001026526" << endl;
	cout << "Name: Iurii Karpenko" << endl << endl;
	roster classRoster;
	cout << "Printing all students in the roster:" << endl << endl;
	classRoster.printAll();
	classRoster.printInvalidEmails();
	cout << "Average days a student took to complete a class:" << endl;
	int i;
	for (i = 0; i < 5; ++i)
	{
		string input;
		input = classRoster.classRosterArray[i]->getStudentID();
		classRoster.printAverageDaysInCourse(input);
	}
	classRoster.printByDegreeProgram(SOFTWARE);
	
	cout << "Removing student with A3 ID:" << endl;
	classRoster.remove("A3");
	cout << "Trying to remove student with A3 ID again:" << endl;
	classRoster.remove("A3");
	classRoster.~roster();
	
	return 0;
}