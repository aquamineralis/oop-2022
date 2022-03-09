#include "allocator.h"
#include <cstdlib>
#include <cstring>

void* Allocator::alloc_raw(unsigned size) {
    char* p = buffer + offset;
    offset += size;
    return p;
}

Allocator::Allocator(unsigned max_size) {
    buffer         = (char*) malloc(max_size);
    offset         = 0;
    this->max_size = max_size;
}

Allocator::~Allocator() {
    free(buffer);
}

#define make_function(type)                                                                                            \
    type* Allocator::alloc(type x) {                                                                                   \
        type* p = (type*) alloc_raw(sizeof(x));                                                                        \
        *p      = x;                                                                                                   \
        return p;                                                                                                      \
    }

make_function(unsigned);
make_function(int);
make_function(float);
make_function(double);
make_function(char);

char* Allocator::alloc(const char* string) {
    int length = strlen(string) + 1;
    char* p    = (char*) alloc_raw(length);
    // strcpy(p, string);
    memcpy(p, string, length);
    return p;
}

// unsigned* Allocator::alloc(unsigned x) {
//     unsigned* p = (unsigned*) alloc_raw(sizeof(x));
//     *p      = x;
//     return p;
// }
//
// int* Allocator::alloc(int x) {
//     int* p = (int*) alloc_raw(sizeof(x));
//     *p     = x;
//     return p;
// }
//
// float* Allocator::alloc(float x) {
//     float* p = (float*) alloc_raw(sizeof(x));
//     *p       = x;
//     return p;
// }
//
// double* Allocator::alloc(double x) {
//     double* p = (double*) alloc_raw(sizeof(x));
//     *p        = x;
//     return p;
// }
//
// char* Allocator::alloc(char x) {
//     char* p = (char*) alloc_raw(sizeof(x));
//     *p      = x;
//     return p;
// }
//
// char* Allocator::alloc(const char* string) {
//     int length = strlen(string) + 1;
//     char* p    = (char*) alloc_raw(length);
//     // strcpy(p, string);
//     memcpy(p, string, length);
//     return p;
// }
