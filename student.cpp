#include "student.h"
#include <iostream>
using namespace std;

Student::Student() {
	//set default values for constructor
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysToCourseCompletion = new int[3];
	for (int i = 0; i < 3; i++) {
		this->daysToCourseCompletion[i] = 0;
	}

}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCourseCompletion[], Degree degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysToCourseCompletion = new int[3];
	for (int i = 0; i < 3; i++) {
		this->daysToCourseCompletion[i] = daysToCourseCompletion[i];
	}
}

//getters

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int * Student::getDaysToCourseCompletion() {
	return daysToCourseCompletion;
}

//setters
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToCourseCompletion(int daysToCourseCompletion[]) {
	this->daysToCourseCompletion = new int[3];
	for (int i = 0; i < 3; i++) {
		this->daysToCourseCompletion[i] = daysToCourseCompletion[i];
	}
}

void Student::setDegreeProgram(Degree d) {
	this->degreeProgram = d;
}

void Student::print() {

	string degree;

	if (getDegreeProgram() == 0)
		degree = "NETWORK";
	else if (getDegreeProgram() == 1)
		degree = "SECURITY";
	else if (getDegreeProgram() == 2)
		degree = "SOFTWARE";
	
	cout << left << getStudentID() << "\t";
	cout << left << "First Name: " << getFirstName() << "\t";
	cout << left << "Last Name: " << getLastName() << "\t";
	cout << left << "Age: " << to_string(getAge()) << "\t";
	cout << left << "daysInCourse: " << getDaysToCourseCompletion()[0] << "," << getDaysToCourseCompletion()[1] << "," << getDaysToCourseCompletion()[2] << "\t";
	cout << left << degree << "\n";
}

Student::~Student()
{
	if (daysToCourseCompletion != nullptr) {
		delete[] daysToCourseCompletion;
		daysToCourseCompletion = nullptr;
	}
}




