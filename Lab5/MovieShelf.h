#pragma once
#include <string>
#include <iostream>
#include "Movie.h"
using namespace std;

const int NUM_MOVIES = 10;

class MovieShelf
{
private:
    int MovieCount;
    Movie* Movies[NUM_MOVIES];

public:
    MovieShelf();                   // Default Constructor
    ~MovieShelf();                  // Destructor

    // Getters
    int getMovieCount();
    Movie* getMovie(int index); // maybe becomes a print function

    // Setters
    void setMovie(Movie* m, int index);
   
    // Additional Functions
    void addMovie(Movie* M);
    Movie* removeMovie();
};