#pragma once
#include "degree.h"
#include "student.h"
using namespace std;
class SoftwareStudent : public Student
{
using Student::Student;

public:

	SoftwareStudent();
	void setDegreeProgram(Degree d);
	Degree getDegreeProgram();
	void print();

private:

	Degree d = SOFTWARE;

	~SoftwareStudent();
};
