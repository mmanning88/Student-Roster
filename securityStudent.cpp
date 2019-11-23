#include "securityStudent.h"
#include <iostream>
using namespace std;

SecurityStudent::SecurityStudent() : Student(studentID, firstName, lastName, emailAddress, age, daysToCourseCompletion, degreeProgram) {
	setDegreeProgram(SECURITY);
}

//getter and setter for derived attribute
Degree SecurityStudent::getDegreeProgram() {
	return d;
}

void SecurityStudent::setDegreeProgram(Degree d) {
	this->degreeProgram = SECURITY;
}

void SecurityStudent::print() {
	this->Student::print();
}


SecurityStudent::~SecurityStudent() {
	Student::~Student();
	delete this;
}