#include"Course.h"
#pragma once
class Lab : public Course {
	int insemMarks, endsemMarks;
	std::string result;
public:
	//parameterized constructor
	Lab(int insem_marks, int endsem_marks, std::string course_name, std::string course_code, int credit_val) : Course(course_name, course_code, credit_val) {
		insemMarks = insem_marks;
		endsemMarks = endsem_marks;
		result = "NIL";
	}

	Lab() {
		insemMarks = 0;
		endsemMarks = 0;
		result = "";
	}

	void calcResult() {
		if (endsemMarks >= 35 && (endsemMarks + insemMarks >= 50))
			this->result = "PASS";
		else
			this->result = "FAIL";
	}

	std::string getResult() {
		return result;
	}

	//getter function
	int getInsemMarks() {
		return insemMarks;
	}

	//getter function
	int getEndSemMarks() {
		return endsemMarks;
	}

	void viewResult() {
		std::cout << "LAB:\n" << "\tInsem Marks:" << insemMarks << "\tEndsem Marks:" << endsemMarks << "\n\tResult:" << result;
	}
};

