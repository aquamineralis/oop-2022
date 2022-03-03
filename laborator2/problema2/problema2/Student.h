#pragma once

class Student {
  private:
    char name[100];
    float MathGrade;
    float EnglishGrade;
    float HistoryGrade;

  public:
    void Init();

    void SetName(const char* name);
    void SetMathGrade(float grade);
    void SetEnglishGrade(float grade);
    void SetHistoryGrade(float grade);

    const char* GetName() const;
    float GetMathGrade() const;
    float GetEnglishGrade() const;
    float GetHistoryGrade() const;
    float GetAverageGrade() const;
};