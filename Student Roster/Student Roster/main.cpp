#include "roster.h"
int main()
{
	const string studentData[] = //student data
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ogden,Developer,Ogdendeveloper@gmail.com,31,03,25,56,SOFTWARE"//student data last item personal information
	};
	const int numStudents = 5;
	Roster classRoster; //instance of Roster class called classRoster

	cout << "C867 " << "C++ " << "000448044 " << "Gordon Cox\n" << endl;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);//students added to classRoster
	cout << "Displaying all students:" << endl;
	classRoster.printAll(); //print all

	cout << "\n" << endl;

	cout << "Displaying students with invalid Emails:" << endl;
	classRoster.printInvalidEmails();//students with invalid emails

	cout << "\n" << endl;

	cout << "Displaying average days in each course: " << endl;
	for (int i = 0; i < numStudents; i++) classRoster.printAverageDaysInCourse(classRoster.getStudents()[i]->getStudentID());//average number of days in course

	cout << "\n" << endl;

	for (int i = 2; i < 3; i++)
	{
		cout << "Displaying students with degree type:" << degreeProgramStrings[i] << endl;//displaying only students with degree type software
		classRoster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "\n" << endl;


	cout << "Removing student A3:" << endl;//removing student A3
	cout << "\n" << endl;
	classRoster.remove("A3");

	cout << "\n" << endl;

	cout << "Removing student A3" << endl;
	cout << "\n" << endl;
	classRoster.remove("A3");
	cout << "\n" << endl;
	system("pause");

	return 0;
}