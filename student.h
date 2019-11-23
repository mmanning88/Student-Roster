#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student
{
protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysToCourseCompletion;
	Degree degreeProgram;

public:
	Student();	
	Student(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysToCourseCompletion[], 
		Degree degreeProgram
	);
	

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToCourseCompletion();
	virtual Degree getDegreeProgram() = 0; //sublass used to get degree

	//setters
	void setStudentID(std::string studentID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setDaysToCourseCompletion(int daysToCourseCompletion[]);
	void setDegreeProgram(Degree d); //correct degree called in subclasses
	virtual void print() = 0;

	~Student();
};

