#include "CountConsonantHash.h"
#include <cstring>

int CountConsonantHash::CalcHash(const char* sir)
{
    int count = 0;
    int lg = strlen(sir);
    for (int i = 0; i < lg; i++)
        if (!strchr("aeiouAEIOU", sir[i]) && (('a' <= sir[i] && sir[i] <= 'z') || ('A' <= sir[i] && sir[i] <= 'Z')))
            count++;
    return count;
}
