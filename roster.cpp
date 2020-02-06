#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"

int main() {
	std::cout << "Course: C867 - Scripting And Programming Applications\nLanguage: C++\nStudent ID: 000999825\nStudent Name: Zachary Fredricksen\n" << std::endl;
	
	Roster classRoster;
	Degree degree;

	string output, row[COLUMNS];

	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i)
	{
		std::istringstream input(studentData[i]);
		for (int j = 0; j < COLUMNS; ++j) {
			std::getline(input, output, ',');
			row[j] = output;
		}

		switch (row[8][2]) {
			case 'C':
				degree = SECURITY;
				break;
			case 'T':
				degree = NETWORK;
				break;
			case 'F':
				degree = SOFTWARE;
				break;
		}

		classRoster.add(
			row[0],
			row[1],
			row[2],
			row[3], 
			std::stoi(row[4]), 
			std::stoi(row[5]), 
			std::stoi(row[6]), 
			std::stoi(row[7]), 
			degree
		);
	}

	// Go through the requirements and print the function outputs to the screen
	std::cout << "Roster:\n";
	classRoster.printAll();
	std::cout << std::endl;
	std::cout << "Invalid emails:\n";
	classRoster.printInvalidEmails();
	std::cout << std::endl;
	std::cout << "Average days to complete a course by student:\n";
	for (int studentNumber = 0; studentNumber < NUMBER_OF_STUDENTS; ++studentNumber) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[studentNumber]->getStudentID());
	}
	std::cout << std::endl;
	std::cout << "Students in degree program SOFTWARE:" << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	std::cout << std::endl;
	classRoster.remove("A3");
	classRoster.remove("A3");
	std::cout << std::endl;
	std::cout << "Roster:" << std::endl;
	classRoster.printAll();
	std::cout << std::endl;

	// Call destructor
	classRoster.~Roster();

	system("PAUSE");
	return 0;
}

void Roster::add(
	string studentID, 
	string firstName, 
	string lastName, 
	string emailAddress, 
	int age, 
	int daysInCourse1, 
	int daysInCourse2, 
	int daysInCourse3, 
	Degree degree) {

	int daysInCourse[] = { 
		daysInCourse1, daysInCourse2, daysInCourse3 
	};

	Student* student = nullptr;

	switch (degree) {
		case SECURITY:
			student = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degree);
			break;
		case NETWORK:
			student = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degree);
			break;
		case SOFTWARE:
			student = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degree);
			break;
	}

		for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
			if (classRosterArray[i] == nullptr) {
				classRosterArray[i] = student;
				break;
			}
		}
};

void Roster::remove(string studentID) {
	std::cout << "Removing student with ID " << studentID << ", ";
	for (int studentNumber = 0; studentNumber < NUMBER_OF_STUDENTS; ++studentNumber) {
		if (classRosterArray[studentNumber] == nullptr) {
			std::cout << "A student with this ID can not be found.\n";
			break;
		}
		else if (studentID == classRosterArray[studentNumber]->getStudentID()) {
			classRosterArray[studentNumber] = nullptr;
			std::cout << "Student removed from the roster.\n";
		}
	}
};

void Roster::printAll() {
	for (int studentNumber = 0; studentNumber < NUMBER_OF_STUDENTS; ++studentNumber) {
		if (classRosterArray[studentNumber] != nullptr) {
			classRosterArray[studentNumber]->print();
		}
	}
};

void Roster::printAverageDaysInCourse(string studentID) {

	float average = 0;
	int courseAmount = 3;
	for (int course = 0; course < sizeof(classRosterArray) / sizeof(classRosterArray[course]); ++course) {
		if (classRosterArray[course] != nullptr && classRosterArray[course]->getStudentID() == studentID) {

			int* daysInCourse = classRosterArray[course]->getDaysInCourse();
			for (int courseDays = 0; courseDays < courseAmount; ++courseDays) {
				average += daysInCourse[courseDays];
			}

			std::cout << "Student " << classRosterArray[course]->getStudentID() << " Average Days: " << ceil(average / courseAmount) << "\n";
			break;
		}
	}
};

void Roster::printByDegreeProgram(Degree degree) {

	for (int studentNumber = 0; studentNumber < NUMBER_OF_STUDENTS; ++studentNumber) {

		Student* student = classRosterArray[studentNumber];

		// Only print the student if the degree type matches
		if (student->getDegree() == degree) {
			student->print();
		}
	}
};

void Roster::printInvalidEmails() {

	bool valid = false;

	for (int student = 0; student < NUMBER_OF_STUDENTS; ++student) {
		string emailAddress = classRosterArray[student]->getEmailAddress();
		bool isValid = false;

		// Go through and check for each piece, only allowing valid email address if it meets all conditions
		size_t found = emailAddress.find("@");

		if (found != string::npos) {
			found = emailAddress.find(".");
			if (found != string::npos) {
				found = emailAddress.find(" ");
				if (found == string::npos) {
					isValid = true;
				}
			}
		}

		// Print the invalid email address
		if (!isValid) {
			std::cout << emailAddress << " is not a valid email address \n";
		}
	}
};

Roster::~Roster() {

};