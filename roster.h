#pragma once
#include <string>
#include "degree.h"
using std::string;

const string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Zachary,Fredricksen,zfredr2@wgu.edu,26,10,22,34,SOFTWARE"
};

static const int COLUMNS = 9;
static const int NUMBER_OF_STUDENTS = sizeof(studentData) /sizeof(studentData[0]);

class Roster {
	public:
		Student* classRosterArray[NUMBER_OF_STUDENTS] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	
		void add(
			string studentID,
			string firstName,
			string lastName,
			string emailAddress,
			int age,
			int daysInCourse1,
			int daysInCourse2,
			int daysInCourse3,
			Degree degree
		);
		
		void printAverageDaysInCourse(string studentID);
		void printAll();
		void printInvalidEmails();
		void printByDegreeProgram(Degree degree);
		void remove(string studentID);

		~Roster();
};