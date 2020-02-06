#include <iostream>
#include "student.h"

// Constructors for Student class
Student::Student() : 
	studentID(""), 
	firstName(""), 
	lastName(""), 
	emailAddress(""), 
	age(-1), 
	daysInCourse(new int[daysInCourseSize]) {
		// Initialize daysInCourse array elements with 0
		for (int course = 0; course < daysInCourseSize; ++course) {
			this->daysInCourse[course] = 0;
		}
	}

Student::Student(
	string studentID, 
	string firstName, 
	string lastName, 
	string emailAddress, 
	int age, 
	int daysInCourse[],
	Degree degree)
	: 
	studentID(studentID), 
	firstName(firstName), 
	lastName(lastName), 
	emailAddress(emailAddress), 
	age(age), 
	daysInCourse(new int[daysInCourseSize]) {
		// set each course day amount to the corresponding element
		for (int course = 0; course < daysInCourseSize; ++course) {
			this->daysInCourse[course] = daysInCourse[course];
		}
	}

// Setters for Student class
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
	this->daysInCourse = new int[daysInCourseSize];
	for (int course = 0; course < daysInCourseSize; ++course) {
		this->daysInCourse[course] = daysInCourse[course];
	}
}

void Student::setDegree(Degree degree) {
	this->degree = degree;
}

// Getters for Student class
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysInCourse() {
	return daysInCourse;
}

Degree Student::getDegree() { 
	return degree;
}

// Print function for base Student class
void Student::print() {
	std::cout << getStudentID() << 
		"\tFirst Name: " << getFirstName() << 
		"\tLast Name: " << getLastName() << 
		"\tAge: " << getAge();
	
	int* days = getDaysInCourse();
	std::cout << "\t  Days in course : " << days[0] << ", " << days[1] << ", " << days[2];

	string degreeType = "";

	switch (getDegree()) {
		case SECURITY:
			degreeType = "SECURITY";
			break;
		case SOFTWARE:
			degreeType = "SOFTWARE";
			break;
		case NETWORK:
			degreeType = "NETWORK";
			break;
		
	}
	std::cout << "\tDegree: " << degreeType << std::endl;
}

// Destructor for Student class
Student::~Student() {

}