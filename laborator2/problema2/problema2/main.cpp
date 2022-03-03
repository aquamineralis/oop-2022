#include <iostream>
#include "Student.h"
#include "StudentFunctions.h"

int main() {
    Student student1;
    student1.Init();
    student1.SetName("Ana Popescu");
    student1.SetMathGrade(7.8);
    student1.SetEnglishGrade(8.5);
    student1.SetHistoryGrade(5.0);

    Student student2;
    student2.Init();
    student2.SetName("Maria Popa");
    student2.SetMathGrade(6.4);
    student2.SetEnglishGrade(9.7);
    student2.SetHistoryGrade(5.0);

    std::cout << "Student 1"
              << "\nName: " << student1.GetName() << "\nMath Grade: " << student1.GetMathGrade()
              << "\nEnglish Grade: " << student1.GetEnglishGrade() << "\nHistory Grade: " << student1.GetHistoryGrade()
              << "\nAverage Grade: " << student1.GetAverageGrade() << "\n\n";

    std::cout << "Student 2"
              << "\nName: " << student2.GetName() << "\nMath Grade: " << student2.GetMathGrade()
              << "\nEnglish Grade: " << student2.GetEnglishGrade() << "\nHistory Grade: " << student2.GetHistoryGrade()
              << "\nAverage Grade: " << student2.GetAverageGrade() << "\n\n";

    std::cout << "Comparison of students"
              << "\nNames: " << CompareNames(student1, student2)
              << "\nMath Grades: " << CompareMathGrades(student1, student2)
              << "\nEnglish Grades: " << CompareEnglishGrades(student1, student2)
              << "\nHistory Grades: " << CompareHistoryGrades(student1, student2)
              << "\nAverage Grades: " << CompareAverageGrades(student1, student2) << "\n\n";
    return 0;
}