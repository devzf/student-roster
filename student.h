#pragma once
#include <string>
#include "degree.h"

using std::string;

class Student {
	protected:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int* daysInCourse;
		Degree degree;

	public:
		// Empty and full constructors
		Student();
		Student(
			string studentID, 
			string firstName, 
			string lastName, 
			string emailAddress, 
			int age, 
			int daysInCourse[], 
			Degree degree);

		const static int daysInCourseSize = 3;

		// Define setters for Student class
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setDaysInCourse(int daysInCourse[]);
		void setDegree(Degree degree);

		// Define getters for Student class
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int* getDaysInCourse();
		virtual Degree getDegree() = 0;
		virtual void print();

		// Destructor
		~Student();
};