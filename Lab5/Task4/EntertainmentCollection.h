#include <array>
#include <string>
#include <iostream>
#include <iomanip>
#include "EmptyShelfException.h"
#include "FullShelfException.h"

using namespace std;

const int NUM_T = 10;

template <class T>
class EntertainmentCollection
{
private:
    int Count;
    T *Items[NUM_T];
    // Default constructor

public:
    EntertainmentCollection()
    {
        Count = 0;
    }

    // Destructor

    ~EntertainmentCollection()
    {
    }

    // Getters

    int getCount()
    {
        return Count;
    }

    T *getItem(int index)
    {
        return Items[index];
    }

    // Setters
    void setItem(T *item, int index)
    {
        Items[index] = item;
    }

    // Additional Functions
    void addItem(T *item)
    {
        if (Count >= NUM_T)
        {
            throw FullShelfException();
        }
        Items[Count] = item; // If this fails, full shelf exception is thrown
        Count++;
    }

    T *removeItem()
    {
        if (Count <= 0)
        {
            throw EmptyShelfException();
        }
        Count--;
        T *returnT = Items[Count]; // If this fails, empty shelf exception is thrown
        return returnT;
    }
};