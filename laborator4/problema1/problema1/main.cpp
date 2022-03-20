#include <iostream>
#include "Sort.h"

int main() {
    Sort list1(6, 4, 20);
    list1.Print();
    list1.BubbleSort(true);
    list1.Print();
    std::cout << '\n';

    Sort list2 = { 2, 7, -3, 8, 5, -1, 2, 11 };
    list2.Print();
    list2.InsertSort();
    list2.Print();
    std::cout << '\n';

    int vector3[] = { 7, -9, 4, -2, 1, 0, 7, 15 };
    Sort list3(8, vector3);
    list3.Print();
    list3.QuickSort(false);
    list3.Print();
    std::cout << '\n';

    Sort list4(8, 3, -5, 2, 3, 8, 10, -2, 6);
    list4.Print();
    list4.BubbleSort();
    list4.Print();
    std::cout << '\n';

    char string5[] = "5,2,-3,0,1,-3,13,5";
    Sort list5(string5);
    list5.Print();
    list5.InsertSort(true);
    list5.Print();
    std::cout << '\n';
    return 0;
}