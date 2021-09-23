#pragma once
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

class Student {
public:
	const static int courseLoad = 3;
	// Default Constructor
	Student();
	//Student Constructor
	Student(string studentID, string firstName, string lastName, string emailAddy, int age, int courseDaysArray[], DegreeProgram degreeProgram);
	// Destructor
	~Student();

	//Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddy();
	int getAge();
	int* getCourseDaysArray();
	DegreeProgram getDegreeProgram();

	//Setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddy(string emailAddy);
	void setAge(int age);
	void setCourseArray(int courseDaysArray[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	void print();
	void printHeader();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddy;
	int age;
	int courseDaysArray[courseLoad];
	DegreeProgram degreeProgram;
};
