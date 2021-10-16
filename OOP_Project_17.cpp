#include <iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Student.h"
#include"Course.h"
#include"Theory.h"
#include"Lab.h"

void intro()
{
    std::cout << "\n\n\n\t\t WELCOME TO"; cout << "\n\n\t\t STUDENT";
    std::cout << "\n\n\t	AUTO GRADING SYSTEM"; cout << "\n\n\t\t PROJECT";
    std::cout << "\n\n\n\tMADE BY : JUKTA GOYARI \n\t\t& SACHIN DOLEY"; 
    std::cout << "\n\t4th Semester,CSE,DUIET";
    cin.get();
    system("cls"); //to clear the intro screen
}


void read_information() {

    //to read the file ifstream fin;
    ifstream fin;
    // Open an existing file fin.open("STUDENT.csv");
    fin.open("STUDENT.csv");
    string line, word;
    while (fin.good()) {

        //seperating the lines at commas (,) getline (fin, line, ',');
        getline(fin, line, ',');

        //breaking the line in words stringstream s(line);
        stringstream s(line);
        //displaying each word

        while (getline(s, word, ',')) {
            std::cout << left << setw(17) << word; //setw() is used to set width

        }

    }


    std::cout << "\n";
    std::cout << "The data may appear a little distorted due to less space. Check out Student.csv file to see the details clearly\n";

}

void read_result() {

    //to read the file ifstream fin;
    ifstream fin;
    // Open an existing file

    fin.open("Result.csv");

    string line, word;
    while (fin.good()) {

        //seperating the lines at commas (,)

        getline(fin, line, ',');

        //breaking the line in words

        stringstream s(line);

        //displaying each word
        while (getline(s, word, ',')) {
            std::cout << left << setw(20) << word;
        }

    }

}





int main()
{
    Student* s;
    int t, isTrue = 0;
    int* roll;
    intro();
    std::cout << "Enter total students: ";
    cin >> t;
    //string* result;
    s = new Student[t];
    //storing in the csv file writing in the file.if the file is not present,a new one of the given names are created
    ofstream fout1;
    ofstream fout2;
    fout1.open("STUDENT.csv");
    fout2.open("Result.csv");

    //writing the headers of the csv file
    fout1 << "Roll,Name,CourseCode,CourseName,Credit,Lab-Insem-Marks,Lab-Endsem-Marks,Lab-Result,Theory-Insem-Marks,Theory-Endsem-Marks,Theory-Result,Final-Result";
    fout2 << "Roll,Name,Result";

    for (int i = 0; i < t; i++) {
        s[i].details();

        //accessing all the values to store in csv file

        int roll = s[i].getRoll();
        string name = s[i].getName();

        int totalCourse = s[i].getTotalCourses();
        string* result = s[i].getResult();

        Course* course = s[i].courseInfo();
        Lab* lab = s[i].labInfo();

        Theory* theory = s[i].theoryInfo();

        fout1 << "\n" << roll << "," << name << ",";
        fout2 << "\n" << roll << "," << name << ",";

        // to check if a student has passed all the exams

        bool isPass = true;
        for (int j = 0; j < totalCourse; j++) {

            //writing in the csv file
            if (result[j] == "FAIL")

                isPass = false; //if student fails in any one subject then they fail the exam as a whole

            if (j != 0)

                fout1 << "\n,,";

            fout1 << course[j].getCourseCode() << "," << course[j].getCourseName() << "," << course[j].getCredit() << "," << lab[j].getInsemMarks() << "," << lab[j].getEndSemMarks() << "," << lab[j].getResult() << "," << theory[j].getInsemMarks() << "," << theory[j].getEndSemMarks() << "," << theory[i].getResult() << "," << result[j];

        }

        //checking if student is pass or not
        if (isPass)

            fout2 << "PASS";
        else
            fout2 << "FAIL";

    }
    //end of loop
    fout1.close();//close the file student.csv
    fout2.close();//close the file results.csv


    for (int i = 0; i < t; i++)
        s[i].showResults(); //display the result along with the deatils

    //display statement 
    std::cout << "Press 1 to to view the course wise result\nPress 2 to view the overall result of each student.\nPress 3 to view the full information.\n Press 0 to break\n-----";
    cin >> isTrue;

    if (isTrue == 0) {

    }
    if (isTrue == 1)
    {
        for (int i = 0; i < t; i++) {
            s[i].showResults();


        }
    }
    else if (isTrue == 2)
    {
        read_result();

    }
    else if (isTrue == 3)
    {
        read_information();

    }
    else {
        std::cout << "Wrong option ! Try again \n";
    }
    return 0;

}