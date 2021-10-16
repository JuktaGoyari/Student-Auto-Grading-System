#include<string>
#pragma once
class Course {
	std::string courseName, courseCode, * result;
	int credit;
public:

	//parameterized constructor
	Course(std::string course_name, std::string course_code, int credit_val) {
		credit = credit_val;
		courseName = course_name;

		int random = rand() % 900 + 100;
		courseCode = course_code;
	}

	//default constructor defined 
	Course() {
		credit = 0;
		courseName = "";
		int random = 0;
		courseCode = "";

	}

	//getter function for credit
	int getCredit() {
		return credit;
	}

	//getter function for course name
	std::string getCourseName() {
		return courseName;
	}

	//getter function for course code
	std::string getCourseCode() {
		return courseCode;
	}

	std::string* getResult()
	{
		return result;
	}

	//to show the details of the course enrolled by the student
	void viewCourseDetails() {
		std::cout << "\n\tCourse Code:" << courseCode << "\n\t Course name" << courseName << "\n\tCredit:" << credit;
	}

};


