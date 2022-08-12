#pragma once
#include <vector>
#include "student.h"
#include "string.h"
class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;

	Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };//class roster array pointers

public:
	Student** getStudents();

	void parse(string row);

	void add(string sStudentID, string sFirstName, string sLastName,
		string sEmailAddress, int sAge, double sdays1, double sdays2, double sdays3,
		DegreeProgram degreeProgram);

	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void remove(string studentID);

	~Roster();
};

