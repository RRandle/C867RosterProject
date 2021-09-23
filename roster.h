#pragma once
#include "student.h"
#include <iostream>

class Roster {
public:
	void parse(string row);
	void add(string studentID, string firstName, string lastName, string emailAddy, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	~Roster();

public:
	// Pointer Array
	const static int rosterCount = 5;
	int lastStudent = -1;
	Student* classRosterArray[rosterCount];
};
