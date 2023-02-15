#include <cstdlib>
#include <iostream>
#include <exception>
using namespace std;

class FullShelfException : public std::exception
{
public:
    char *what()
    {
        return "The Shelf Was Full! You cannot add a movie to a full shelf.";
    }
};