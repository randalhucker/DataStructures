#include <cstdlib>
#include <iostream>
#include <exception>
using namespace std;

class EmptyShelfException : public std::exception
{
public:
    char *what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The Shelf Was Empty! You cannot remove a movie from an empty shelf.";
    }
};