#include<iostream>
#include<iomanip>
#include"Course.h"
#include"Lab.h"
#include"Theory.h"
using namespace std;
#pragma once
class Student {
	std::string name, * result;
	int roll, totalCourses;
	Course* obj;
	Lab* lab;
	Theory* theory;
public:
	Student() {
		name = "";
		result = {};
		roll = 0;
		totalCourses = 0;
		obj = new Course[0];
		theory = new Theory[0];
		lab = new Lab[0];
	}
	void details() {

		cout << "\nEnter the student's name " << ":";
		cin.ignore();
		getline(cin, name);
		cout << "\nEnter roll number of the student: ";
		cin >> roll;
		cout << "\nEnter total courses enrolled: ";
		cin >> totalCourses;

		//declaring size of the data member
		result = new std::string[totalCourses];
		obj = new Course[totalCourses];
		lab = new Lab[totalCourses];
		theory = new Theory[totalCourses];

		for (int i = 0; i < totalCourses; i++) {
			std::string cname, cCode;
			int insemLab, endsemLab, insemTheory, endsemTheory, credit;

			cout << "\n\tEnter course name " << i + 1 << ": ";
			cin.ignore();
			getline(cin, cname);
			cout << "\n\tEnter the course code of " << cname << " : ";
			cin >> cCode;
			cout << "\n\tEnter credit of " << cname << " : ";
			cin >> credit;
			cout << "\n\tLAB:\n";
			cout << "\n\t\tEnter insem marks obtained in " << cname << " lab : ";
			cin >> insemLab;
			cout << "\n\t\tEnter endsem marks obtained in " << cname << " lab : ";
			cin >> endsemLab;

			cout << "\n\tTHEORY:\n";
			cout << "\n\t\tEnter insem marks obtained in " << cname << " theory : ";
			cin >> insemTheory;
			cout << "\n\t\tEnter endsem marks obtained in " << cname << " theory : ";
			cin >> endsemTheory;

			//storing the course details
			obj[i] = Course(cname, cCode, credit);
			 //storing the lab details
			lab[i] = Lab(insemLab, endsemLab, cname, cCode, credit);
			//storing the theory details 
			theory[i] = Theory(insemTheory, endsemTheory, cname, cCode, credit);

			//calculating lab and theory results
			lab[i].calcResult();
			theory[i].calcResult();

			if (lab[i].getResult() == "PASS" && theory[i].getResult() == "PASS")
			{
				this->result[i] = "PASS";
			}
			else
				this->result[i] = "FAIL";

		}

	}

	//to display every details of the students and couses taken by them
	void showDetails() {
		cout << "\nRoll:" << roll << "Name:" << name << "\n" << "Courses taken:";
		for (int i = 0; i < totalCourses; i++) {
			cout << "\n\t" << i + 1 << ")";
			obj[i].viewCourseDetails();
			lab[i].viewResult();
			theory[i].viewResult();
			cout << " Course Result:" << this->result[i] << "\n";
		}
	}


	//to show course result
	void showResults() {
		cout << "\nRoll:" << roll << "Name:" << name << "\n" << "Course name" << setw(29) << "Result\n";
		for (int i = 0; i < totalCourses; i++) {
			cout << obj[i].getCourseName() << setw(34) << this->result[i];
			cout << "\n";
		}
		cout << "\n";
	}
	int getRoll() {
		return roll;
	}


	std::string getName() {
		return name;
	}

	int getTotalCourses() {
		return totalCourses;
	}
	std::string* getResult() {
		return result;
	}
	Course* courseInfo() {
		return obj;
	}
	Lab* labInfo() {

		return lab;
	}
	Theory* theoryInfo() {
		return theory;
	}

};

