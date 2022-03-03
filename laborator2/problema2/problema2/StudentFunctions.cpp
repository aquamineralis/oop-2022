#include "StudentFunctions.h"
#include <cstring>

int CompareNames(const Student& student1, const Student& student2) {
    if (strcmp(student1.GetName(), student2.GetName()) > 0)
        return 1;
    if (strcmp(student1.GetName(), student2.GetName()) < 0)
        return -1;
    return 0;
}

int CompareMathGrades(const Student& student1, const Student& student2) {
    if (student1.GetMathGrade() > student2.GetMathGrade())
        return 1;
    if (student1.GetMathGrade() < student2.GetMathGrade())
        return -1;
    return 0;
}

int CompareEnglishGrades(const Student& student1, const Student& student2) {
    if (student1.GetEnglishGrade() > student2.GetEnglishGrade())
        return 1;
    if (student1.GetEnglishGrade() < student2.GetEnglishGrade())
        return -1;
    return 0;
}

int CompareHistoryGrades(const Student& student1, const Student& student2) {
    if (student1.GetHistoryGrade() > student2.GetHistoryGrade())
        return 1;
    if (student1.GetHistoryGrade() < student2.GetHistoryGrade())
        return -1;
    return 0;
}

int CompareAverageGrades(const Student& student1, const Student& student2) {
    if (student1.GetAverageGrade() > student2.GetAverageGrade())
        return 1;
    if (student1.GetAverageGrade() < student2.GetAverageGrade())
        return -1;
    return 0;
}
