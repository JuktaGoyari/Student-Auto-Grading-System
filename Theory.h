#include"Course.h"
#pragma once
class Theory : public Course {
	int insemMarks, endsemMarks;
	std::string result;
public:

	Theory(int insem_marks, int endsem_marks, std::string course_name, std::string course_code, int credit_val) : Course(course_name, course_code, credit_val) {
		insemMarks = insem_marks;
		endsemMarks = endsem_marks;
		result = "NIL";
	}
	//default constructor
	Theory() {
		insemMarks = 0;
		endsemMarks = 0;
		result = "";
	}

	void calcResult() {
		if (endsemMarks >= 28 && (insemMarks + endsemMarks >= 40))
			this->result = "PASS";
		else
			this->result = "FAIL";
	}
	std::string getResult() {
		return this->result;
	}
	int getInsemMarks() {
		return insemMarks;
	}
	int getEndSemMarks() {
		return endsemMarks;
	}

	void viewResult() {
		std::cout << "Theory:\n" << "\tInsem Mraks:" << insemMarks << "\tEndsem Marks:" << endsemMarks << "\n\tResult:" << result;
	}
};


