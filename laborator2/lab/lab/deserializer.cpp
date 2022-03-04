#include "deserializer.h"
#include <iostream>

bool Deserializer::read_buffer(void* buffer, unsigned size) {
    return fread(buffer, 1, size, file) == size;
}

bool Deserializer::read_movie(Movie& movie) {
    unsigned year        = 0;
    double score         = 0.0;
    unsigned length      = 0;
    char* name           = nullptr;
    unsigned name_length = 0;

    if (!read_buffer(&year, sizeof(year)))
        return false;
    if (!read_buffer(&score, sizeof(score)))
        return false;
    if (!read_buffer(&length, sizeof(length)))
        return false;
    if (!read_buffer(&name_length, sizeof(name_length)))
        return false;
    name = (char*) calloc(name_length, sizeof(char));
    if (name == nullptr)
        return false;
    if (!read_buffer(name, sizeof(char) * name_length))
        return false;

    movie.set_year(year);
    movie.set_score(score);
    movie.set_length(length);
    movie.set_name(name);

    free(name);
    return true;
}

bool Deserializer::init(const char* file_name) {
    file = fopen(file_name, "rb");
    return file != nullptr;
}

void Deserializer::close() {
    if (file)
        fclose(file);
}

bool Deserializer::read(MovieSeries& series) {
    unsigned series_size = 0;
    if (!read_buffer(&series_size, sizeof(series_size)))
        return false;
    series.set_size(series_size);
    for (unsigned i = 0; i < series_size; i++) {
        {
            Movie movie;
            if (!read_movie(movie))
                return false;
            series.set_movie_by_index(i, movie);
        }
    }
    return true;
}
