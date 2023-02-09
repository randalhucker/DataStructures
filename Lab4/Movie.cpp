
#include "Movie.h"
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Movie::Movie()
{
    Title = "";
    Description = "";
    Credits = "";
}

// Fill constructor for imperial units
Movie::Movie(string T, string D, string C)
{
    Title = T;
    Description = D;
    Credits = C;
}

// Destructor
Movie::~Movie()
{
}

// Getter

string Movie::getCredits()
{
    return (Credits);
}

// Setter

void Movie::setCredits(string C)
{
    Description = C;
}

// Play
void Movie::Play() // uses cout to disply the values of class attributes
{
    cout << fixed << setprecision(2);
    cout << "Now Playing: " + getTitle();
    cout << endl;
    cout << "Credits: " << getCredits();
    cout << endl;
}
