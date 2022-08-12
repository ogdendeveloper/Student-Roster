#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
using std::endl;

class Student
{
public:
	const static int avgDay = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double days[avgDay];//array of number of days to complete each course
	DegreeProgram degreeProgram;
public:
	Student();//empty constructor

	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double days[], DegreeProgram degreeProgram);//constructor 
	~Student();

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	const double* getDays();
	DegreeProgram getDegreeProgram();

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(const double days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();//print

};