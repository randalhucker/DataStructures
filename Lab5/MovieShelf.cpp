#include "MovieShelf.h"
#include <array>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
MovieShelf::MovieShelf()
{
    MovieCount = 0;
}

// Destructor
MovieShelf::~MovieShelf()
{
}

// Getters
int MovieShelf::getMovieCount()
{
    return MovieCount;
}

Movie *MovieShelf::getMovie(int index)
{
    return Movies[index];
}

// Setters
void MovieShelf::setMovie(Movie *m, int index)
{
    Movies[index] = m;
}

// Additional Functions
void MovieShelf::addMovie(Movie *M)
{
    Movies[MovieCount] = M; // 
    throw FullShelfException();
    MovieCount++;
}

Movie *MovieShelf::removeMovie()
{
    MovieCount--;
    Movie *returnMovie = Movies[MovieCount];
    throw EmptyShelfException();
    return returnMovie;
}
