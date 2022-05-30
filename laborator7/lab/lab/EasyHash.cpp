#include "EasyHash.h"
#include <cstring>

int EasyHash::CalcHash(const char* sir)
{
    int sum = 0;
    int lg = strlen(sir);
    for (int i = 0; i < lg; i++)
        if (('a' <= sir[i] && sir[i] <= 'z') || ('A' <= sir[i] && sir[i] <= 'Z'))
            if (strchr("aeiouAEIOU", sir[i]))
                sum += 10 * sir[i];
            else
                sum += 11 * sir[i];
        else
            sum += 12 * sir[i];
    return sum;
}
