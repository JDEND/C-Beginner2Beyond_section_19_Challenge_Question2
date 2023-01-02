// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

float getAvgScore(int& totalGrade, int& totalStudents);
int outputStudents(const string& studentName, const string& studentAnswer, const string& answerKey);
int studentGrade(const string& studentGrade, const string& answerKey);

int main() {
    int totalGrades = 0, NoStudents = 0;
    const string answerDoc = "responses.txt";
    string answerKey, stuName, stuAnswer;

    ifstream Responses;
    Responses.open(answerDoc);
    if (!Responses.is_open()) {
        cerr << "Open file failed: File not found" << endl;
        return 0;
    }

    Responses >> answerKey;

    cout << "Student                     Score" << endl;
    cout << "---------------------------------" << endl;
    while (Responses >> stuName)
    {
        Responses >> stuAnswer;
        totalGrades += outputStudents(stuName, stuAnswer, answerKey);
        NoStudents++;
    }
    cout << "---------------------------------" << endl;
    cout << left << setw(28) << "Average Score: " << getAvgScore(totalGrades, NoStudents) << endl;

    return 0;
}

float getAvgScore(int& totalGrade, int& totalStudents) { return (float)totalGrade / (float)totalStudents; }

int outputStudents(const string &studentName, const string &studentAnswer, const string &answerKey) {
    int temp = 0;
    temp = studentGrade(studentAnswer, answerKey);
    cout << left << setw(28) << studentName << temp << endl;
    return temp;
}

int studentGrade(const string& studentGrade, const string& answerKey) {
    int grade = 0;
    for (size_t i = 0; i < answerKey.length(); i++)
    {
        if (studentGrade[i] == answerKey[i])
            grade++;
    }
    return grade;
}

