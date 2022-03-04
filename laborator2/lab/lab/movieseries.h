#pragma once

#include "movie.h"

class MovieSeries {
  private:
    Movie movies[16];
    unsigned size;

  public:
    void init();
    void add(const Movie& movie);
    void print() const;
    unsigned get_size() const;
    void set_size(unsigned size);
    const Movie& get_movie_by_index(unsigned index) const;
    void set_movie_by_index(unsigned index, Movie movie);
};
