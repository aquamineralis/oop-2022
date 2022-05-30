#include "CountVowelsHash.h"
#include <cstring>

int CountVowelsHash::CalcHash(const char* sir)
{
    int count = 0;
    int lg = strlen(sir);
    for(int i = 0; i < lg; i++)
        if(strchr("aeiouAEIOU", sir[i]))
            count++;
    return count;
}
