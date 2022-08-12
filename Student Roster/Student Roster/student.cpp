#include "student.h"
Student::Student()//parameterless constructor
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < avgDay; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double days[], DegreeProgram degreeProgram)
//full constructor
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < avgDay; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}
Student::~Student() {}//destructor
//getters
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
const double* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//setters
void Student::setStudentID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(const double days[])
{
	for (int i = 0; i < avgDay; i++) this->days[i] = days[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }


void Student::printHeader()
{
	cout << "studentID - ";
	cout << "firstName - ";
	cout << "lastName - ";
	cout << "emailAddress - ";
	cout << "age - ";
	cout << "average days to complete course - ";
	cout << "degree Program";
	cout << endl;
}

void Student::print()//printed student data
{
	cout << this->studentID << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->emailAddress << '\t';
	cout << this->age << '\t';
	cout << this->days[0] << '\t';
	cout << this->days[1] << '\t';
	cout << this->days[2] << '\t';
	cout << degreeProgramStrings[(int)this->degreeProgram];
	cout << endl;
}