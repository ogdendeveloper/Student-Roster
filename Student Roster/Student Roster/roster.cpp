#include <vector>
#include <sstream>
#include "Roster.h"

using std::vector;
using std::stringstream;

Student** Roster::getStudents()
{
	return Roster::classRosterArray;//array of pointers
}

void Roster::parse(string row)//parsing
{
	vector<string> result;
	stringstream input(row);
	while (input.good())
	{
		string token;
		getline(input, token, ',');
		result.push_back(token);
	}
	DegreeProgram degType = DegreeProgram::SECURITY;
	if (row.back() == 'K') degType = DegreeProgram::NETWORK;
	if (row.back() == 'E') degType = DegreeProgram::SOFTWARE;

	add(result.at(0), result.at(1), result.at(2), result.at(3), stoi(result.at(4)), stod(result.at(5)), stod(result.at(6)), stod(result.at(7)), degType);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double days1, double days2, double days3, DegreeProgram degreeProgram)//add
{
	double daysArray[3] = { days1,days2,days3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
}

void Roster::printAll()//print all 
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
}

void Roster::printInvalidEmails()//prints invalid emails
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string id = Roster::getStudents()[i]->getEmailAddress();
		if (id.find(' ') != string::npos
			|| id.find('.') == string::npos)
			cout << id << " is invalid!" << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID)//average days in course
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDays()[0] +
				classRosterArray[i]->getDays()[1] +
				classRosterArray[i]->getDays()[2]) / 3.0 << endl;
		}
	}
}

void Roster::remove(string studentID)//remove student with error message if not found
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << "Student " << studentID << " removed." << endl;
		printAll();

	}
	else cout << "Student " << studentID << " not found." << endl;
}

Roster::~Roster()//Destructor 
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destructor called for " << classRosterArray[i]->getStudentID() << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}