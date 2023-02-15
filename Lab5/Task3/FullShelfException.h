#include <cstdlib>
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class FullShelfException : public std::exception
{
public:
    string what()
    {
        return ("The Shelf Was Full! You cannot add a movie to a full shelf.");
    }
};