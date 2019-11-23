#pragma once
#include "degree.h"
#include "student.h"
using namespace std;
class SecurityStudent : public Student
{
using Student::Student;

public:

	SecurityStudent();
	void setDegreeProgram(Degree d);
	Degree getDegreeProgram();
	void print();

private:

	Degree d = SECURITY;

	~SecurityStudent();
};


