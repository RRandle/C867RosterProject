#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

//Constructors
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddy = "";
	this->age = 0;
	for (int i = 0; i < courseLoad; i++) this->courseDaysArray[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddy, int age, int courseDaysArray[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddy = emailAddy;
	this->age = age;
	for (int i = 0; i < courseLoad; i++) this->courseDaysArray[i] = courseDaysArray[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student()
{
}

//Getters

string Student::getStudentID()
{
	return this->studentID;
}

string Student::getFirstName()
{
	return this->firstName;
}

string Student::getLastName()
{
	return this->lastName;
}

string Student::getEmailAddy()
{
	return this->emailAddy;
}

int Student::getAge()
{
	return this->age;
}

int* Student::getCourseDaysArray()
{
	return this->courseDaysArray;
}

DegreeProgram Student::getDegreeProgram()
{
	return this->degreeProgram;
}

//Setters

void Student::setStudentID(string studentID)
{
	this->studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddy(string emailAddy)
{
	this->emailAddy = emailAddy;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setCourseArray(int courseDaysArray[])
{
	for (int i = 0; i < courseLoad; i++) this->courseDaysArray[i] = courseDaysArray[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

//Printer
void Student::print()
{
	cout << this->getStudentID() << '\t';
	cout <<"First Name: "<< this->getFirstName() << '\t';
	cout <<"Last Name: " << this->getLastName() << '\t';
	cout <<"Age: " << this->getAge() << '\t';
	cout <<"Days in Course: {"<< this->getCourseDaysArray()[0] << ',';
	cout << this->getCourseDaysArray()[1] << ',';
	cout << this->getCourseDaysArray()[2] <<"}"<< '\t';
	cout <<"Degree Program: "<< degreeProgramString[this->getDegreeProgram()] << '\n';
}