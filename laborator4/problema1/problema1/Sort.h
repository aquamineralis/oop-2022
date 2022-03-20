#pragma once

#include <initializer_list>

class Sort {
  private:
    int elements_count;
    int* elements;

  public:
    Sort(int elements_count, int min, int max);
    Sort(std::initializer_list<int> list);
    Sort(int elements_count, int elements[]);
    Sort(int elements_count, ...);
    Sort(const char* string);

    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print() const;
    int GetElementsCount() const;
    int GetElementFromIndex(int index) const;
};
