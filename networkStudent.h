#pragma once
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student {

	public:

		using Student::Student;
		virtual Degree getDegree();

	protected:

		Degree degree = NETWORK;

};