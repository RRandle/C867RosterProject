#include <iostream>
#include <string>
#include "roster.h"
#include <sstream>
using namespace std;

//Parser
void Roster::parse(string studentdata)
{
	//Parse studentID
	int rightSide = studentdata.find(",");
	string studentID = studentdata.substr(0, rightSide);
	//firstName
	int leftSide = rightSide + 1;
	rightSide = studentdata.find(",", leftSide);
	string firstName = studentdata.substr(leftSide, rightSide - leftSide);
	//lastName
	leftSide = rightSide + 1;
	rightSide = studentdata.find(",", leftSide);
	string lastName = studentdata.substr(leftSide, rightSide - leftSide);
	//emailAddress
	leftSide = rightSide + 1;
	rightSide = studentdata.find(",", leftSide);
	string emailAddress = studentdata.substr(leftSide, rightSide - leftSide);
	//age
	leftSide = rightSide + 1;
	rightSide = studentdata.find(",", leftSide);
	int age = stod(studentdata.substr(leftSide, rightSide - leftSide));
	//course1
	leftSide = rightSide + 1;
	rightSide = studentdata.find(",", leftSide);
	int daysInCourse1 = stod(studentdata.substr(leftSide, rightSide - leftSide));
	//course2
	leftSide = rightSide + 1;
	rightSide = studentdata.find(",", leftSide);
	int daysInCourse2 = stod(studentdata.substr(leftSide, rightSide - leftSide));
	//course3
	leftSide = rightSide + 1;
	rightSide = studentdata.find(",", leftSide);
	int daysInCourse3 = stod(studentdata.substr(leftSide, rightSide - leftSide));
	//Degree Program
	DegreeProgram degreeprogram = UNKNOWN;
	if (studentdata.back() == 'Y') degreeprogram = SECURITY;
	else if (studentdata.back() == 'K') degreeprogram = NETWORK;
	else if (studentdata.back() == 'E') degreeprogram = SOFTWARE;

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int courseAvg[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };

	classRosterArray[++lastStudent] = new Student(studentID, firstName, lastName, emailAddress, age, courseAvg, degreeprogram);
}

void Roster::remove(string studentID)
{
	bool active = false;
	for (int i = 0; i <= Roster::lastStudent; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			active = true;
			if (i < (rosterCount - 1)) {
				Student* interim = classRosterArray[i];
				classRosterArray[i] = classRosterArray[rosterCount - 1];
				classRosterArray[rosterCount - 1] = interim;
			}
			Roster::lastStudent--;
		}
	}
	if (active) {
		cout << studentID << " Removed" << endl;
	}
	else cout << studentID << " not found. " << endl;
}
//Printers

void Roster::printAll()
{
	for (int i = 0; i <= lastStudent; i++) {
		classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastStudent; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << "Student ID: " << classRosterArray[i]->getStudentID() << ", " << "averages " << (classRosterArray[i]->getCourseDaysArray()[0] + classRosterArray[i]->getCourseDaysArray()[1]
				+ classRosterArray[i]->getCourseDaysArray()[2]) / 3 << " days in a course." << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	bool badEmail = false;
	for (int i = 0; i <= Roster::lastStudent; i++) {
		string emailAdd = (classRosterArray[i]->getEmailAddy());
		if (emailAdd.find(' ') != string::npos) {
			badEmail = true;
			cout << emailAdd << ": No spaces allowed." << endl;
		}
		else if (emailAdd.find('.') == string::npos) {
			badEmail = true;
			cout << emailAdd << ": missing a period." << endl;
		}
		else if (emailAdd.find('@') == string::npos) {
			badEmail = true;
			cout << emailAdd << ": missing @ symbol." << endl;
		}
	}
	if (!badEmail) cout << "NONE" << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	for (int i = 0; i <= Roster::lastStudent; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram)
			classRosterArray[i]->print();
	}
	cout << endl;
}

//Destructor
Roster::~Roster()
{
	cout << "Destructor Activated" << endl;
	for (int i = 0; i < rosterCount; i++) {
		cout << "releasing student: " << i + i << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}