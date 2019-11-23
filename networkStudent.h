#pragma once
#include "degree.h"
#include "student.h"
using namespace std;
class NetworkStudent : public Student
{
using Student::Student;

public:
	NetworkStudent();
	void setDegreeProgram(Degree d);
	Degree getDegreeProgram();
	void print();

private: 

	Degree d = NETWORK;

	~NetworkStudent();
};

