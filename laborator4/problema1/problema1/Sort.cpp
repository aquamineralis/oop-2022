#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>

Sort::Sort(int elements_count, int min, int max) {
    this->elements_count = elements_count;
    this->elements       = new int[elements_count];
    srand(time(NULL));
    for (int i = 0; i < elements_count; i++)
        elements[i] = rand() % max + min;
}

Sort::Sort(std::initializer_list<int> list) {
    elements_count = list.size();
    elements       = new int[list.size()];
    int i          = 0;
    for (auto iterator = list.begin(); iterator != list.end(); iterator++)
        elements[i++] = *iterator;
}

Sort::Sort(int elements_count, int elements[]) {
    this->elements_count = elements_count;
    this->elements       = new int[elements_count];
    for (int i = 0; i < elements_count; i++)
        this->elements[i] = elements[i];
}

Sort::Sort(int elements_count, ...) {
    this->elements_count = elements_count;
    this->elements       = new int[elements_count];
    va_list args;
    va_start(args, elements_count);
    for (int i = 0; i < elements_count; i++)
        elements[i] = va_arg(args, int);
    va_end(args);
}

Sort::Sort(const char* string) {
    elements_count = 1;
    for (int i = 0; i < strlen(string); i++)
        if (string[i] == ',')
            elements_count++;
    elements = new int[elements_count];
    char* s  = new char[strlen(string) + 1];
    strcpy(s, string);
    int i   = 0;
    char* p = strtok(s, ",");
    while (p != nullptr) {
        elements[i++] = atoi(p);
        p             = strtok(nullptr, ",");
    }
    delete[] s;
}

Sort::~Sort() {
    delete[] elements;
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < elements_count; i++) {
        int j    = i - 1;
        int temp = elements[i];
        while (j >= 0 && ((ascendent && elements[j] > temp) || (!ascendent && elements[j] < temp))) {
            elements[j + 1] = elements[j];
            j--;
        }
        if (elements[j + 1] != temp)
            elements[j + 1] = temp;
    }
}

void Sort::QuickSort(bool ascendent) {
    std::sort(elements, elements + elements_count, [ascendent](int a, int b) {
        if (ascendent)
            return a < b;
        return a > b;
    });
}

void Sort::BubbleSort(bool ascendent) {
    int last    = elements_count - 1;
    bool sorted = false;
    do {
        sorted = true;
        for (int i = 0; i < last; i++)
            if ((ascendent && elements[i] > elements[i + 1]) || (!ascendent && elements[i] < elements[i + 1])) {
                std::swap(elements[i], elements[i + 1]);
                sorted = false;
            }
        last--;
    } while (sorted == false);
}

void Sort::Print() const {
    for (int i = 0; i < elements_count; i++)
        std::cout << elements[i] << ' ';
    std::cout << '\n';
}

int Sort::GetElementsCount() const {
    return elements_count;
}

int Sort::GetElementFromIndex(int index) const {
    if (index < elements_count)
        return elements[index];
    return -1;
}
