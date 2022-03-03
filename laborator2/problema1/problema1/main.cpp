#include "NumberList.h"

int main() {
    NumberList numberList;
    numberList.Init();

    numberList.Add(-96);
    numberList.Add(38);
    numberList.Add(65);
    numberList.Add(-74);
    numberList.Add(28);

    numberList.Print();
    numberList.Sort();
    numberList.Print();
    return 0;
}