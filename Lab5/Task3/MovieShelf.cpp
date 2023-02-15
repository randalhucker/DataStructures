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
    if (MovieCount >= NUM_MOVIES)
    {
        throw FullShelfException();
    }
    Movies[MovieCount] = M; // If this fails, full shelf exception is thrown
    MovieCount++;
}

Movie *MovieShelf::removeMovie()
{
    if (MovieCount <= 0)
    {
        throw EmptyShelfException();
    }
    MovieCount--;
    Movie *returnMovie = Movies[MovieCount]; // If this fails, empty shelf exception is thrown
    return returnMovie;
}
