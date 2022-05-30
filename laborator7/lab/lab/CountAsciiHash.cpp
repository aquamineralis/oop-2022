#include "CountAsciiHash.h"
#include <cstring>

int CountAsciiHash::CalcHash(const char* sir)
{
    int sum = 0;
    int lg = strlen(sir);
    for (int i = 0; i < lg; i++)
        sum += (int)sir[i];
    return sum;
}
