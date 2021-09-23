#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main()
{
	cout << "Course Title: C867" << endl;
	cout << "Language: C++" << endl;
	cout << "WGU ID: 001270114" << endl;
	cout << "Name: Ray Randle" << endl;
	cout << endl;

	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Ray,Randle,rrandl8@wgu.edu,33,30,32,36,SOFTWARE"
	};

	Roster classRoster;

	const int studentList = 5;

	//Print All
	cout << "Displaying All Students: " << endl << endl;
	for (int i = 0; i < studentList; i++) classRoster.parse(studentData[i]);

	classRoster.printAll();
	cout << endl;

	//Print Invalid Emails
	cout << "Displaying invalid emails: " << endl << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	//Printing Student Course Averages
	cout << "Student Course Averages: " << endl << endl;
	for (int i = 0; i < studentList; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	//Printing Software Students
	cout << "Displaying students in degree program: " << degreeProgramString[SOFTWARE] << endl << endl;
	classRoster.printByDegreeProgram((DegreeProgram)SOFTWARE);

	//Removing student
	cout << "Removing A3: " << endl << endl;
	classRoster.remove("A3");
	cout << endl;
	classRoster.printAll();
	cout << endl;

	//Removing student again
	classRoster.remove("A3");

	system("pause");

	return 0;
}