#define _CRT_SECURE_NO_WARNINGS
#include "HashManager.h"
#include <cstring>
#include <iostream>

Hash*& HashManager::operator[](const char* name)
{
    int lg = strlen(name) + 1;
    hashes[count].name = new char[lg];
    strcpy(hashes[count].name, name);
    count++;
    return hashes[count-1].hash;
}

void HashManager::print_hashes(const char* sir)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << hashes[i].name << ' ' << hashes[i].hash->CalcHash(sir) << '\n';
    }
}
