#include "networkStudent.h"
#include <iostream>
using namespace std;

NetworkStudent::NetworkStudent() : Student(studentID, firstName, lastName, emailAddress, age, daysToCourseCompletion, degreeProgram){
	setDegreeProgram(NETWORK);
}


//getter and setter for derived attribute
Degree NetworkStudent::getDegreeProgram() {
	return d;
}

void NetworkStudent::setDegreeProgram(Degree d) {
	this->degreeProgram = NETWORK;
}

void NetworkStudent::print() {
	this->Student::print();
}


NetworkStudent::~NetworkStudent() {
	Student::~Student();
	delete this;
}