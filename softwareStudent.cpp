#include "softwareStudent.h"
#include <iostream>
using namespace std;

SoftwareStudent::SoftwareStudent() : Student(studentID, firstName, lastName, emailAddress, age, daysToCourseCompletion, degreeProgram) {
	setDegreeProgram(SOFTWARE);
}

//getter and setter for derived attribute
Degree SoftwareStudent::getDegreeProgram() {
	return d;
}

void SoftwareStudent::setDegreeProgram(Degree d) {
	this->degreeProgram = SOFTWARE;
}


void SoftwareStudent::print() {
	this->Student::print();
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
	delete this;
}