#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string studentData[] =
{
 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 "A5,Matthew,Manning,mmann53@my.wgu.edu,31,10,30,40,SOFTWARE"
};



void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
	
	int daysToCourseCompletion[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] == nullptr) {
			switch (degreeProgram) {
			case NETWORK:
				classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysToCourseCompletion, degreeProgram);
				break;
			case SECURITY:
				classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysToCourseCompletion, degreeProgram);
				break;
			case SOFTWARE:
				classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysToCourseCompletion, degreeProgram);
				break;
			default:
				break;
			}
			break;
		}
	}
	


}

void Roster::print_All() {

	for (int i = 0; i < (sizeof(classRosterArray) / sizeof(classRosterArray[0])); i++) {
		classRosterArray[i]->print();
	}
}

void Roster::remove(string studentID) {
	bool isRemoved = false;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			isRemoved = true;
			break;
		}
	}

	if (isRemoved == false) {
		std::cout << "ERROR: Student ID '" << studentID << "' does not exist \n";
	}

}

void Roster::printDaysInCourse(string studentID) {
	float avgDays = 0;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int *daysInCourse = classRosterArray[i]->getDaysToCourseCompletion();
			for (int j = 0; j < 3; j++) {
				avgDays += daysInCourse[j];
			}
		}
		else {
			break;
		}
		
		std::cout << "Average days left in courses: " << (avgDays / 3) << endl;
	}
}

void Roster::printInvalidEmails() {
	cout << "Invalid Email Addresses:" << "\n";
	string str = "";
	vector<string> badEmails;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		bool isValid = true;
		str = classRosterArray[i]->getEmailAddress();
		int epos = str.find('@');
		int ppos = str.find('.');
		int spos = str.find(' ');
		if (epos == -1) {
			isValid = false;
		} 
		else if (ppos == -1) {
			isValid = false;
		}
		else if (spos != -1) {
			isValid = false;
		}
		if (isValid == false) {
			badEmails.push_back(str);
		}

	}

	for (int i = 0; i < badEmails.size(); i++) {
		cout << badEmails[i] << "\n";
	}
}

void Roster::printByDegreeProgram(int degreeProgram) {

	cout << "Students by Degree: " << degreeTypeStrings[degreeProgram] << "\n";
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

int main() {

	std::cout << "SCRIPTING AND PROGRAMMING APPLICATIONS - C867" << "\n";
	std::cout << "Programed in C++" << endl;
	std::cout << "Author: Matthew Manning | Student ID: 000967779" << "\n\n";

	Roster classRoster;

	string* pStudentData = studentData;

	for (int i = 0; i < (sizeof(studentData)) / (sizeof(studentData[0])); i++) {
		
		stringstream ss(*pStudentData); //stream of chars using pointer string as input

		vector<string> vec;
		string sLine;
		char delim = ',';
		Degree tempDegree;

		// ss input, returns to sLine
		while (getline(ss, sLine, delim)) {
			vec.push_back(sLine);
		}

		/*prints each token
		for (int j = 0; j < vec.size(); j++) {
			cout << vec[j] << "\n";
		}
		*/
		
		if (vec.back() == "NETWORK") {
			tempDegree = NETWORK;
		}
		else if (vec.back() == "SECURITY") {
			tempDegree = SECURITY;
		}
		else if (vec.back() == "SOFTWARE") {
			tempDegree = SOFTWARE;
		}
		else {
			exit(-1);
		}
		classRoster.add(vec[0], vec[1], vec[2], vec[3], stoi(vec[4]), stoi(vec[5]), stoi(vec[6]), stoi(vec[7]), tempDegree);
		pStudentData++;
	}
	
	classRoster.print_All();
	classRoster.printInvalidEmails();
	for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	
	std::system("pause");
	classRoster.~Roster();
	return 0;
}

Roster::~Roster() {

}