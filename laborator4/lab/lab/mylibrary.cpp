#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream) {
    books_count = 0;
    books       = nullptr;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream) {
    this->books_count = books_count;
    this->books       = new int[books_count];
    for (int i = 0; i < books_count; i++) {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max)
    : output_stream(output_stream) {
    this->books_count = books_count;
    this->books       = new int[books_count];
    srand(time(NULL));
    for (int i = 0; i < books_count; i++)
        books[i] = rand() % max + min;
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream) {
    books_count = 1;
    for (int i = 0; i < strlen(books_values); i++)
        if (books_values[i] == ';')
            books_count++;
    books        = new int[books_count];
    char* string = new char[strlen(books_values) + 1];
    strcpy(string, books_values);
    int i   = 0;
    char* p = strtok(string, ";");
    while (p != nullptr) {
        books[i++] = atoi(p);
        p          = strtok(nullptr, ";");
    }
    delete[] string;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream) {
    this->books_count = books_count;
    this->books       = new int[books_count];
    va_list args;
    va_start(args, books_count);
    for (int i = 0; i < books_count; i++)
        books[i] = va_arg(args, int);
    va_end(args);
}

MyLibrary::MyLibrary(MyLibrary const& library) : output_stream(library.output_stream) {
    this->books_count = library.books_count;
    this->books       = new int[books_count];
    for (int i = 0; i < books_count; i++)
        this->books[i] = library.books[i];
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books() const {
    if (books_count == 0)
        output_stream << "Found -1 books\n";
    else {
        output_stream << "Found " << books_count << " books\n";
        for (int i = 0; i < books_count; i++)
            output_stream << books[i] << ' ';
        output_stream << '\n';
    }
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (book_index < books_count)
        books[book_index] = book_id;
}

unsigned MyLibrary::get_books_count() const {
    return books_count;
}

int MyLibrary::get_book_id_by_index(int book_index) const {
    if (book_index < books_count)
        return books[book_index];
    return -1;
}
