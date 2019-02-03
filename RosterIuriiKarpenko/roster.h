#pragma once
#include <vector>
#include <array>
#include "student.h"
using namespace std;

class roster
{

public:
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Iurii,Karpenko,ikarpen@wgu.edu,31,1,14,20,SOFTWARE" };
	
	roster();
	~roster();

	vector<student*> classRosterArray;

	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);

	void printAll();

	void remove(string studentID);

	void printInvalidEmails();

	void printAverageDaysInCourse(string studentID);

	void printByDegreeProgram(Degree programDegree);
};

