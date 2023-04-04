#include <exception>
#include <string>

using namespace std;

class EmptyTableException : public std::exception
{
public:
    string what() 
    {
        return "The table is empty. Items cannot be found or removed from an empty table";
    }
};

class ItemNotFoundException : public std::exception
{
public:
    string what() 
    {
        return "The item you are looking for could not be found in the table";
    }
};