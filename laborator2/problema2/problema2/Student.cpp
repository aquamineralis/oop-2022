#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>

void Student::Init() {
    name[0]      = '\0';
    MathGrade    = 0.0;
    EnglishGrade = 0.0;
    HistoryGrade = 0.0;
}

void Student::SetName(const char* name) {
    strcpy(this->name, name);
}

void Student::SetMathGrade(float grade) {
    if (grade >= 1.0 && grade <= 10.0)
        MathGrade = grade;
}

void Student::SetEnglishGrade(float grade) {
    if (grade >= 1.0 && grade <= 10.0)
        EnglishGrade = grade;
}

void Student::SetHistoryGrade(float grade) {
    if (grade >= 1.0 && grade <= 10.0)
        HistoryGrade = grade;
}

const char* Student::GetName() const {
    return name;
}

float Student::GetMathGrade() const {
    return MathGrade;
}

float Student::GetEnglishGrade() const {
    return EnglishGrade;
}

float Student::GetHistoryGrade() const {
    return HistoryGrade;
}

float Student::GetAverageGrade() const {
    return (float) (MathGrade + HistoryGrade + EnglishGrade) / 3;
}
