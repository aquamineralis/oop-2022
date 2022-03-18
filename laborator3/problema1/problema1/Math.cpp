#include "Math.h"
#include <cstdarg>
#include <cstdlib>
#include <cstring>

int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int x, int y, int z) {
    return x + y + z;
}

double Math::Add(double x, double y) {
    return x + y;
}

double Math::Add(double x, double y, double z) {
    return x + y + z;
}

int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

double Math::Mul(double x, double y) {
    return x * y;
}

double Math::Mul(double x, double y, double z) {
    return x * y * z;
}

int Math::Add(int count, ...) {
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
        result += va_arg(args, int);
    va_end(args);
    return result;
}

char* Math::Add(const char* x, const char* y) {
    if (x == nullptr || y == nullptr)
        return nullptr;

    unsigned size_x   = strlen(x);
    unsigned size_y   = strlen(y);
    unsigned max_size = size_x + size_y + 1;
    char* result      = (char*) malloc(max_size);
    if (result == nullptr)
        return nullptr;
    memcpy(result, x, size_x);
    memcpy(result + size_x, y, size_y + 1);
    return result;
}
