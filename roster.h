#pragma once
#include <string>
#include <iostream>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"

const int numStudents = 5;

class Roster
{
public:

	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr }; //nullptr will not convert to 0

	/*Takes parsed strings from studentData[]
	passes to subclass constructor for new students based off Degree type*/
	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		Degree degreeProgram);
	
	void print_All();
	void remove(string studentID);
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

	~Roster();
};

