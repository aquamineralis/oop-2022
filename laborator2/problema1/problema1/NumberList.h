#pragma once

class NumberList {
    int numbers[10];
    unsigned count;

  public:
    void Init();          // count will be 0
    bool Add(int number); // adds X to the numbers list and increase the data member count.
                          // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print() const;   // will print the current vector
};